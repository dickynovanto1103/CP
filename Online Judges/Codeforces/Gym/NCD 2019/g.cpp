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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

double akhir(double deg, int v) {
	double vy = v*sin(deg);
	double t = 2.0*vy/10.0;
	double vx = v*cos(deg);
	printf("cos(%lf): %lf\n",deg, cos(deg));
	double dist = vx*t;
	return dist;
}

double overlap(double a, double b, double c, double d){
	if(d < a || c > b)
		return 0;
	return min(b, d) - max(a, c);
}

bool can1(double deg, int v, int a, int b) {
	double vy = v*sin(deg);
	double t = 2.0*vy/10.0;
	double vx = v*cos(deg);
	double dist = vx*t;

	if(dist > a) {
		return true;
	}else{
		return false;
	}
}

bool can2(double deg, int v, int a, int b) {
	double vy = v*sin(deg);
	double t = 2.0*vy/10.0;
	double vx = v*cos(deg);
	double dist = vx*t;
	if(dist > b) {
		return true;
	}else{
		return false;
	}
}

int main(){
	double ref = pi / 2;
	double g = 10;
	int t;
	scanf("%d", &t);
	while(t--){
		int n, v, l, r;
		scanf("%d %d %d %d", &n, &v, &l, &r);
		double lt = l * pi / 180.0;
		double rt = r * pi / 180.0;

		double tot = rt - lt;

		// cerr<<"range "<<lt<<" "<<rt <<" "<<vv<<endl;
		for(int i=0;i<n;++i){
			int a, b;
			scanf("%d %d", &a, &b);
			double mid, ans1 = -1, ans2 = -1, kiri = lt, kanan = rt;
			for(int j=0;j<50;j++){
				mid = (kiri + kanan) / 2.0;
				if(can1(mid, v, a, b)) {
					ans1 = mid;
					printf("ans1 jd: %lf akhir: %lf\n",ans1, akhir(ans1, v));
					kanan = mid;
				}else{
					kiri = mid;
				}
			}
			printf("ans: %lf\n",akhir(0.5, v));
			kiri = lt, kanan = rt;
			for(int j=0;j<50;j++){
				mid = (kiri + kanan) / 2.0;
				if(can2(mid, v, a, b)) {
					ans2 = mid;
					kiri = mid;
				}else{
					kanan = mid;
				}
			}
			printf("tujuan akhir: %lf %lf\n",akhir(ans1, v), akhir(ans2, v));
			// double li = double(a) * g / vv;
			// double ri = min(double(b), maxd) * g / vv;
			// double x = asin(li)/2;
			// double y = asin(ri)/2;
			// cerr<<li<<" "<<ri<<" "<<x<<" "<<y<<endl;
			if(ans1 == -1 || ans2 == -1){printf("0.0000\n");}
			else{
				printf("rt: %lf lt: %lf\n",rt, lt);
				printf("ans1: %lf ans2: %lf\n",ans1, ans2);
				printf("selisih; %lf %lf\n",ans1-ans2, rt-lt);
				double ans = (ans1 - ans2) / tot;
				printf("%.4lf\n", ans);	
			}
			
		}
	}
	return 0;
};