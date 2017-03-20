/* Question 1 is based on stable matching  
   By Parul Bansal (B14116)
   Input is taking from a1.in input file
   
   Example -
   --Input--
   5
   ---Men Preferences---
   0 1 4 2 3
   0 2 3 1 4
   3 1 4 0 2
   4 3 2 1 0
   2 3 0 1 4
   ---Women Preferences---
   0 1 2 4 3
   2 1 4 3 0
   3 4 0 2 1
   4 2 3 0 1
   0 3 4 2 1
   
   --Output--
   Wife 0 - Husband 0
   Wife 1 - Husband 1
   Wife 2 - Husband 4
   Wife 3 - Husband 2
   Wife 4 - Husband 3 
*/

#include<cstdio>
#include<iostream>
#include<queue>
#include<fstream>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FREE -1
using namespace std;


int main(){		
	ifstream myfile("a1.in");		
	int n;
	myfile>>n;
	int manPref[n][n], womPref[n][n];
	
	FOR(i,0,n){
		FOR(j,0,n)
			myfile>>manPref[i][j];
		}
		
	FOR(i,0,n){
		FOR(j,0,n)
			myfile>>womPref[i][j];
		}
	
	priority_queue<int, std::vector<int>, std::greater<int> > pq;
	int status[n];
	FOR(i,0,n) status[i]= FREE;
	FOR(i,0,n) pq.push(i);
	
	// While there are free men
	while(!pq.empty()){
		
		int m = pq.top();
		pq.pop();
		
		FOR(j,0,n){
			// If woman is not engaged
			if(status[manPref[m][j]] == FREE){
				status[manPref[m][j]] = m;
				break;
			}
			else {
				//CurrentRank is of Current Husband and NewRank is of New Husband
				int CurrentRank, NewRank;
				FOR(k,0,n) { 
				if(status[manPref[m][j]] == womPref[manPref[m][j]][k]) 
					CurrentRank = k;
				if(m == womPref[manPref[m][j]][k])
					NewRank = k;
				}
				
				// If w prefers m over her current engagement m1,
                // then break the engagement between w and m1 and
                // engage m with w. 
				if (CurrentRank > NewRank) {
					pq.push(status[manPref[m][j]]);
					status[manPref[m][j]] = m;
					break;
				}
			}
		}
	}
	
	FOR(i,0,n)
		cout<<"Wife "<<i<<" - Husband "<<status[i]<<endl;
		
	return 0;
}
		
	
