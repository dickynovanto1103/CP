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
vec scale(vec v, double s){
	return vec(v.x*s,v.y*s);
}
point translate(point p, vec v){//translate p sebanyak v
	return point(p.x+v.x, p.y+v.y);
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

double distToLine(point p, point a, point b, point &c){
	vec ap = toVec(a,p), ab = toVec(a,b);
	double u = dot(ap,ab) / norm_sq(ab);
	c = translate(a,scale(ab,u));
	return dist(p,c);
}
double distToLineSegment(point p, point a, point b, point &c){
	if(a==b){return dist(p,a);}
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

point pivot;
bool angleCmp(point a, point b){
	if(collinear(pivot, a, b)){return dist(pivot,a) < dist(pivot,b);}
	point d1,d2;
	d1.x = a.x - pivot.x, d1.y = a.y - pivot.y;
	d2.x = b.x - pivot.x, d2.y = b.y - pivot.y;
	return (atan2(d1.y,d1.x) - atan2(d2.y,d2.x)) < 0;
}

int main() {
	int n,i;
	vector<point> P;
	scanf("%d",&n);
	double xpertama,ypertama;
	for(i=0;i<n;i++){
		double a,b;
		scanf("%lf %lf",&a,&b); point p(a,b); P.pb(p);
	}
	P.pb(P[0]);
	double a,b;
	scanf("%lf %lf",&a,&b); point p(a,b);
	if(inPolygon(p,P)){
		//cari jarak terdekat dengan semua sisi
		double ans = (double)inf;
		point c;
		for(i=0;i<P.size()-1;i++){
			double jarak = distToLineSegment(p,P[i],P[i+1],c);
			//printf("jarak node dengan garis idx %d dan %d adalah: %lf\n",i,i+1,jarak);
			ans = min(ans,jarak);
		}
		//double jarak = distToLineSegment(p,P[0],P[n-1],c);
		//ans = min(ans,jarak);
		//printf("jarak node dengan garis idx %d dan %d adalah: %lf\n",n-1,0,jarak);
		printf("%.9lf\n",ans);
	}else{
		for(i=0;i<n;i++){//cari ada yang sama dengan point atau ngga
			if(fabs(a-P[i].x)<eps && fabs(b-P[i].y)<eps){break;}
		}
		if(i<n){printf("0.000000000\n");}//ada yg sama...
		else{printf("-1\n");}
		
	}
	return 0;
}