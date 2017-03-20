/* Question 1 is based on Huffman Prefix Codes
   By Parul Bansal (B14116)
   Input is taking from huff1.in input file
   Implementation is done using Priority Queue
   
    Example -
   --Input--
    6
	a 5
	b 9
	c 12
	d 13
	e 16 
	f 45

   --Output--
	f - 0
	c - 100
	d - 101
	a - 1100
	b - 1101
	e - 111
      
*/

#include<cstdio>
#include<iostream>
#include<queue>
#include<fstream>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FREE -1
using namespace std;

struct TreeNode {
	char data;
	int freq;
	TreeNode *le, *ri;
	
	TreeNode(char data, int freq){
		le=NULL; ri=NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct cmpfunc {

	bool operator()(TreeNode *l, TreeNode* r){
		return (l->freq > r->freq);
	}
};

void printPrefixCode(struct TreeNode* tr, string str){
	
		if(tr == NULL)
			return;
			
		if(tr->data != '#')
			cout<<tr->data<<" - " <<str<<endl;
		
		printPrefixCode(tr->le, str+"0");
		printPrefixCode(tr->ri, str+"1");
	}
			

int main(){
	ifstream myfile("huff1.in");
	int n;
	myfile>>n;
	char c[n];
	int freq[n];
	FOR(i,0,n) myfile >> c[i] >> freq[i];
	
	struct TreeNode *le, *ri, *top;
	priority_queue<TreeNode*, vector<TreeNode*>, cmpfunc > pq;
	
	FOR(i,0,n) 
		pq.push(new TreeNode(c[i], freq[i]) );
		
	while(pq.size()!=1){
		
		le = pq.top();
		pq.pop();
		
		ri=pq.top();
		pq.pop();
		
		//cout<<le->data<<" "<<ri->data<<endl;
		top = new TreeNode('#', le->freq + ri->freq);
		top->le = le;
		top->ri = ri;
		pq.push(top);
	}
	
	printPrefixCode(pq.top(), "");
    return 0;

}
