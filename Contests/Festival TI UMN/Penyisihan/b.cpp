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
double dist(point p1, point p2){
	double jarak = hypot(p1.x - p2.x , p1.y - p2.y);

	//double val = ((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y) * (p1.y-p2.y));
	double val = jarak*jarak;
	//printf("val: %lf\n",val);
	return val;
}
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

point P[110];
double memo[110][110];
double costTriangle(int i, int j, int k){
	//printf("dist: %lf\n",dist(P[i],P[j]));
	return dist(P[i],P[j]) + dist(P[i], P[k]) + dist(P[k],P[j]);
}

double solve(int n){
	//printf("masuk sini\n");
	if(n<3){

		return 0;
	}
	int i,j,k,l;
	for(l=0;l<n;l++){
		i=0;
		for(j=l;j<n;j++){
			if (j < i+2)
            memo[i][j] = 0;
	        else{
	            memo[i][j] = inf;
	            for (k = i+1; k < j; k++){
	              double val = memo[i][k] + memo[k][j] + costTriangle(i,j,k);
	              //printf("val: %lf\n",val);
	              if (memo[i][j] > val){memo[i][j] = val;}
	       		}
	        }
          	i++;
		}
	}
	return memo[0][n-1];
}
int main(){
	int tc,tt,i,j;
	
	scanf("%d",&tc);
	for(tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		int n;
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%lf %lf",&P[i].x,&P[i].y);}
		double ans = solve(n);
		//printf("ans: %lf\n",ans);
		ll jawab = (ll)ans;
		printf("%lld\n",jawab);
	}
	return 0;
};