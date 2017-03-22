/* Question 6 is based on finding Minimum Spanning Tree of Graph G(V,E) in two cases
   1) Original Graph G
   2) Modified Graph G' by replacing each edge cost c by its square c^2
   and check whether they are same or not.
   
   By Parul Bansal (B14116)
   Input is taking from q6.in input file
   Implementation is done using Greedy Strategy (PRIM'S ALGORITHM))
   
   Example -
   --Input--
   6 7
   0 1 5
   1 2 3
   2 3 1
   3 4 13
   4 5 3
   4 1 17
   5 0 2
   --Output--
   ----------------Original Graph----------------- 
   0-1:5
   1-2:3
   2-3:1
   3-4:13
   0-5:2

  Minimum Weight of Acyclic Subset of Given Graph: 24

  -------------------Modified Graph---------------------
  0-1:25
  1-2:9
  2-3:1
  3-4:169
  0-5:4

  Minimum Weight of Acyclic Subset of Given Graph: 208

*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<fstream>
#include<list>
#include <climits>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FREE -1
#define INF INT_MAX


int main(){
	int v,e,a,b,w;
	ifstream myfile("q6.in");
	myfile>>v>>e;
	
	list< pair<int, int> > adj[v];
	
	FOR(i,0,e){
		myfile>>a>>b>>w;
		adj[a].push_back(make_pair(b,w));
		adj[b].push_back(make_pair(a,w));
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, std::greater<pair<int, int> > > pq;
	
	int src=0;
	
	vector<int> key(v, INF);
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
			
			if(!vis[node] && key[node] > weight){
				key[node] = weight;
				pq.push(make_pair(node,key[node]));
				par[node] = u;
			}
		}
	}
	
	cout<<"----------------Original Graph----------------- \n";
	int sum=0;
	FOR(i,1,v) {
		cout<<par[i]<<"-"<<i<<":"<<key[i]<<endl;
		sum += key[i];
	}
	
	cout<<endl<<"Minimum Weight of Acyclic Subset of Given Graph: "<< sum<<endl<<endl;
	
	
	// ------------------------ Modified Graph Spanning Tree -----------------------------
	
	FOR(u,0,v){
		list<pair<int, int> >::iterator i;
		for(i=adj[u].begin(); i!=adj[u].end(); i++)
			(*i).second *= (*i).second;
	}
	
	FOR(i,0,v){
		key[i] = INF;
		par[i] = -1;
		vis[i] = false;
	}
	
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
			
			if(!vis[node] && key[node] > weight){
				key[node] = weight;
				pq.push(make_pair(node,key[node]));
				par[node] = u;
			}
		}
	}
	
	cout<<"-------------------Modified Graph---------------------\n";
	sum=0;
	FOR(i,1,v) {
		cout<<par[i]<<"-"<<i<<":"<<key[i]<<endl;
		sum += key[i];
	}
	
	cout<<endl<<"Minimum Weight of Acyclic Subset of Given Graph: "<< sum<<endl;
	
	return 0;
}
		
	
