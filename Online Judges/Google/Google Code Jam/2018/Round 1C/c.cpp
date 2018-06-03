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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;
ll load[maxn];
ll w[maxn];
ii pas[maxn];

bool isKuat(int awal, int akhir) {
	for(int i=awal;i<=akhir;i++){
		if((w[i] * 6LL) < load[i]){return false;}
	}
	return true;
}

bool cmp(ii a, ii b){
	if(a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main(){
	int tc,i,j,n;
	
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%lld",&w[i]);}
		reverse(w,w+n);
		
		for(i=0;i<n;i++){
			pas[i] = ii(w[i], i);
		}
		// sort(pas,pas+n);
		int ans = 1;
		for(i=0;i<n;i++){
			ll load = 0;
			int curIdx = pas[i].second;
			ll benchmark = pas[i].first;
			ll batas = benchmark*6LL;
			int cnt = 1;
			for(j=i+1;j<n;j++){
				if(pas[j].second > curIdx){
					if((load+pas[j].first) <= batas){
						load+=pas[j].first;
						curIdx = pas[j].second;
						cnt++;
					}
				}
			}
			ans = max(ans,cnt);
		}

		printf("%d\n",ans);
	}
	return 0;
};