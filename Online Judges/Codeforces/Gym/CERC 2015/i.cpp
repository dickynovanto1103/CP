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

const int maxn = 502;

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
double dist(point p1, point p2){return hypot((p1.x-p2.x),(p1.y-p2.y));}

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

vector<int> s[maxn][maxn];
double radius[maxn][maxn];

int main(){
	int n,q,i,j;
	memset(radius,-1,sizeof radius);
	scanf("%d",&n);
	int banyakOperasi = 0;
	clock_t begin, end;
	
	for(i=0;i<n;i++){
		int x,y;
		double r;
		scanf("%d %d %lf",&x,&y,&r);
		
		radius[x][y] = r;
		banyakOperasi++;
	}
	
	
	// for(i=1;i<=500;i++){
	// 	for(j=1;j<=500;j++){
	// 		sort(s[i][j].begin(), s[i][j].end());

	// 		// for(int k=0;k<s[i][j].size();k++){
	// 		// 	printf("i: %d j: %d -> %lf\n", i,j,s[i][j][k]);
	// 		// }
	// 	}
	// }

	scanf("%d",&q);
	begin = clock();
	int banyakQuery = 0;
	while(q--){
		banyakQuery++;
		int x1,x2,y1,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if(x1 > x2) {
			swap(x1,x2); swap(y1,y2);
		}
		point p1((double)x1,(double)y1);
		point p2((double)x2,(double)y2);
		line l;
		
		pointsToLine(p1,p2,l);
		
		int cnt = 0;
		if(l.b==0.0){
			//vertikal
			if(y1>y2){swap(y1,y2);}
			//iterasi
			for(i=y1;i<=y2;i++){
				if(radius[x1][i]>0){cnt++;}
				// cnt+=(s[x1][i].size());
			}

		}else{
			// printf("masuk sini\n");
			//iterasi x
			for(i=x1;i<=x2;i++){
				double y = -(i*l.a + l.c);
				int yAtas = (int)ceil(y);
				int yBawah = (int)floor(y);
				// printf("x: %d y: %lf yAtas: %d yBawah: %d\n",i,y,yAtas,yBawah);
				point perpotongan;
				point coba1(i,yAtas);
				point coba2(i,yBawah);
				int jarak = distToLine(coba1, p1,p2, perpotongan);
				
				if(jarak<=radius[i][yAtas]){cnt++;}
				// cnt+=s[i][yAtas].size();
				
				banyakOperasi++;
				
				if(yAtas != yBawah){
					int jarak = distToLine(coba2, p1,p2, perpotongan);
					if(jarak<=radius[i][yBawah]) {cnt++;}
					// if(s[i][yBawah].size()) {
					// 	// int idx = lower_bound(s[i][yBawah].begin(), s[i][yBawah].end(), jarak) - s[i][yBawah].begin();
					// 	// printf("jarak2: %lf idx: %d\n",jarak,idx);
					// 	// cnt+=(s[i][yBawah].size() - idx);
					// 	cnt+=s[i][yBawah].size();
					// }
					banyakOperasi++;
				}
			}
			end = clock();
			double waktu = (double)(end-begin) /CLOCKS_PER_SEC;
			if(waktu > 5.0){
			
				break;
			}
		}

		// cerr<<banyakQuery<<endl;
		printf("%d\n",cnt);


	}
	end = clock();
	cerr<<"waktu: "<<(double)(end-begin) /CLOCKS_PER_SEC<<endl;
	
	cerr<<"banyakOperasi: "<<banyakOperasi<<endl;
	return 0;
};	