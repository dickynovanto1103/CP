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
typedef vector<ii> vii;

int main(){
	int tc, n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		string s;
		cin>>s;
		int tuj[202];
		for(int i=1;i<=n;i++){
			int bil;
			scanf("%d",&bil);
			tuj[i] = bil;
		}

		bool vis[202];
		memset(vis, false, sizeof vis);

		vi v;
		for(int i=1;i<=n;i++){

			if(vis[i]) continue;
			int awal = i;
			int now = i;
			int step = 0;
			string st;
			vi indeks;
			do{
				st += s[now-1];
				indeks.pb(now);
				vis[now] = true;
				now = tuj[now];
				step++;
			}while(now != awal);

			string stAwal = st;
			string stNow = stAwal;
			int realStep = 0;;
			do {
				char back = stNow.back(); stNow.pop_back();
				stNow = back + stNow;
				realStep++;
			}while(stNow != stAwal);
			
			v.pb(realStep);
		}

		ll kpk = 1;
		for(int i=0;i<v.size();i++){
			// printf("v[%d]: %d\n", i, v[i]);
			ll cur = kpk;
			ll nilaiBaru = (ll)v[i] * cur;
			nilaiBaru /= __gcd((ll)v[i], cur);
			kpk = nilaiBaru;
		}

		printf("%lld\n", kpk);
	}
	
	return 0;
};