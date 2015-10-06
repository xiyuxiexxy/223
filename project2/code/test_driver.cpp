#include "functions.h"
#include "functions.cpp"

using namespace std;

int main()
{

	ofstream data("data2.csv");								
	data<<"input_size"<<"	"<<"maxSubSum_function"<<"	"<<"result"<<"	"<<"time/microsec"<<endl;
		
	data.precision(12);
	string dir = "E:/cygwin/home/Xiyu/cpts223_project2/inputs/";	
	vector<string> files;
	
	getFiles(dir, files);
	
	for (int i=0; i<files.size();i++)
	{
		vector<int> v;
		parseFile(files[i],v);
		
		cout<<v.size()<<endl;
		//cout<<"input sequence is :"
		//for(int j=0; j<v.size();j++)
		//	cout<<v[j]<<"	";
		//cout<<endl;
		
		recordTime(v, data);
		
	}
			
	data.close();
    return 0;
}



