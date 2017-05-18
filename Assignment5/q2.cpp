/*  Question 2 is based on finding Maximum-Size independent set in forest

	By Parul Bansal
	Implementation is done using Greedy Strategy

	Example-
	--Input--
	15 13
    0 1
    0 2
    0 3
    3 4
    3 5
    4 6
    4 7
    5 8 
    5 9
    10 11
    10 12
    11 13
    11 14

    --Ouput--
    Maximum-Size Independent Set
	1 2 6 7 8 9 3 12 13 14 

*/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)


int main(){
	int n,m,u,v;
	cin>>n>>m;
	vector<int> arr(n,-1);
	vector<int> cnt(n,0); 
	vector<bool> vis(n,false);
	FOR(i,0,m){
		cin>>u>>v;
		arr[v]=u;
	}
	FOR(i,0,n){
		FOR(j,0,n){
			if(arr[j]==i)
				cnt[i]++;
		}
	}

	vector<int> set;
	bool temp=true;
	while(temp){
		temp = false;
		FOR(i,0,n){
			if(cnt[i]==0){
				cnt[i]=-1;
				if(arr[i]!=-1)
					cnt[arr[i]]--;
				if(!vis[i]){
					set.push_back(i);
					vis[i]=true;
					if(arr[i]!=-1)
						vis[arr[i]]=true;
				}
				
				temp = true;
				break;
			}
		}
	}

	u = set.size();
	cout<<"Maximum-Size Independent Set\n";
	FOR(i,0,u)
		cout<<set[i]<<" ";
	cout<<endl;
	return 0;
}