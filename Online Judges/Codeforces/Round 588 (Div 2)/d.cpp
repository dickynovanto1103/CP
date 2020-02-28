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
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

set<int> s;

void pushToVector(vi& v, ll bil) {
	if(!v.empty()){
		if(v.back() != bil)
			v.pb(bil);
	}else{
		v.pb(bil);
	}
	for(int i=0;i<60;i++){
		if((1LL<<i) & bil){
			s.insert(i);
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	ii a[7070];
	for(i=0;i<n;i++){
		scanf("%lld",&a[i].first);
	}
	for(i=0;i<n;i++){
		scanf("%lld",&a[i].second);
	}
	sort(a,a+n);
	ll cur = -1;
	ll ans = 0;
	ll maks = 0;
	bool ada = false;
	for(i=0;i<n-1;i++){
		if(a[i].first == a[i+1].first){
			ada = true;
			break;
		}
	}

	a[n] = ii(-1,0);

	bool mark[65];
	memset(mark, true, sizeof mark);

	if(ada){
		ll ans = 0;
		vi v;
		bool processSama = false;
		bool vis[7001];
		memset(vis, false, sizeof vis);
		for(i=0;i<n;i++){
			ll bil = a[i].first;
			ll next = a[i+1].first;
			if(bil == next) {
				processSama = true;
				ans += a[i].second;
				vis[i] = true;
				pushToVector(v, bil);
			}else{
				if(processSama) {
					ans += a[i].second;
					vis[i] = true;
					pushToVector(v, bil);
					processSama = false;
				}
			}
		}

		for(i=0;i<n;i++){
			ll bil = a[i].first;

			if(!vis[i]){
				// printf("i: %d bil: %lld\n",i,bil);
				int ukuran = v.size();
				bool temp[ukuran+1];
				memset(temp, false, sizeof temp);
				int cnt = ukuran;
				for(j=0;j<60;j++){
					if(((1LL<<j) & bil)) {
						for(int k=0;k<ukuran;k++){
							if(!((1LL<<j) & v[k])){
								if(!temp[k]){
									temp[k] = true;
									cnt--;
									if(cnt == 0){break;}
								}
							}
						}
					}
					if(cnt == 0){break;}
				}
				if(cnt!=0){
					ans += a[i].second;
				}
			}
		}
		
		printf("%lld\n",ans);
	}else{
		printf("0\n");
	}
	
	return 0;
};