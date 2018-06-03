#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
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

// line segment p-q intersect with line A-B.
point lineIntersectSeg(point p, point q, point A, point B) {
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v)); }

// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
  vector<point> P;
  for (int i = 0; i < (int)Q.size(); i++) {
    double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
    if (i != (int)Q.size()-1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
    if (left1 > -eps) P.push_back(Q[i]);       // Q[i] is on the left of ab
    if (left1 * left2 < -eps)        // edge (Q[i], Q[i+1]) crosses line ab
      P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
  }
  if (!P.empty() && !(P.back() == P.front()))
    P.push_back(P.front());        // make P's first point = P's last point
  return P; }

vector<point> p;

int main(){
	double x[5],y[5];
	int i,j;


	for(i=0;i<4;i++){

		scanf("%lf %lf",&x[i],&y[i]);
		point po(x[i], y[i]);
		p.pb(po);
		// p[i].x = x[i], p[i].y = y[i];
	}
	// printf("i: %d\n",i);
	point po(x[0], y[0]);
	p.pb(po);
	// p[4].x = x[0], p[4].y = y[0];
	
	

	double sum = 0;

	vector<point> hasilPerpotongan;

	for(j=0;j<4;j++){
		point p1,p2;
		// printf("j: %d\n",j);
		double pengali;
		if(j==0){
			p1.x = 10000.5; p1.y= -0.5; 
			p2.x = -10000.5; p2.y = -0.5;
			pengali = 1.0;
		}else if(j==1){
			p1.x = 0.5; p1.y= 1000.5; 
			p2.x = 0.5; p2.y = -1000.5;
			pengali = 3;
		}else if(j==2){
			p1.x = -10000.5; p1.y= 0.5; 
			p2.x = 10000.5; p2.y = 0.5;
			pengali = 6;
		}else{
			p1.x = -0.5; p1.y= -1000.5; 
			p2.x = -0.5; p2.y = 1000.5;
			pengali = 4;
		}
		hasilPerpotongan = cutPolygon(p1, p2, p);
		// printf("hasilPerpotongan\n");
		double luas = area(hasilPerpotongan);
		sum+=(luas*5*pengali / (124.0));
		// printf("luas: %.2lf sum jd: %.9lf\n",luas,sum);
		// for(int k=0;k<hasilPerpotongan.size();k++){
		// 	printf("%lf %lf\n",hasilPerpotongan[k].x,hasilPerpotongan[k].y);
		// }
	}
	sum+=(4.0*5*5*5/(124.0));
	printf("%.9lf\n",sum);
	return 0;
};