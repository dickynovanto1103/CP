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

double overlap(double a, double b, double c, double d){
	if(d < a || c > b)
		return 0;
	return min(b, d) - max(a, c);
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
		ll v2 = 1LL*v*v;
		double vv = 1.0*v*v;
		double maxd = v2 / g;
		double tot = rt - lt;
		// cerr<<"range "<<lt<<" "<<rt <<" "<<vv<<endl;
		for(int i=0;i<n;++i){
			int a, b;
			scanf("%d %d", &a, &b);
			if(a * 10LL > v2 || tot < eps){
				puts("0.0000");
				continue;
			}
			double li = double(a) * g / vv;
			double ri = min(double(b), maxd) * g / vv;
			double x = asin(li)/2;
			double y = asin(ri)/2;
			// cerr<<li<<" "<<ri<<" "<<x<<" "<<y<<endl;
			double ans = overlap(x, y, lt, rt) + overlap(pi/2.0-y, pi/2.0-x, lt, rt);
			printf("%.4lf\n", ans / tot);
		}
	}
	return 0;
};