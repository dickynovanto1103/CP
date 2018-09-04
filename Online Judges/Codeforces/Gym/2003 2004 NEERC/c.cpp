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
#define fi first
#define se second


int n,i,j,t;
pair<double, double> center[1000];
double area[1000];
ii p[300];

bool ccw(ii a, ii b, ii c){
	return 	1LL*(b.fi - a.fi)*(c.se-a.se) - 1LL*(c.fi - a.fi)*(b.se - a.se) != 0;
}

int main(){
	freopen("cranksft.in", "r", stdin);
	freopen("cranksft.out", "w", stdout);
	scanf("%d", &n);
	double tot = 0;
	for(i=0;i<n;++i){
		scanf("%d", &t);
		ll x=0, y=0;
		ll ar = 0;
		std::vector<ii> ch;
		for(j=0;j<t;++j){
			int x, y;
			scanf("%d %d", &x, &y);
			while(1){
				int len = ch.size();
				if(len <= 1 ||ccw(ch[len-2], ch[len-1], {x, y})){
					ch.pb({x, y});
					break;
				}
				else{
					ch.pop_back();
				}
			}
		}
		while(1){
			int len = ch.size();
			if(len <=1 || ccw(ch[len-2], ch[len-1], ch[0])){
				ch.pb(ch.front());
				break;
			}
			else{
				ch.pop_back();
			}
		}
		// cout<<ch.size()<<endl;
		// for(ii a: ch){
		// 	printf("%d %d\n",a.first, a.second);
		// }
		t = ch.size()-1;
		for(j=0;j<t;++j){
			x += ((ll)ch[j].fi + (ll)ch[j+1].fi) * ((ll)ch[j].se*(ll)ch[j+1].fi - (ll)ch[j].fi * (ll)ch[j+1].se);
			y += ((ll)ch[j].se + (ll)ch[j+1].se) * ((ll)ch[j].se*(ll)ch[j+1].fi - (ll)ch[j].fi * (ll)ch[j+1].se);
			ar += ch[j].fi * ch[j+1].se - ch[j].se * ch[j+1].fi;
		}
		ar = llabs(ar);
		// printf("x: %lld y: %lld\n",x,y);
		area[i] = ar/2.0;
		// printf("area[%d]: %lf\n",i,area[i]);
		center[i] = {1.0*(double)x/(6.0*area[i]), 1.0*(double)y/(6.0*area[i])};
		
		tot += area[i];
	}
	double cx = 0, cy=0;
	for(i=0;i<n;++i){
		// cout<<area[i]<<" "<<center[i].fi<<" "<<center[i].se<<endl;
		cx += area[i]*center[i].fi/tot;
		cy += area[i]*center[i].se/tot;
	}
	printf("%.4lf %.4lf\n", cx, cy);
	return 0;
};