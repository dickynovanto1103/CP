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
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<long double,long double> dd;
typedef vector<ii> vii;
typedef vector<dd> vdd;

void solve(){
	int n,q;
	
	while(scanf("%d%d",&n,&q) != EOF) {
		vdd coor;
		vector<long double> pref(n), prefXCenter(n), prefYCenter(n);
		for(int i=0;i<n;i++){
			long double x,y;
			scanf("%Lf%Lf",&x,&y);

			coor.pb(dd(x,y));
			// printf("x: %lf y: %lf\n", x,y);
		}

		for(int i=0;i<n;i++){
			// printf("i: %d\n", i);
			int next = (i+1) % n;
			
			long double kali = coor[i].first*coor[next].second - coor[next].first*coor[i].second;
			pref[i] = kali;
			// printf("kali: %lf\n", kali);

			long double xCenterKali = (coor[i].first + coor[next].first)*(kali);
			long double yCenterKali = (coor[i].second + coor[next].second)*(kali);

			prefXCenter[i] = xCenterKali;
			prefYCenter[i] = yCenterKali;
			
			if(i > 0){
				pref[i] += pref[i-1];
				prefXCenter[i] += prefXCenter[i-1];
				prefYCenter[i] += prefYCenter[i-1];
			}
		}
		// puts("halo");

		ll totalArea = pref[n-1];

		while(q--){
			int idx1, idx2;
			scanf("%d%d",&idx1,&idx2);
			idx1--;idx2--;

			//find area first
			if(idx1 > idx2) {
				assert(idx1 > 0);
				long double shoelace = (coor[idx2].first*coor[idx1].second - coor[idx1].first*coor[idx2].second);
				long double area = fabs((pref[n-1] - pref[idx1 - 1]) + (idx2 == 0 ? 0 : pref[idx2 - 1]) + shoelace) / 2.0;
				long double centerXKaliFromNewLine = (coor[idx1].first + coor[idx2].first)*(shoelace);
				long double centerYKaliFromNewLine = (coor[idx1].second + coor[idx2].second)*(shoelace);
				
				long double centerX = (prefXCenter[n-1] - prefXCenter[idx1-1] + (idx2 == 0 ? 0: prefXCenter[idx2 - 1]) + centerXKaliFromNewLine)/ (6.0 * area);
				long double centerY = (prefYCenter[n-1] - prefYCenter[idx1-1] + (idx2 == 0 ? 0: prefYCenter[idx2 - 1]) + centerYKaliFromNewLine)/ (6.0 * area);
				printf("%.9Lf %.9Lf\n", centerX, centerY);
			}else{
				assert(idx2 > 0);
				long double shoelace = (coor[idx2].first*coor[idx1].second - coor[idx1].first*coor[idx2].second);
				long double area = fabs(pref[idx2 - 1] - (idx1 == 0 ? 0 : pref[idx1 - 1]) + shoelace) / 2.0;
				long double centerXKaliFromNewLine = (coor[idx1].first + coor[idx2].first)*(shoelace);
				long double centerYKaliFromNewLine = (coor[idx1].second + coor[idx2].second)*(shoelace);
				
				long double centerX = (prefXCenter[idx2-1] - (idx1 == 0 ? 0 : prefXCenter[idx1 - 1]) + centerXKaliFromNewLine)/ (6.0 * area);
				long double centerY = (prefYCenter[idx2-1] - (idx1 == 0 ? 0 : prefYCenter[idx1 - 1]) + centerYKaliFromNewLine)/ (6.0 * area);
				printf("%.9Lf %.9Lf\n", centerX, centerY);
			}
		}

		puts("");
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};