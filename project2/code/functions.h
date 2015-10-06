#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <dirent.h>		
#include <sstream>

#include <iostream>
#include <fstream>

#include <ctime>
#include <math.h>

#include <vector>
#include <string> 

#include <algorithm>

using namespace std;

//get input filenames( which begin with input_...)
//under folder dir
void getFiles (string dir, vector<string> &files);

//parse numbers of the input file into vector v
void parseFile(string path, vector<int> &v);

//record 4 maxSubSum function running time 
//of input vector v;
//and output result in file data
void recordTime(const vector<int> &v, ofstream &data);


//running individual maxSubSum functions in respect of i
int maxSubSum(const vector<int> &a, int i);

int maxSubSum1(const vector<int> &a);

int maxSubSum2(const vector<int> &a);

int maxSubSum3(const vector<int> &a);
int maxSumRec(const vector<int> &a, int left, int right);
int max3(int a, int b, int c);

int maxSubSum4(const vector<int> &a);

#endif