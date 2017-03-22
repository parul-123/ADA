/* Question 5 is based on scheduling a set of activities using minimum number of classes
   By Parul Bansal (B14116)
   Input is taking from q5.in input file
   Implementation is done using Greedy Strategy
   
   Example -
   --Input--
   3
   1 2
   2 3
   1 3
   --Output--
   Minimum number of Classes for scheduling the activities are : 2

   Activities and Classes Details 
   Activities   |   Classes   
     1          |     1     
     2          |     1     
     3          |     2     

   
*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<queue>
#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int main() {
	int n;
	ifstream myfile("q5.in");
	myfile>>n;
	vector<pair<pair<int,bool>, int> > ve;
	vector<int> resources(n);
	FOR(i,0,n) {
		int start,end;
		myfile >> start >> end;
		ve.push_back(make_pair(make_pair(start,true),i));
		ve.push_back(make_pair(make_pair(end,false),i));
	}
	sort(ve.begin(),ve.end());
	
		
	int room = 0;
	queue<int> qe;
	for(vector<pair<pair<int,bool>,int> >::iterator iter = ve.begin();iter != ve.end(); iter++) {
		pair<pair<int, bool>,int> current = *iter;
		if(current.first.second) {
			if(qe.empty()) 
				qe.push(++room);
			resources[current.second] = (qe.front());
			qe.pop();
		}
		else {
			qe.push(resources[current.second]);
		}
	}
	
	cout<<"Minimum number of Classes for scheduling the activities are : "<<room<<endl<<endl;
	cout<<"Activities and Classes Details \n";
	cout<<"   Activities   |" << "   Classes   "<<endl; 
	
	FOR(i,0,n)
	 cout << "     "<<i+1 << "          |     "<< resources[i] << "     \n"; 
	 
	return 0;
}
