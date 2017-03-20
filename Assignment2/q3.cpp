/* Question 3 is based on to find an acyclic subset of E of maximum total weight
   in an undirected graph G(V,E)
   By Parul Bansal (B14116)
   Input is taking from q3.in input file
   Indirectly we have to find Maximum Spanning Tree of G.
   Implementation is done using modified Prim Algorithm
   
   Example -
   --Input--
   3 3
   0 1 2
   1 2 3
   0 2 4

   --Output--
   2-1:3
   0-2:4

   Maximum Weight of Acyclic Subset of Given Graph: 7

*/


#include<cstdio>
#include<iostream>
#include<queue>
#include<fstream>
#include<list>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FREE -1
using namespace std;

int main(){
	int v,e,a,b,w;
	ifstream myfile("q3.in");
	myfile>>v>>e;
	
	list< pair<int, int> > adj[v];
	
	FOR(i,0,e){
		myfile>>a>>b>>w;
		adj[a].push_back(make_pair(b,w));
		adj[b].push_back(make_pair(a,w));
	}
	
	priority_queue<pair<int, int> > pq;
	
	int src=0;
	
	vector<int> key(v, -1);
	vector<int> par(v, -1);
	
	vector<bool> vis(v, false);
	
	pq.push(make_pair(src, 0));
	key[src] = 0;
	
	while(!pq.empty()){
	
		int u = pq.top().first;
		pq.pop();
		vis[u] = true;
		
		list<pair<int, int> >::iterator i;
		for(i=adj[u].begin(); i!=adj[u].end(); i++){
			
			int node = (*i).first;
			int weight = (*i).second;
			
			if(!vis[node] && key[node] < weight){
				key[node] = weight;
				pq.push(make_pair(node,key[node]));
				par[node] = u;
			}
		}
	}
	
	int sum=0;
	FOR(i,1,v) {
		cout<<par[i]<<"-"<<i<<":"<<key[i]<<endl;
		sum += key[i];
	}
	
	cout<<endl<<"Maximum Weight of Acyclic Subset of Given Graph: "<< sum<<endl;
	return 0;
}
		
	
