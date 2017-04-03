/* Question 2 is based on Counting Inversions
   By Parul Bansal (B14116)
   Here we implement using Divide & Conquer Strategy (almost same as Merge Sort). 
   
    Example -
   --Input--
    6
	83 86 77 15 93 35 

   --Output--
	Number of inversions are 9  
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)

int sort_and_count(vector<int>& a, int lo, int hi);
int merge_and_count(vector<int>& a,int lo,int mid,int hi);
	  	  
int sort_and_count(vector<int>& a, int lo, int hi){
	int cnt=0;
	if(lo<hi){
		int q = (lo+hi)/2;
		cnt += sort_and_count(a,lo,q);
		cnt += sort_and_count(a,q+1,hi);
		cnt += merge_and_count(a,lo,q,hi);
		}
	return cnt;
	}	
		
int merge_and_count(vector<int>& a,int lo,int mid,int hi){
	int n1 = hi-lo+1;
	int p = lo;
	int q = mid+1;
	int cnt=0;
	vector<int> a1(n1);
	int k=0;
	for(int i=lo;i<hi+1;i++){
		if(p>mid)
			a1[k++] = a[q++];
		else if(q>hi)
			a1[k++]= a[p++];
		else if(a[p]>a[q]){
			a1[k++] = a[q++];
			cnt += mid-p+1;
		}
		else
			a1[k++] = a[p++];
	   }
	
	for(int p=0;p<k;p++)
		a[lo++] = a1[p];	
	return cnt;
}

int main(){
	int n,a;
	cin>>n;
	vector<int> ve;
	FOR(i,0,n){
		a = rand()%100;
		ve.push_back(a);
		cout<<a<<" ";
	}
	cout<<endl;
	cout<<"Number of inversions are "<<sort_and_count(ve,0,n-1);
	return 0;
}
