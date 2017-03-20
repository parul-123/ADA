/* Question 1 is based on Huffman Prefix Codes
   By Parul Bansal (B14116)
   Input is taking from huff1.in input file
   Implementation is done without using Priority Queue
   
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
#include<algorithm>
#include<vector>
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
	FOR(i,0,n) myfile >> c[i]>>freq[i];
	
	vector<TreeNode*> ve;
	struct TreeNode *le, *ri, *top;
	
	FOR(i,0,n) 
		ve.push_back(new TreeNode(c[i], freq[i]) );
		
	while(ve.size()!=1){
		    
		    n = ve.size();
			TreeNode* node = ve[0];
			int index =0;
			FOR(j,1,n){
				if(node->freq > ve[j]->freq){
					node = ve[j];
					index = j;
				}
			}
			
			le = ve[index];
			ve.erase(ve.begin() + index);
			n--;
			
			node = ve[0];
			index =0;
			FOR(j,1,n){
				if(node->freq > ve[j]->freq){
					node = ve[j];
					index = j;
				}
			}
			
			ri = ve[index];
			ve.erase(ve.begin() + index);
			
			top = new TreeNode('#', le->freq + ri->freq);
			top->le =le;
			top->ri = ri;
			ve.push_back(top);
	}
	
	printPrefixCode(top, "");
	return 0;
}
