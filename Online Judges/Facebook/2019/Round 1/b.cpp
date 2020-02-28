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

const int maxn = 1e6 + 2;
const ll mod = 1e9 + 7;

char s[maxn];
int suff[maxn];
ll duaPangkat[maxn];

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	duaPangkat[0] = 1;
	for(i=1;i<maxn;i++){
		duaPangkat[i] = 2LL*duaPangkat[i-1];
		duaPangkat[i] %= mod;
	}
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		int n,k;
		scanf("%d %d",&n,&k);
		scanf("%s",s);
		int maks = 0, minim = 0, kurang = 0;
		for(i=n-1;i>=0;i--){
			suff[i] = (s[i] == 'A' ? -1 : 1);
			suff[i] += suff[i+1];
		}
		ll ans = 0;
		int score = 0;
		for(i=n-1;i>=0;i--){
			suff[i] -= kurang;
			if(s[i] == 'B') {
				if((suff[i] + maks) > k){
					ans += duaPangkat[i+1];
					ans %= mod;
					s[i] = 'A';
					kurang += 2;
					score++;
				}else{
					score--;
				}
			}else{
				score++;
			}

			maks = max(maks, score);
		}
		printf("%lld\n",ans);
	}
	return 0;
};