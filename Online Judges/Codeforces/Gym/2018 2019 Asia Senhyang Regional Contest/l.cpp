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
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef pair<double,double> ii;
typedef vector<ii> vii;

const double PI = acos(-1);

double angle(double x, double y, double r){
	double a = acos(x/r);
	return y<0?2*PI-a : a;
}

int main(){
	int tc,n,R;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d",&n,&R);
		vector<ii> v;
		int i,j;
		for(i=0;i<n;i++){
			int a,b,r;

			scanf("%d %d %d",&a,&b,&r);
			if(a == 0){
				double y = (1.0*R*R -1.0*r*r+1.0*b*b)/2/b;
				if(fabs(y) <= R){
					double x = R*R-y*y;
					double x1 = -sqrt(x);
					double x2 = sqrt(x);
					v.pb({x1, y});
					v.pb({x2, y});
					// cout<<i<<" "<<x1<<" "<<y<<" "<<x2<<" "<<y<<endl;
				}
				continue;
			}
			double C = (double)(R*R - r*r + a*a + b*b) / (2.0*(double)a);
			double determinant = (4.0*C*C*b*b)/(a*a) - 4.0*(C*C - R*R)*(1.0 + (double)b*b/(double)(a*a));
			if(determinant < 0){continue;}
			double y1 = (2.0 * C * (double)b/(double)a + sqrt(determinant)) / (2.0 * (1.0 + (double)b*b/(double)(a*a)));
			double y2 = (2.0 * C * (double)b/(double)a - sqrt(determinant)) / (2.0 * (1.0 + (double)b*b/(double)(a*a)));
			double x1 = C - ((double)b/(double)a)*y1;
			double x2 = C - ((double)b/(double)a)*y2;
			ii p = {x1, y1};
			ii q = {x2, y2};
			// cout<<i<<" "<<determinant<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
			// if(angle(x1, y1, R) > angle(x2, y2, R))
			// 	swap(p, q);
			v.pb(q);
			v.pb(p);
		}
		int ukuran = v.size();
		double ans = 0;
		for(i=0;i<ukuran;i++){
			for(j=i+1;j<ukuran;j++){
				ii a = v[i], b = v[j];
				// cout<<a.fi<<" "<<a.se<<" "<<b.fi<<" "<<b.se<<endl;
				ans = max(ans, hypot(a.first - b.first, a.second - b.second));
			}
		}
		printf("%.10lf\n",ans);
	}
	return 0;
};