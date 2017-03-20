/* Question 2 is based on whether cycle is present or not in graph
   By Parul Bansal (B14116)
   Input is taking from a2.in input file
   
   Example-
   --Input--
   5 5
   1 0
   0 2
   2 4
   0 3
   3 4
   
   --Output--
   Vertices in cycle
   ---------------------
   0 3 4 2 
   Graph contains cycle
   
 */
#include<cstdio>
#include<iostream>
#include<fstream>
#include<list>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;

bool isCycleSub(int u, bool vis[], int par, std::list<int> adj[]){
	
		vis[u]=true;
		
		list<int>::iterator i;
		for(i=adj[u].begin(); i!=adj[u].end(); i++){
			if(!vis[*i]){
				if(isCycleSub(*i, vis, u, adj)) {
					cout<<*i<<" ";
					return true; }
				}
			else if(*i != par){
				cout<<"Vertices in cycle\n";
				cout<<"---------------------\n";
				cout<<*i<<" ";
				return true;}
		}
		
	return false;
	
}

int main(){
	int v,e,a,b;
	ifstream myfile("a2.in");
	myfile>>v>>e;
	bool *vis = new bool[v];
	
	FOR(i,0,v)
		vis[i]=false;
	
	list<int> adj[v];
	
	FOR(i,0,e){
		myfile>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	FOR(i,0,v){
		if(!vis[i]){
			if(isCycleSub(i, vis, -1, adj)){
				a=-1;
				cout<<"\nGraph contains cycle\n";
			}
		}
	}
	
	if(a!=-1)
		cout<<"Graph doesn't contain cycle\n";
		
	return 0;
}
	
	
