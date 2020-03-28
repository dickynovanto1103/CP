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

const int maxn = 1e6 + 6;

int a[maxn];
int cnt[101];

void reset(int k) {
	for(int i=0;i<k;i++){
		cnt[i] = 0;
	}
}

void shiftLeft(int banyakShift, int k) {
	int temp[101],i;
	for(i=0;i<k;i++){
		int idxBaru = i - banyakShift;
		if(idxBaru < 0){
			idxBaru += k;
		}
		temp[idxBaru] = cnt[i];
	}
	for(i=0;i<k;i++){
		cnt[i] = temp[i];
	}
}

int main(){
	int tc,i,j,n,k;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		reset(k);
		ll ans = 0;
		int tot = 0;
		for(i=0;i<n;i++){
			tot += a[i];
			tot %= k;
			cnt[tot]++;
		}

		assert(cnt[0] >= 0);
		ans += cnt[0];
		for(i=0;i<n-1;i++){
			int mod = a[i] % k;
			cnt[mod]--;
			assert(cnt[mod] >= 0);

			shiftLeft(mod, k);
			assert(cnt[0] >= 0);

			ans += cnt[0];
		}
		printf("%lld\n",ans);
	}
	return 0;
};