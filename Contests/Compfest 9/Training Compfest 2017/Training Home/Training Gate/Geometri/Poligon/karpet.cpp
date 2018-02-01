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
struct vec{
	double x,y;
	vec(double _x, double _y): x(_x), y(_y){}
};

vec toVec(point a, point b){
	return vec(b.x-a.x, b.y-a.y);
}
double dist(point p1, point p2){return hypot(p1.x-p2.x,p1.y-p2.y);}

double perimeter(const vector<point> &P){
	double result = 0.0;
	for(int i=0;i<P.size()-1;i++){
		result+=dist(P[i],P[i+1]);
	}
	return result;
}

double area(const vector<point> &P){
	double result = 0.0, x1,x2,y1,y2;
	for(int i=0;i<P.size()-1;i++){
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		result+=(x1*y2 - x2*y1);
	}
	return fabs(result)/2.0;
}

double dot(vec a, vec b){return (a.x*b.x + a.y*b.y);}
double norm_sq(vec v){return (v.x*v.x + v.y*v.y);}

double angle(point a, point o, point b){//return in rad
	vec oa = toVec(o,a), ob = toVec(o,b);
	return acos(dot(oa,ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}



double cross(vec a, vec b){return a.x*b.y - a.y*b.x;}
bool ccw(point p, point q, point r){
	return cross(toVec(p,q), toVec(p,r)) > 0;
}
bool collinear(point p, point q, point r){
	return fabs(cross(toVec(p,q), toVec(p,r))) < eps;	
}

bool isConvex(const vector<point> &P){
	int sz = P.size();
	if(sz <= 3){return false;}
	bool isLeft = ccw(P[0],P[1],P[2]);
	for(int i=1;i<sz-1;i++){
		if(ccw(P[i],P[i+1],P[(i+2)==sz? 1:i+2]) != isLeft){return false;}
	}
	return true;
}

bool inPolygon(point pt, const vector<point> &P){
	if(P.size()==0){return false;}
	double sum = 0.0;
	for(int i=0;i<P.size()-1;i++){
		if(ccw(pt,P[i],P[i+1])){sum+=angle(P[i],pt,P[i+1]);}
		else{sum-=angle(P[i],pt,P[i+1]);}
	}
	return fabs(fabs(sum)-2*pi) <eps;
}

int main() {
	int n,i;
	double x,y,xpertama,ypertama;
	vector<point> P;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lf %lf",&x,&y);
		if(i==0){xpertama = x; ypertama = y;}
		point p(x,y); P.pb(p);
	}
	point p(xpertama,ypertama); P.pb(p);
	printf("%.1lf\n",area(P));
	return 0;
}