/* Question 4 is based on minimizing the average completion time
   By Parul Bansal (B14116)
   Input is taking from q4.in input file
   Implementation is done using Greedy Strategy
   
   Example -
   --Input--
   2
   1 3
   2 5

   --Output--
   Minimum Average Completion Time
   5.5
   Tasks Schedule
   1 3
   2 8
   
*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FREE -1
using namespace std;

bool cmpfunc(pair< int, int> p1, pair<int, int> p2){
	return (p1.second < p2.second);
}


int main(){
	ifstream myfile("q4.in");
	int n,a,b;
	myfile>>n;
	vector<pair< int, int> > ve;
	FOR(i,0,n){
		myfile>>a>>b;
		ve.push_back(make_pair(a,b));
	}
	
	sort(ve.begin(), ve.end(), cmpfunc);
	
	FOR(i,1,n)
		ve[i].second += ve[i-1].second;
		 
	cout<<"Minimum Average Completion Time"<<endl;
	double avg=0;
	FOR(i,0,n)
		avg += ve[i].second;
	
	avg/=n;
	
	cout<<avg<<endl;
	
	cout<<"Tasks Schedule\n";
	FOR(i,0,n)
		cout<<ve[i].first<<" "<<ve[i].second<<endl;
		
	return 0;
}
	
