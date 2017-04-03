/* Question 3 is based on finding Closest-Pair
   By Parul Bansal (B14116)
   Here we implement using Divide & Conquer Strategy. 
   
    Example -
   --Input--
    6
	2 3
	12 30
	40 50
	5 1
	12 10
	3 4


   --Output--
	The smallest distance is 1.41421

*/

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cfloat>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)

class Point {

	int x;
	int y;
	
	public:
	Point(){}
	
	Point(int x, int y){
		x = this->x;
		y = this->y;
	}
	
	void setValues(int a, int b){
		x = a;
		y = b;
	}
	
	int getX(){
		return x;
	}
	
	int getY(){
		return y;
	}
	
	double eucDist(Point p){
		int xd = x - p.getX();
		int yd = y - p.getY();
		return sqrt(xd*xd + yd*yd);
	
	}
};

bool cmpX(Point& p1, Point& p2){
	return (p1.getX() < p2.getX());
}

bool cmpY(Point& p1, Point& p2){
	return (p1.getY() < p2.getY());
}


double bruteForce(Point P[], int n)
{
    double min = DBL_MAX;
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            if (P[i].eucDist(P[j]) < min)
                min = P[i].eucDist(P[j]);
            }
         }
    return min;
}

double min(double a, double b){
	return (a<b)?a:b;
}

double stripClosest(Point strip[], int size, double d)
{
    double min = d;
    for (int i = 0; i < size; ++i){
        for (int j = i+1; j < size && (strip[j].getY() - strip[i].getY()) < min; ++j){
            if (strip[i].eucDist(strip[j]) < min)
                min = strip[i].eucDist(strip[j]);
 		}
 	}
    return min;
}



double closestSub(Point Px[], Point Py[], int n){
	if(n<=3)
		return bruteForce(Px,n);
	
	int mid = n/2;
	Point midPoint = Px[mid];
	
	Point Pyl[mid+1];
	Point Pyr[n-mid-1];
	int li = 0, ri = 0;
    for (int i = 0; i < n; i++){
      if (Py[i].getX() <= midPoint.getX())
         Pyl[li++] = Py[i];
      else
         Pyr[ri++] = Py[i];
    }
    
    double delta1 = closestSub(Px, Pyl, mid);
    double delta2 = closestSub(Px + mid, Pyr, n-mid);
	
	double d = min(delta1, delta2);
	
	
	Point strip[n];
	int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs(Py[i].getX() - midPoint.getX()) < d)
            strip[j++] = Py[i];
      }

	return min(d,stripClosest(strip, j, d));
	
}

double closest(Point P[], int n)
{
    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }
 
    sort(Px, Px+n, cmpX);
    sort(Py, Py+n, cmpY);
 
    return closestSub(Px, Py, n);
}

int main(){
	int n,a,b;
	cin>>n;
	Point P[n];
	FOR(i,0,n){
		cin>>a>>b;
		P[i].setValues(a,b);
	}
	
	//FOR(i,0,n)
		//cout<<P[i].getX()<<" "<<P[i].getY()<<endl;
	cout<<"The smallest distance is "<<closest(P,n)<<endl;
	return 0;
 
}
