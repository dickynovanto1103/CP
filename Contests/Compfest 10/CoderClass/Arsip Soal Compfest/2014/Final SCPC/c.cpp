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

bool inPolygon(point p, const vector< point >& vp) {
  int wn = 0, n = (int)vp.size() - 1;
  for(int i = 0; i<n; i++) {
    long long cs = cross(vp[i+1], vp[i], p);
    if(cs == 0 && p.x <= max(vp[i].x, vp[i+1].x) && p.x >= min(vp[i].x, vp[i+1].x)
      && p.y <= max(vp[i].y, vp[i+1].y) && p.y >= min(vp[i].y, vp[i+1].y))
      return 1;
    if(wn == 0) {
      if(cs < 0)
        wn = -1;
      else
        if(cs > 0)
          wn = 1;
    }
    if(wn) {
      if(cs * wn <= 0)
        return 0;
    }
  }
  return 1;
}

point pivot;
bool angleCmp(point a, point b){
	if(collinear(pivot, a, b)){return dist(pivot,a) < dist(pivot,b);}
	point d1,d2;
	d1.x = a.x - pivot.x, d1.y = a.y - pivot.y;
	d2.x = b.x - pivot.x, d2.y = b.y - pivot.y;
	return (atan2(d1.y,d1.x) - atan2(d2.y,d2.x)) < 0;
}

vector<point> CH(vector<point> P) {
	int i,j, n =P.size();
	if(n<=3){
		if(!(P[0]==P[n-1])){P.pb(P[0]);}
		return P;
	}
	//find index so that P[idx] has lowest Y, if tie..the rightmost X
	int idx = 0;
	for(i=1;i<n;i++){
		if(P[i].y < P[idx].y || (P[i].y==P[idx].y && P[i].x > P[idx].x)){
			idx = i;
		}
	}
	//swap routine
	point temp = P[0]; P[0] = P[idx]; P[idx] = temp;
	//sort
	pivot = P[0];
	sort(++P.begin(),P.end(),angleCmp);

	vector<point> S;
	S.pb(P[n-1]); S.pb(P[0]); S.pb(P[1]);
	i = 2;
	while(i<n){
		j = S.size()-1;
		if(ccw(S[j-1],S[j],P[i])){S.pb(P[i++]);}
		else{S.pop_back();}
	}
	return S;
}

int main(){
	int t;
	scanf("%d", &t);
	int n,m,i,j;
	for(int cc=1;cc<=t;++cc){
		scanf("%d %d", &n, &m);
		vector<point> P;
		for(i=0;i<n;++i){
			int x,y;
			scanf("%d %d", &x, &y);
			point p((double)x, (double)y);
			P.pb(p);
		}

		sort(P.begin(), P.end());

		P.erase(unique(P.begin(), P.end()), P.end());
		P.pb(P[0]);
		vector<point> ch = CH(P);
		// cout<<ch.size()<<endl;
		for(int i=0;i<m;++i){
			int x, y;
			scanf("%d %d", &x, &y);
			point p(x,y);
			if(inPolygon(p, ch))
				puts("YA");
			else
				puts("TIDAK");	
		}
	}
	return 0;
}