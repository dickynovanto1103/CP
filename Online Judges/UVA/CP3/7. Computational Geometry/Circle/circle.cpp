#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

double degToRad(double a){return a*pi/180.0;}
double radToDeg(double a){return a*180.0/pi;}

struct point_i{
	int x,y;
	point_i(){x = 0; y=0;}
	point_i(int _x, int _y){x = _x; y = _y;}
};

struct point{
	double x,y;
	point(){x = y = 0.0;}
	point(double _x, double _y): x(_x), y(_y){}
	bool operator < (point other) const {
		if(fabs(x-other.x)>eps){return x < other.x;}
		return y<other.y;
	}
	bool operator == (point other){return ((fabs(x-other.x)<eps) && (fabs(y-other.y)<eps));}
};

int insideCirlce(point p, point center, double r){
	double dx = p.x - center.x, dy = p.y-center.y;
	double Euc = dx*dx + dy*dy, rSq = r*r;
	if(fabs(Euc-rSq)<eps){return 1;}//in border
	if(Euc<rSq){return 0;}//inside
	if(Euc>rSq){return 2;}//outside
}

bool circle2PtsRad(point p1, point p2, double r, point& c){
	double d2 = (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
	double det = r*r/d2 - 0.25;
	if(det<0.0){return false;}
	double h = sqrt(det);
	c.x = (p1.x+p2.x)*0.5 + (p1.y-p2.y)*h;
	c.y = (p1.y+p2.y)*0.5 + (p2.x-p1.x)*h;
	return true;
}

int main() {
	
	return 0;
}