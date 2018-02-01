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

const int maxn = 5e4 + 4;
const ll mod = 1e9 + 7;

ll fac[maxn];

int main(){
	int tc,n,j;
	ll i;
	int a[maxn];
	int counter[maxn];

	fac[0] = 1;
	for(i=1;i<maxn;i++){
		fac[i] = (i*fac[i-1])%mod;
	}

	scanf("%d",&tc);
	while(tc--){
		memset(counter,0,sizeof counter);
		scanf("%d",&n);
		//printf("n: %d\n",n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			//printf("yang dibaca: %d\n",a[i]);
		}
		sort(a,a+n);
		bool valid = true;
		for(i=0;i<n;i++){
			if(a[i]>i){printf("0\n");valid = false; break;}
			counter[a[i]]++;
			//printf("counter[%d]jd: %d\n",a[i],counter[a[i]]);
		}
		if(!valid){continue;}

		ll cumulative[maxn];
		memset(cumulative,0,sizeof cumulative);
		
		bool done[maxn];
		memset(done,false,sizeof done);

		cumulative[0] = counter[0];	
		done[0] = true;
		for(i=1;i<n;i++){
			cumulative[i] = cumulative[i-1];
			if(!done[i]){
				//printf("counter[%d]: %d\n",i,counter[i]);
				cumulative[i]+=counter[i];
				done[i] = true;
			}
		}
		// printf("cumulative\n");
		// for(i=0;i<n;i++){
		// 	if(i){printf(" ");}
		// 	printf("%lld",cumulative[i]);
		// }
		// printf("\n");
		ll ans = 1;
		for(i=0;i<n;i++){
			
			ll banyak = cumulative[i];
			//printf("i: %lld banyak: %d\n",i,banyak);
			ans*=(banyak-i);
			ans%=mod;
			
		}
		printf("%lld\n",ans);
	}
	return 0;
};