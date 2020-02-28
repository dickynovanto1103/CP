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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii,ii> iiii;
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

bool isInRange(point p, int r, int c) {
	int x = p.x, y = p.y;
	return x >= 1 && x <= r && y>=1 && y<=c;
}

int hitungJarak(ii a, ii b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

pair<point, point> constructPoint(ii p, int jarak, int i) {
	point p1, p2;
	if(i == 0) {
		p1.x = p.first; p1.y = p.second+jarak;
		p2.x = p.first+jarak; p2.y = p.second;
		if(p1.x == p2.x && p1.y == p2.y) {
			p1.x--; p1.y++;
			p2.x++; p2.y--;	
		}
	}else if(i == 1) {
		p1.x = p.first-jarak; p1.y = p.second;
		p2.x = p.first; p2.y = p.second + jarak;
		if(p1.x == p2.x && p1.y == p2.y) {
			p1.x++; p1.y++;
			p2.x--; p2.y--;	
		}
	}else if(i == 2) {
		p1.x = p.first; p1.y = p.second - jarak;
		p2.x = p.first + jarak; p2.y = p.second;
		if(p1.x == p2.x && p1.y == p2.y) {
			p1.x--; p1.y--;
			p2.x++; p2.y++;	
		}
	}else if(i == 3){
		p1.x = p.first-jarak; p1.y = p.second;
		p2.x = p.first; p2.y = p.second - jarak;
		if(p1.x == p2.x && p1.y == p2.y) {
			p1.x--; p1.y++;
			p2.x++; p2.y--;	
		}
	}
	return {p1, p2};
}

int main(){
	int r,c,q,i,j;
	scanf("%d %d %d",&r,&c,&q);
	vector<line> v;
	set<point> intersect;
	ii listKoor[5] = {ii(1,1), ii(r,1), ii(1,c), ii(r,c), ii(((2+r)/2), (c+2)/2)};
	int res[5];
	for(i=0;i<5;i++){
		if(i == 4) {
			point pnow = *intersect.begin();
			// printf("pnow: %lf %lf\n",pnow.x, pnow.y);
			listKoor[i] = ii((int)pnow.x, (int)pnow.y);
		}
		printf("? %d %d\n",listKoor[i].first, listKoor[i].second);
		fflush(stdout);
		int jarak;
		scanf("%d",&jarak);
		res[i] = jarak;
		point p1, p2;
		
		if(i == 4){
			
			//bikin 4 line
			int dx[] = {-1,1,0,0};
			int dy[] = {0,0,-1,1};
			for(j=0;j<4;j++){
				pair<point,point> ans = constructPoint(listKoor[i], jarak, j);
				p1 = ans.first, p2 = ans.second;
				line garis;
				pointsToLine(p1,p2,garis);
				for(int k=0;k<v.size();k++){
					line garis2 = v[k];
					point inter;
					if(areIntersect(garis, garis2, inter)) {
						if(isInRange(inter, r, c)){
							intersect.insert(inter);
						}
					}
				}
				v.pb(garis);
			}
			goto hell;
		}else{
			pair<point,point> ans = constructPoint(listKoor[i], jarak, i);
			p1 = ans.first, p2 = ans.second;
		}

		// point p1(1,1+jarak);
		// point p2(1+jarak,1);
		line garis;
		pointsToLine(p1,p2,garis);

		for(j=0;j<v.size();j++){
			line garis2 = v[j];
			point inter;
			if(areIntersect(garis, garis2, inter)) {
				if(isInRange(inter, r, c)){
					intersect.insert(inter);
				}
			}
		}
		v.pb(garis);
	}

	hell:;
	// printf("%d\n",(int)intersect.size());
	assert(intersect.size() > 0);
	if(intersect.size() == 1) {
		point p = *intersect.begin();
		ii ans = ii((int)p.x, (int)p.y);
		printf("! %d %d %d %d\n",ans.first, ans.second, ans.first, ans.second);
	}else {
		printf("!");
		set<point>::iterator it;
		vii listPoint;
		for(it=intersect.begin();it!=intersect.end();it++){
			point p = *it;
			ii ans = ii((int)p.x, (int)p.y);
			listPoint.pb(ans);
			// printf(" %d %d",ans.first, ans.second);
		}
		for(i=0;i<listPoint.size();i++){
			for(j=i+1;j<listPoint.size();j++){
				ii p1 = listPoint[i], p2 = listPoint[j];
				bool valid = true;
				for(int k=0;k<5;k++){
					int jarak1 = hitungJarak(listKoor[k], p1);
					int jarak2 = hitungJarak(listKoor[k], p2);
					int minim = min(jarak1, jarak2);
					if(minim != res[k]){valid = false; break;}
				}
				if(valid){printf(" %d %d %d %d\n",p1.first, p1.second, p2.first, p2.second); return 0;}
			}
		}
		printf("\n");
	}

	return 0;
};