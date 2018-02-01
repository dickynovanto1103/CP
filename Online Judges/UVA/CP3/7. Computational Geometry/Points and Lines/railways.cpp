#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000
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
double dist(point p1, point p2){return hypot(p1.x-p2.x,p1.y-p2.y);}
point rotate(point p, double theta){
	double rad = degToRad(theta);
	return point(p.x*cos(rad) - p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
}

struct line{double a,b,c;};

void pointsToLine(point p1, point p2, line &l){
	if(fabs(p1.x-p2.x) < eps){
		l.a = 1.0; l.b = 0.0; l.c = -p1.x;
	}else{
		l.a = -(double)(p1.y-p2.y) / (p1.x-p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a*p1.x) - p1.y;
	}
}

bool areParallel(line l1, line l2){return ((fabs(l1.a-l2.a)<eps) && (fabs(l1.b-l2.b)<eps));}
bool areSame(line l1, line l2){
	if(areParallel(l1,l2)){return fabs(l1.c-l2.c)<eps;}
	return false;
}

bool areIntersect(line l1, line l2, point &p){
	if(areParallel(l1,l2)){return false;}
	p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
	if(fabs(l1.b) > eps){p.y = -(l1.a*p.x + l1.c);}
	else{p.y = -(l2.a*p.x + l2.c);}
	return true;
}

struct vec{
	double x,y;
	vec(double _x, double _y): x(_x), y(_y){}
};

vec toVec(point a, point b){
	return vec(b.x-a.x, b.y-a.y);
}
vec scale(vec v, double s){
	return vec(v.x*s,v.y*s);
}
point translate(point p, vec v){//translate p sebanyak v
	return point(p.x+v.x, p.y+v.y);
}
double dot(vec a, vec b){return (a.x*b.x + a.y*b.y);}
double norm_sq(vec v){return (v.x*v.x + v.y*v.y);}

double distToLine(point p, point a, point b, point &c){
	vec ap = toVec(a,p), ab = toVec(a,b);
	double u = dot(ap,ab) / norm_sq(ab);
	c = translate(a,scale(ab,u));
	return dist(p,c);
}
double distToLineSegment(point p, point a, point b, point &c){
	//if(a==b){return }cek nanti disini
	vec ap = toVec(a,p), ab = toVec(a,b);
	double u = dot(ap,ab) / norm_sq(ab);
	if(u<0.0){c = point(a.x,a.y); //closer to a
		return dist(p,a);
	}
	if(u>1.0){
		c = point(b.x,b.y);
		return dist(p,b);
	}
	return distToLine(p,a,b,c);
}

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


int main() {
	point p1;

	while(scanf("%lf %lf",&p1.x,&p1.y)!=EOF){
		int n,i;
		scanf("%d",&n);
		line l;
		vector<point> P;
		point P1,pans,c1,c2,c;
		double ans = inf;
		for(i=0;i<n;i++){
			scanf("%lf %lf",&P1.x,&P1.y);
			P.pb(P1);
			/*pointsToLine(P1,P2,l);
			double jawab1 = distToLineSegment(p1,P1,P2,c1);
			double jawab2 = distToLineSegment(p2,P1,P2,c2);
			double jawab = min(jawab1,jawab2);
			if(fabs(jawab-jawab1)<eps){c = c1;}
			else if(fabs(jawab-jawab2)<eps){c=c2;}
			if(ans>jawab){pans = c;}*/
			
		}
		scanf("%lf %lf",&P1.x,&P1.y);
		P.pb(P1);
		for(i=0;i<n;i++){
			double jawab = distToLineSegment(p1,P[i],P[i+1],c);
			if(ans>jawab){pans = c; ans = jawab;}
		}

		printf("%.4lf\n%.4lf\n",pans.x,pans.y);
	}
	return 0;
}