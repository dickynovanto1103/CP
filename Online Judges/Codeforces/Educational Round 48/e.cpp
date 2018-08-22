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

const int maxn = 2e5 + 5;

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

int l[maxn], r[maxn];
vi listPoint;
int sy, a,b;

int cariIdxPalingKanan(int n, int x, int y){
	int kiri = 0, kanan = 2*n - 1, mid, ans = 0;
	// printf("x: %d y: %d\n",x,y);
	while(kiri <= kanan){
		mid = (kiri + kanan)/2;
		int titik = listPoint[mid];
		double titikDiKanan;

		point p1(x,y);
		point p2(titik,0);
		line l;
		pointsToLine(p1,p2,l);
		titikDiKanan = -((double)sy*(double)l.b + (double)l.c) / (double)l.a;
		
		if(titikDiKanan < b){
			ans = mid;
		
			kiri = mid+1;
		}else{
			kanan = mid-1;
		}
	}
	return ans;
}

int cariIdxPalingKiri(int n, int x, int y){
	int kiri = 0, kanan = 2*n - 1, mid, ans = 0;
	// printf("x: %d y: %d\n",x,y);
	bool assigned = false;
	while(kiri <= kanan){
		mid = (kiri + kanan)/2;
		int titik = listPoint[mid];
		double titikDiKiri;

		point p1(x,y);
		point p2(titik,0);
		line l;
		pointsToLine(p1,p2,l);
		titikDiKiri = -((double)sy*(double)l.b + (double)l.c) / (double)l.a;
		if(titikDiKiri > a){
			// printf("halo\n");
			assigned = true;
			ans = mid;
			kanan = mid-1;
		}else{

			kiri = mid+1;
		}
	}
	if(!assigned){
		ans = kanan;
	}
	return ans;	
}

int main(){
	
	int n,i,j;
	
	int q;
	scanf("%d %d %d",&sy,&a,&b);
	scanf("%d",&n);
	
	ll prefSum[2*maxn];
	int idx = 0;
	ll sumSebelum = 0;
	for(i=0;i<n;i++){
		scanf("%d %d",&l[i],&r[i]);
		listPoint.pb(l[i]); listPoint.pb(r[i]);
		if(idx == 0){
			prefSum[idx] = 0;
			prefSum[idx+1] = prefSum[idx] + (r[i] - l[i]);
		}else{
			prefSum[idx] = prefSum[idx-1];
			prefSum[idx+1] = prefSum[idx] + (r[i] - l[i]);
		}
		idx+=2;
	}

	scanf("%d",&q);
	
	for(i=0;i<q;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		int idxTerkanan = cariIdxPalingKanan(n,x,y);
		int idxTerkiri = cariIdxPalingKiri(n,x,y);
		if(idxTerkanan < idxTerkiri){
			double lama;
			if(idxTerkanan % 2 == 0 && idxTerkiri %2 == 1){
				lama = fabs(b-a);
			}else{
				lama = 0;
			}
			printf("%.9lf\n",lama);
			continue;
		}
		int pointKiri = listPoint[idxTerkiri];
		int pointKanan = listPoint[idxTerkanan];
		point p1(x,y);
		point p2(pointKiri, 0);
		line l;
		pointsToLine(p1,p2,l);
		
		double titikTerkiri = -((double)sy*(double)l.b + (double)l.c) / (double)l.a;
		point p3(pointKanan, 0);
		pointsToLine(p1,p3,l);
		double titikTerkanan = -((double)sy*(double)l.b + (double)l.c) / (double)l.a;

		double pengurang = prefSum[idxTerkiri];
		
		double pengali = ((double)y-(double)sy) / (double)y;
		double lama = (double)(prefSum[idxTerkanan] - pengurang)*pengali;

		if(idxTerkiri % 2 == 1){
			if(titikTerkiri >= a){
				lama += fabs(titikTerkiri - a);	
			}	
		}
		if(idxTerkanan % 2 == 0){
			if(titikTerkanan <= b){
				lama += fabs(titikTerkanan - b);	
			}	
		}
		printf("%.9lf\n",lama);
	}


	return 0;
};