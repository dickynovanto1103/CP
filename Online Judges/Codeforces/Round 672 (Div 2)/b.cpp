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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[100001];
	bool vis[100001];
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			vis[i] = false;
		}
		ll ans = 0;
		for(i=31;i>=0;i--){
			ll cnt = 0;
			for(j=0;j<n;j++){
				//cari angka 1
				if(vis[j]){continue;}
				
				if((1LL<<i) & a[j]) {
					cnt++;
					vis[j] = true;
				}
			}
			ans += (cnt * (cnt-1)) / 2LL;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
};