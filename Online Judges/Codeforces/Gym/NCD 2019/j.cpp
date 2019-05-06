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

int a[100005];
int b[100005];
int cnt[100005];

int modu(int a, int mod){
	--a;
	a = (mod + (a % mod))%mod;
	++a;
	return a;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i=0;i<m;++i){
			scanf("%d", a+i);
		}
		for(int i=0;i<m;++i){
			scanf("%d", b+i);
		}
		memset(cnt, 0, (n+2) * sizeof(int));
		for(int i=0;i<m;++i){
			if(abs(b[i]) >= n){
				cnt[1]++;
				cnt[n+1]--;
				cnt[a[i]]++;
				cnt[a[i] + 1]--;
				continue;
			}
			int c = modu(a[i], n);
			int d = modu(a[i] + b[i], n);
			// cout<<i<<" "<<c<<" "<<d<<endl;
			if(b[i] < 0){
				swap(c, d);
			}
			if(c <= d){
				cnt[c]++;
				cnt[d+1]--;
			}
			else{
				cnt[c]++;
				cnt[n+1]--;
				cnt[1]++;
				cnt[d+1]--;
			}
		}
		for(int i=1;i<=n;++i)
			cnt[i] += cnt[i-1];
		int ma = *max_element(cnt+1, cnt+n+1);
		for(int i=1;i<=n;++i){
			if(cnt[i] == ma){
				printf("%d %d\n", i, ma);
				break;
			}
		}
	}
	return 0;
};