#include "functions.h"

void getFiles (string dir, vector<string> &files)
{	
	DIR *dp=opendir(dir.c_str());					
	if(dp  == NULL) 
	{
 		cout << "Error opening " << dir << endl;
		return;
    }

	struct dirent *dirp;	  
 	while ((dirp = readdir(dp)) != NULL) 
	{
    	if(string(dirp->d_name).find("input")!=string::npos)
   		{   				
   			string path=dir + string (dirp->d_name);
			files.push_back(path);
   		}
	}
	closedir(dp);
}

void parseFile(string path, vector<int> &v)
{
	ifstream myfile(path.c_str());
	string line;

  	if (myfile.is_open())
  	{
		while ( myfile.good() )
  		{
  	   		getline (myfile,line);	// READ FILE IN LINE
			stringstream os(line);  // PARSE LINE 
  			string temp;                	 
  			while (os >> temp)
			    v.push_back( atoi(temp.c_str()));
  		}			
	}
	myfile.close();

}
		
void recordTime(const vector<int> &v, ofstream &data)
{
	for (int i=3;i<=4;i++)
	{  
		clock_t k = clock(); 
   		clock_t start;
   		do start = clock();
    	while (start == k);
    	int  j=maxSubSum(v,i);
    	clock_t end=clock();
    
    	//cout<<"Result is :"
   		//cout<<j<<endl
		data<<scientific<<v.size()<<"	"					//input size
		<<i<<"	"						//function_#
		<<j<<"	"						//result
		<<(double) ((double)1000)*(end - start)/CLOCKS_PER_SEC 	//runnng time
		<<endl;				
	}	
}
  		

int maxSubSum(const vector<int> &a, int i)
{
	
	if(i==1)
		return maxSubSum1(a);
	if(i==2)
		return maxSubSum2(a);
	if(i==3)
		return maxSubSum3(a);
	if(i==4)
		return maxSubSum4(a);
}


int maxSubSum1(const vector<int> &a)
{
	int maxSum=0;
	for (int i=0; i<a.size();i++)
	{
		for (int j=i; j<a.size();j++ )
		{
			int thisSum=0;
			for (int k=i;k<=j;k++)
				thisSum+=a[k];
			if(thisSum>maxSum)
				maxSum=thisSum;
		}
	}
	return maxSum;
}

int maxSubSum2(const vector<int> & a)
{
	
	int maxSum=0;

	for (int i=0; i< a.size();i++)
	{
		int thisSum=0;
		for (int j=i;j<a.size();j++)
		{	
			thisSum+=a[j];
			if(thisSum>maxSum)
				maxSum=thisSum;
		}
	}
	return maxSum;
}



int maxSumRec(const vector<int> &a, int left, int right)
{
	if(left==right)
		if(a[left]>0)
			return a[left];
		else
			return 0;

	int center = (left +right)/2;
	int maxLeftSum= maxSumRec(a, left, center);
	int maxRightSum= maxSumRec(a, center+1, right);

	int maxLeftBorderSum=0;
	int leftBorderSum=0;
	int maxRightBorderSum=0;
	int rightBorderSum=0;

	//maxSum ending at center
	for(int i=center; i>=left; i--)
	{
		leftBorderSum+=a[i];
		if(leftBorderSum>maxLeftBorderSum)
			maxLeftBorderSum=leftBorderSum;
	}


	//maxSum starting at center+1
	for(int i=center+1; i<=right; i++)
	{
		rightBorderSum+=a[i];
		if(rightBorderSum>maxRightBorderSum)
			maxRightBorderSum=rightBorderSum;
	}
	return max3(maxLeftSum, maxRightSum, maxLeftBorderSum+maxRightBorderSum);
}

int max3(int a, int b, int c)
{
	return max( max(a, b),c);
}

int maxSubSum3(const vector<int> &a)
{
	return maxSumRec(a, 0, a.size()-1);
}

int maxSubSum4(const vector<int> &a)
{
	int maxSum=0;
	int thisSum=0;
	for (int j=0; j<a.size();j++)
	{
		thisSum+=a[j];
		if(thisSum>maxSum)
			maxSum=thisSum;
		else
			if(thisSum<0)
				thisSum=0;
	}
	return maxSum;
}
