/* Question 3 is based on finding the Maximum-Weight independent set of a tree
   
   By Parul Bansal
   Implementation is done using Dynamic Programming Strategy

   Example-
   --Input--
   15 14
   Enter Weights of Vertices
   6 4 8 8 5 6 2 8 3 9 7 5 4 6 2
   Enter Edges
   0 1
   0 2
   0 3
   1 4 
   1 5
   2 6
   2 7
   2 8
   3 9 
   3 10
   7 11
   7 12
   7 13
   9 14


   --Output--
   Maximum Weight of Independent-Set
   53
   Nodes in Maximum-Weight Independent Set
   0 4 5 6 8 9 10 11 12 13 

*/


#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)


int maxWeight(int root, vector<int>& Min, vector<int>& Mout, vector<int>& arr, int wt[], int n){
	if(Min[root] != -1)
		return max(Min[root], Mout[root]);
	int out=0,in=0;
	FOR(i,0,n){
		if(arr[i] == root){
			out += maxWeight(i,Min,Mout,arr,wt,n);
			in +=  Mout[i];
		}
	}
	Mout[root] = out;
	Min[root] = in + wt[root];
	return max(Min[root], Mout[root]);
}

int main(){
	int n,m,u,v;
	cin>>n>>m;
	int wt[n];
	vector<int> arr(n,-1);
	vector<int> cnt(n,0);
	vector<int> Mout(n,-1);
	vector<int> Min(n,-1); 
	vector<int> set;
	vector<int> vis(n,false);

	cout<<"Enter Weights of Vertices\n";
	FOR(i,0,n) cin>>wt[i];
	cout<<"Enter Edges\n";
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

	int root;
	FOR(i,0,n){
		if(arr[i] == -1)
			root = i;
	}

	FOR(i,0,n){
		if(cnt[i] == 0){
			Min[i] = wt[i];
			Mout[i] = 0;
		}
	}

	//cout<<root<<"\n";
	cout<<"Maximum Weight of Independent-Set\n";
	cout<<maxWeight(root,Min,Mout,arr,wt,n)<<endl;

	/*FOR(i,0,n)
		cout<<Min[i]<<" "<<Mout[i]<<endl;*/

	if(Min[root] > Mout[root]){
		set.push_back(root);
		vis[root]=true;
	}

	queue<int> qe;
	qe.push(root);

	while(!qe.empty()){
		u = qe.front();
		qe.pop();

		if(u!=root && (vis[arr[u]] == false) && (Min[u] > Mout[u])){
			set.push_back(u);
			vis[u]=true;
		}
		FOR(i,0,n){
			if(arr[i] == u)
				qe.push(i);
		}
	}

	cout<<"Nodes in Maximum-Weight Independent Set\n";
	u = set.size();
	FOR(i,0,u)
		cout<<set[i]<<" ";
	cout<<endl;

	return 0;
}






