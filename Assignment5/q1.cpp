/* Question 1 is based on finding K-node Vertex Cover 
   
   By Parul Bansal
   Example-
   --Input--
   10 14
   Enter Edges
   2 8
   2 5
   2 7
   4 6
   4 9
   0 5
   0 6
   1 6
   1 2
   3 9
   3 6
   5 6
   6 7
   8 9
   Enter k
   4

   --Ouput--
   0 2 6 9 

*/


#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)


set<int> cover;
set<int> vertexCover(set<int> nodes, vector<pair<int,int> > edges, int k, int n){
	if(edges.empty()) return set<int>();
	if(edges.size() > k*n)
		return nodes;

	pair<int,int> temp = edges[0];
	edges.erase(edges.begin());
	set<int> nodeCopy = nodes;
	nodeCopy.erase(temp.first);
	vector<pair<int,int> > edgesCopy;
	for(int i=0;i<edges.size();){
		if(edges[i].first == temp.first || edges[i].second == temp.first){
			edges.erase(edges.begin()+i);
			edgesCopy.push_back(edges[i]);
		}
		else i++;
	}
	if(vertexCover(nodeCopy, edges, k-1, n-1).size() == (k-1)){
		cover.insert(temp.first);
		return cover;
	}
	else {
		nodeCopy.insert(temp.first);
		nodeCopy.erase(temp.second);
		edges.insert(edges.end(),edgesCopy.begin(),edgesCopy.end());
		edgesCopy = vector<pair<int,int> >();
		for(int i=0;i<edges.size();){
			if(edges[i].first == temp.second || edges[i].second == temp.second){
				edges.erase(edges.begin()+i);
				edgesCopy.push_back(edges[i]);
			}
			else i++;
		}
		if(vertexCover(nodeCopy, edges, k-1, n-1).size() == (k-1)){
			cover.insert(temp.second);
			return cover;
		}
		else
			return nodes;
	 }
}




int main(){
	int n,m,k,u,v;
	cin>>n>>m;
	set<int> nodes;
	FOR(i,0,n) nodes.insert(i);
	vector<pair<int,int> > edges;
	//vector<int> cover;
	cout<<"Enter Edges\n";
	FOR(i,0,m){
		cin>>u>>v;
		edges.push_back(make_pair(u,v));
	}
	cout<<"Enter k\n";
	cin>>k;
	cover = vertexCover(nodes,edges,k,n);
	if (cover.size() <= k){
		for(set<int>::iterator it=cover.begin();it!=cover.end();it++) 
			cout << *it << " ";
		cout<<endl;
	}
	else cout<<k << "-node vertex cover is not possible.\n";
	return 0;
}