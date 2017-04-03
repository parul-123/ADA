/* Question 1(Part 2) is based on Weighted Interval Scheduling
   By Parul Bansal (B14116)
   Here we implement mComputeOpt recursive function whose complexity is O(n) using Memoization. 
   
    Example -
   --Input--
    4
	3 7 3
	5 8 2
	8 15 4      
	9 17 1

   --Output--
	The optimal profit is 7  
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)

bool cmpfunc(pair<pair< int, int>, int > p1, pair<pair<int, int>, int > p2){
	return (p1.first.second < p2.first.second);
}

int max(int a, int b) {
	if(a>b) return a;
	return b;
}

int mComputeOpt(int index, vector<pair<pair<int,int>,int> >& ve, int p[], int m[]){
	if(index==-1)
		return 0;
	else if(m[index]!=-1)
		return m[index];
	else m[index] = max(ve[index].second+mComputeOpt(p[index],ve,p,m), mComputeOpt(index-1,ve,p,m));
	return m[index];
}

int main(){
	vector<pair< pair<int, int>, int> > ve;
	int n,st,fi,val;
	cin>>n;
	int p[n],m[n];
	FOR(i,0,n){
		cin>>st>>fi>>val;
		ve.push_back(make_pair(make_pair(st,fi), val));
		m[i]=-1;
	} 
	
	sort(ve.begin(),ve.end());
	p[0]=-1;
	FOR(i,1,n){
		val=-1;
		for(int j=i-1;j>=0;j--){
			if(ve[i].first.first >= ve[j].first.second){
				p[i]=j;
				val=0;
				break;
			}
		}
		if(val==-1)
			p[i]=-1;
	}
	
	cout<<"The optimal profit is "<<mComputeOpt(n-1,ve,p,m);
	return 0;
}
