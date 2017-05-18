/* Question 3 is based on finding shortest-path in a graph

   By Parul Bansal
   Implementation is done using Greedy Strategy (DIJKSTRA'S ALGORITHM)) 

   Example-
   --Input--
   6 7
   0 1 5
   1 2 3
   2 3 1
   3 4 13 
   4 5 3
   4 1 17
   5 0 2
   Enter Source
   2

   --Ouptut--
   Vertices	 Distance from source
   0		 8
   1		 3
   2		 0
   3		 1
   4		 13
   5		 10

*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<list>
#include <climits>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define INF INT_MAX


int main(){
	int v,e,a,b,w,src;
	cin>>v>>e;
	
	list< pair<int, int> > adj[v];
	
	FOR(i,0,e){
		cin>>a>>b>>w;
		adj[a].push_back(make_pair(b,w));
		adj[b].push_back(make_pair(a,w));
	}
	cout<<"Enter Source\n";
	cin>>src;
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, std::greater<pair<int, int> > > pq;
	
	vector<int> key(v, INF);
	
	pq.push(make_pair(0,src));
	key[src] = 0;
	
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		
		list<pair<int, int> >::iterator i;
		for(i=adj[u].begin(); i!=adj[u].end(); i++){
			int node = (*i).first;
			int weight = (*i).second;
			
			if(key[node] > key[u] + weight){
				key[node] = key[u] + weight;
				pq.push(make_pair(key[node],node));
			}
		}
	}
	
	cout<<"Vertices	Distance from source\n";
	for(int i=0;i<v;i++)
		cout<<i<<"		"<<key[i]<<endl;
	return 0;
}
	
