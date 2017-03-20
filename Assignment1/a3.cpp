/* Question 3 is based on finding minimum number of jumps hero has to
   By Parul Bansal (B14116)
   Input is taking from a3.in input file
   
   Example-
   --Input--
   5 5
   1 3
   2 3
   1 2
   3 5
   4 5
   1 4
   
   --Output--
   3
*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<fstream>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main(){
	int n,a,b,src,dest;
	long m;
	ifstream myfile("a3.in");
	myfile>>n>>m;
	bool adj[n][n];
	
	FOR(i,0,n){
		FOR(j,0,n)
			adj[i][j]=false;
		}
		
	FOR(i,0,m){
		myfile>>a>>b;
		adj[a-1][b-1]=true;
		adj[b-1][a-1]=true;
	}
	
	myfile>>src>>dest;
	
	bool vis[n];
	queue<int> qe;
	FOR(i,0,n)
		vis[i]=false;
		
	qe.push(src-1);
	int size=qe.size();
	int step=0;
	
	while(!qe.empty()){
			int u = qe.front();
			vis[u]=true;
			if(size==0){
				step++;
				size = qe.size();
				//cout<<endl;
			}
			if(u == dest-1){
				//cout<<"HH";
				//cout<<u<<" "<<dest-1<<endl;
				cout<<step<<endl;
				step=-1;
				break;}
			FOR(j,0,n){
				if(adj[u][j] && !vis[j]){
					qe.push(j);
					vis[j] = true;
				}
			}
			//cout<<u<<" ";
			qe.pop();
			size--;
		}
		
	if(step!=-1)
		cout<<"0\n";
		
	return 0;
}
		
		
					
		
	
	
	
	
