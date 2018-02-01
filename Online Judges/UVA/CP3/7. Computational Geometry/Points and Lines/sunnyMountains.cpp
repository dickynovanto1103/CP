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

bool cmp(point a, point b){return a.x < b.x;}


int main() {
	int n,tc,i;
	vector<line> listLine;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		point P[110];
		for(i=0;i<n;i++){
			scanf("%lf %lf",&P[i].x,&P[i].y);
		}
		sort(P,P+n,cmp);
		/*for(i=0;i<n;i++){
			printf("[%d] %lf %lf\n",i,P[i].x,P[i].y);
		}*/
		line l;
		for(i=0;i<n-1;i++){pointsToLine(P[i],P[i+1],l); listLine.pb(l);}
		double ans=dist(P[n-1],P[n-2]);//asumsi n minimal 2
		point awal = P[n-2];

		int ukuran = listLine.size();
		for(i=ukuran-3;i>=0;i-=2){
			//printf("i: %d\n",i);
			line l1 = listLine[i];
			point p = awal; p.x = 0;//garis lurus
			point perpotongan;
			line l2;
			pointsToLine(p,awal,l2);
			areIntersect(l1,l2,perpotongan);
			point pointGaris1 = P[i], pointGaris2 = P[i+1];
			/*printf("pointGaris1: %.2lf %.2lf\n",pointGaris1.x,pointGaris1.y); printf("pointGaris2: %.2lf %.2lf\n",pointGaris2.x,pointGaris2.y);
			printf("perpotongan: %.2lf %.2lf\n",perpotongan.x,perpotongan.y);
			printf("awal: %.2lf %.2lf\n",awal.x,awal.y);*/
			double minimx = min(pointGaris1.x,pointGaris2.x), maksx = max(pointGaris1.x,pointGaris2.x);
			double minimy = min(pointGaris1.y,pointGaris2.y), maksy = max(pointGaris1.y,pointGaris2.y);

			if(perpotongan.x>=minimx && perpotongan.x<=maksx && perpotongan.y>=minimy && perpotongan.y<=maksy){
				ans+=dist(P[i],perpotongan);
				//printf("ditambahkan: %.2lf\n",dist(P[i],perpotongan));
				awal = P[i];
				//printf("awal jd: %.2lf %.2lf\n",awal.x,awal.y);
			}
		}
		//printf("ukuran: %d\n",ukuran);
		printf("%.2lf\n",ans);
		listLine.clear();
	}

	return 0;
}