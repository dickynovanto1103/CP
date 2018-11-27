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

const int maxn = 2e5 + 5;

int main(){
	int n,i,j;
	ll t;
	ll a[maxn];
	scanf("%d %lld",&n,&t);
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	
	ll ans = 0;
	while(true){
		ll cnt = 0;
		ll total = 0;
		for(i=0;i<n;i++){
			if(a[i] <= t){
				t-=a[i];
				total+=a[i];
				cnt++;
			}
		}
		if(total == 0){break;}
		ans += cnt;
		ll loop = t / total;
		t -= (loop*total);
		ans += (loop*cnt);
		// printf("ans: %lld\n",ans);
	}
	printf("%lld\n",ans);
	return 0;
};