/* Question 4 is based on Segmented Least Squares
   By Parul Bansal (B14116)
   Time complexity of this algorithm is O(n^2) 
   Dynamic Programming Strategy is applied in this algorithm.
   
    Example -
   --Input--
    Enter the number of points
	6
	Enter 6 points: 
	1 4
	2 6
	4 12
	5 15
	10 24
	20 68
	Enter C
	10

   --Output--
	Cost of the optimal solution: 20.35
	Segment (y = 2.8 * x + 0.85 ) from points 1 to 4 with square error 0.35
	Segment (y = 4.4 * x + -20 ) from points 5 to 6 with square error 0

*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define MAXN 500

struct Point {
	int x,y;
	bool operator <(const Point &p) const {
		return (x < p.x);
	}
};

Point pts[MAXN+1];

double err[MAXN+1][MAXN+1];
double a[MAXN+1][MAXN+1];
double b[MAXN+1][MAXN+1];

double xy[MAXN+1], x[MAXN+1], y[MAXN+1], xSqr[MAXN+1], ySqr[MAXN+1];
double M[MAXN+1];
double seg[MAXN+1];

double segmentedLeastSquares(int n, int C){
	FOR(j,1,n+1){
		M[j] = err[1][j] + C;
		seg[j] = 1;
		FOR(i,2,j+1){
			if(M[i-1] + C + err[i][j] < M[j]){
				M[j] = M[i-1] + C + err[i][j];
				seg[j] = i;
			}
		}
	}
	return M[n];
}

void getSegments(int j){
	if(j<=0)
		return;
	int i = seg[j];
	getSegments(i-1);
	cout<<"Segment (y = "<<a[i][j]<<" * x + "<<b[i][j]<<" ) from points "<<i<<" to "<<j<<" with square error "<<err[i][j]<<endl;
}


int main(){
	int n;
	double C;
	cout<<"Enter the number of points\n";
	cin>>n;
	cout<<"Enter "<<n<<" points: \n";
	FOR(i,1,n+1)
		cin>>pts[i].x>>pts[i].y;
	cout<<"Enter C\n";
	cin>>C;
	
	sort(pts+1, pts+n+1);
	
	xy[0]= x[0] = y[0] = xSqr[0] = 0;
	FOR(j,1,n+1){
		x[j] = x[j-1] + pts[j].x;
		y[j] = y[j-1] + pts[j].y;
		xy[j] = xy[j-1] + pts[j].x * pts[j].y;
		xSqr[j] = xSqr[j-1] + pts[j].x * pts[j].x;
		ySqr[j] = ySqr[j-1] + pts[j].y * pts[j].y;
		
		FOR(i,1,j+1){
			
			int interval = j-i+1;
			int xTemp = x[j] - x[i-1];
			int yTemp = y[j] - y[i-1];
			int xyTemp = xy[j] - xy[i-1];
			int xSqrTemp = xSqr[j] - xSqr[i-1];
			int ySqrTemp = ySqr[j] - ySqr[i-1];
			
			a[i][j] = ((interval*xyTemp - xTemp*yTemp)*1.0)/((interval*xSqrTemp -  xTemp*xTemp)*1.0);
			b[i][j] = ((yTemp - a[i][j]*xTemp)*1.0)/(interval*1.0);
			
			err[i][j] = ySqrTemp + a[i][j]*a[i][j]*xSqrTemp - 2.0*a[i][j]*xyTemp + interval*b[i][j]*b[i][j] - 2.0*b[i][j]*yTemp + 2.0*a[i][j]*b[i][j]*xTemp;
		}
	
	}

	cout<<"Cost of the optimal solution: "<<segmentedLeastSquares(n,C)<<endl;
	getSegments(n);

	return 0;
}



