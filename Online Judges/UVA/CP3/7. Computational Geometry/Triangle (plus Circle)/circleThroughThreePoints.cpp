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

/*TAMBAHAN LIBRARY DARI TRIANGLE*/
double perimeter(double ab, double bc, double ac){
	return ab+bc+ac;
}
double perimeter(point a, point b, point c){
	return perimeter(dist(a,b),dist(b,c),dist(a,c));
}

double area(double ab, double bc, double ac){
	double s = perimeter(ab,bc,ac)*0.5;
	return sqrt(s)*sqrt(s-ab)*sqrt(s-bc)*sqrt(s-ac);
}

double area(point a, point b, point c){
	return area(dist(a,b), dist(b,c), dist(a,c));
}

double rInCircle(double ab, double bc, double ac){//panjang jari"lingkaran dalam
	return(area(ab,bc,ac)/(0.5*perimeter(ab,bc,ac)));
}
double rInCircle(point a, point b, point c){
	return rInCircle(dist(a,b),dist(b,c),dist(a,c));
}
//cari titik tengah inscribed Circle dan radiusnya
int inCircle(point p1, point p2, point p3, point& ctr, double& r){//return 0..ga ada lingkaran dalam segitiga, otherwise return 1
	r = rInCircle(p1,p2,p3);
	if(fabs(r)<eps){return 0;}//3 point collinear
	line l1,l2;
	double ratio = dist(p1,p2)/dist(p1,p3);
	point p = translate(p2,scale(toVec(p2,p3),ratio/(1+ratio)));
	pointsToLine(p1,p,l1);

	ratio = dist(p2,p1)/dist(p2,p3);
	p = translate(p1,scale(toVec(p1,p3),ratio/(1+ratio)));
	pointsToLine(p2,p,l2);

	areIntersect(l1,l2,ctr);
	return 1;
}
double rCircumCircle(double ab, double bc, double ac){
	return ab*bc*ac / (4.0*area(ab,bc,ac));
}
double rCircumCircle(point a, point b, point c){
	return rCircumCircle(dist(a,b), dist(b,c), dist(a,c));
}

//cari titik tengah circumCircle dan radiusnya
int circumCircle(point p1, point p2, point p3, point &ctr, double &r){
  double a = p2.x - p1.x, b = p2.y - p1.y;
  double c = p3.x - p1.x, d = p3.y - p1.y;
  double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
  double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
  double g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));
  if (fabs(g) < eps) return 0;

  ctr.x = (d*e - b*f) / g;
  ctr.y = (a*f - c*e) / g;
  r = dist(p1, ctr);  // r = distance from center to 1 of the 3 points
  return 1; }

// returns true if point d is inside the circumCircle defined by a,b,c
int inCircumCircle(point a, point b, point c, point d) {
  return (a.x - d.x) * (b.y - d.y) * ((c.x - d.x) * (c.x - d.x) + (c.y - d.y) * (c.y - d.y)) +
         (a.y - d.y) * ((b.x - d.x) * (b.x - d.x) + (b.y - d.y) * (b.y - d.y)) * (c.x - d.x) +
         ((a.x - d.x) * (a.x - d.x) + (a.y - d.y) * (a.y - d.y)) * (b.x - d.x) * (c.y - d.y) -
         ((a.x - d.x) * (a.x - d.x) + (a.y - d.y) * (a.y - d.y)) * (b.y - d.y) * (c.x - d.x) -
         (a.y - d.y) * (b.x - d.x) * ((c.x - d.x) * (c.x - d.x) + (c.y - d.y) * (c.y - d.y)) -
         (a.x - d.x) * ((b.x - d.x) * (b.x - d.x) + (b.y - d.y) * (b.y - d.y)) * (c.y - d.y) > 0 ? 1 : 0;
}

bool canFormTriangle(double a, double b, double c){
	return (a+b>c) && (a+c>b) && (b+c>a);
}

int main() {
	double x[5],y[5],i;
	while(scanf("%lf %lf %lf %lf %lf %lf",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2])!=EOF){
		point ctr;
		double r;

		point p1(x[0],y[0]);
		point p2(x[1],y[1]);
		point p3(x[2],y[2]);

		circumCircle(p1,p2,p3,ctr,r);
		double x = ctr.x, y = ctr.y;
		char kar1,kar2;
		if(x<0.0){kar1 = '+';}
		else{kar1 = '-';}
		if(y<0.0){kar2 = '+';}
		else{kar2 = '-';}
		printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n",kar1,fabs(x),kar2,fabs(y),r);

		double c = x*x + y*y - r*r;
		char akhir = c<0.0 ? '-' : '+';
		printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n\n",kar1,fabs(x*2),kar2,fabs(y*2),akhir,fabs(c));
	}
	return 0;
}