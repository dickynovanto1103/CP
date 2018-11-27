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

const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;

ll counter[1000010];
int a[maxn];

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		memset(counter, 0, sizeof counter);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			counter[a[i]]++;
		}
		sort(a,a+n);
		ll ans = 1;
		for(i=n-1;i>=0;i-=2){
			int bil1 = a[i], bil2 = a[i-1];
			ll jawab;
			if(bil1 == bil2){
				jawab = (counter[bil1]*(counter[bil1]-1LL))/2LL;
				jawab %= mod;
			}else{
				jawab = counter[bil1]*counter[bil2];
				jawab %= mod;
			}
			ans *= jawab;
			ans %= mod;
			counter[bil1]--; counter[bil2]--;
		}
		printf("%lld\n",ans);
	}
	return 0;
};