/* Question 1 is based on finding Maximum Flow Problem
   for Graph G with source s and sink t. 

   By Parul Bansal
   Implementation is done using Ford-Fulkerson Algorithm.

   Example -
   --Input--
   4 5
   Enter source and sink
   0 3
   0 1 20
   0 2 10
   2 3 20
   1 3 10
   1 2 30
   --Output--
   The maximum possible flow is 30
   
*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)

bool bfs(vector<vector<int> >& adj, int s, int t, int par[], int v){
    bool vis[v];
    FOR(i,0,v)
    	vis[i]=false;
    queue <int> qe;
    qe.push(s);
    vis[s] = true;
    par[s] = -1;
 
    while (!qe.empty()){
        int u = qe.front();
        qe.pop();
 
        for (int i=0; i<v; i++){
            if (vis[i]==false && adj[u][i] > 0){
                qe.push(i);
                par[i] = u;
                vis[i] = true;
            }
        }
    }
    return (vis[t] == true);
}

int augment(vector<vector<int> >& adj, int flow, int par[], int src, int t){
	int path_flow = INT_MAX;
	for(int i = t; i!=src; i=par[i]){
		int u = par[i];
		path_flow = (path_flow > adj[u][i])?adj[u][i]:path_flow;
	}
	for(int i=t; i!=src; i=par[i]){
		int u = par[i];
		adj[u][i]-=path_flow;
		adj[i][u]+=path_flow;
	}
	flow += path_flow;
	return flow;
}


int maxFlow(vector<vector<int> >& adj,int s, int t, int v){
	int max_flow = 0;
	int par[v];
	while(bfs(adj,s,t,par,v)){
		int fNew = augment(adj, max_flow, par,s,t);
		max_flow = fNew;
	}
	return max_flow;
}

int main(){
	int v,e,src,sink;
	cin>>v>>e;
	cout<<"Enter source and sink\n";
	cin>>src>>sink;
	vector<vector<int> > adj(v, vector<int>(v,0));
	int a,b,w;
	FOR(i,0,e){
		cin>>a>>b>>w;
		adj[a][b]=w;
	}
	cout<<"The maximum possible flow is "<<maxFlow(adj,src,sink,v)<<endl;
	
	return 0;
}
