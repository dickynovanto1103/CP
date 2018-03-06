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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1001;
ll a[maxn];
vi arrBaru;
ll sum[maxn*maxn];

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		arrBaru.clear();
		memset(sum,0,sizeof sum);
		int q;
		scanf("%d %d",&n,&q);
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}

		for(i=0;i<n;i++){
			ll sum = a[i];
			// printf("yang dipush: %lld\n",sum);
			arrBaru.pb(sum);
			for(j=i+1;j<n;j++){
				sum+=a[j];
				// printf("yang dipush: %lld\n",sum);
				arrBaru.pb(sum);
			}
		}
		sort(arrBaru.begin(), arrBaru.end());
		// printf("arrBaru\n");
		// for(i=0;i<arrBaru.size();i++){
		// 	if(i){printf(" ");}
		// 	printf("%lld",arrBaru[i]);
		// }
		// printf("\n");
		sum[0] = arrBaru[0];
		for(i=1;i<arrBaru.size();i++){
			sum[i] = sum[i-1] + arrBaru[i];

		}
		// for(i=0;i<arrBaru.size();i++){
		// 	if(i){printf(" ");}
		// 	printf("%lld",sum[i]);
		// }
		// printf("\n");
		printf("Case #%d:\n",tt);
		for(i=1;i<=q;i++){
			int l,r;
			scanf("%d %d",&l,&r);
			l--; r--;
			// printf("query: %d\n",i);
			if(l==0){printf("%lld\n",sum[r]);}
			else{printf("%lld\n",(sum[r]-sum[l-1]));}
			//printf("%lld\n",sum[r] - sum[l-1]);
		}

	}
	

	return 0;
};