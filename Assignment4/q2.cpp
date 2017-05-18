/* Question 2 is based on solving 0-1 Knapsack Problem
   
   By Parul Bansal
   Implementation is done using Dynamic Programming Strategy

   Example -
   --Input--
   3 50
   60 10
   100 20
   120 30

   --Output--
   220
 
*/
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)

int max(int a, int b){
	return (a>b)?a:b;
}

int knapRec(int W, int val[], int w[], int n){
	if(n==0 || W==0)
		return 0;
	if(w[n-1] > W)
		return knapRec(W,val,w,n-1);
	return max(knapRec(W-w[n-1],val,w,n-1)+val[n-1], knapRec(W,val,w,n-1));
}

int knapDp(int W, int val[], int w[], int n){
	int k[n+1][W+1];
	FOR(i,0,n+1){
		FOR(j,0,W+1){
			if(i==0 || j==0)
				k[i][j]=0;
			else if(w[i-1] <= j)
				k[i][j] = max(k[i-1][j-w[i-1]] + val[i-1], k[i-1][j]);
			else
				k[i][j] = k[i-1][j];
		}
	}
	return k[n][W];
}

int main(){
	int n,W;
	cin>>n>>W;
	int val[n],w[n];
	FOR(i,0,n)
		cin>>val[i]>>w[i];
	cout<<knapDp(W,val,w,n)<<endl;
	return 0;
}
