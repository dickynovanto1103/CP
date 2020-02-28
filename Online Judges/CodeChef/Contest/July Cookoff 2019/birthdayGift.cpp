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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	string s;
	int cnt[2][maxn];

	while(tc--){
		cin>>s;
		int n = s.length();
		memset(cnt, 0, sizeof cnt);
		for(i=0;i<n;i++){
			int bil = s[i] - '0';
			cnt[bil][i] = 1;
			if(i){cnt[0][i] += cnt[0][i-1]; cnt[1][i] += cnt[1][i-1];}
		}
		ll ans = 0;
		for(i=1;i<=n;i++){
			int nol = i*i, satu = i;
			int tot = nol + satu;
			// printf("tot: %d\n",tot);
			if(tot > n){break;}
			for(j=0;j<n;j++){
				int next = j + tot - 1;
				// printf("j: %d next : %d\n",j, next);
				if(next >= n){break;}
				ll tot0 = cnt[0][next] - (j == 0 ? 0: cnt[0][j-1]);
				ll tot1 = cnt[1][next] - (j == 0 ? 0: cnt[1][j-1]);
				// printf("tot0: %d tot1: %d\n",tot0, tot1);
				if(tot0 == tot1*tot1){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
};