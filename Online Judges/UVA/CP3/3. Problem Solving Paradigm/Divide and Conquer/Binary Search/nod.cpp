#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isprime[1000010];
int prime[170];
ll ans[1000010];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i+i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

ll numdiv(ll n){
	ll ans = 1, idx = 0, pf = prime[idx];
	while(pf*pf<=n){
		ll power = 0;
		while(n%pf==0){n/=pf; power++;}
		ans*=(power+1);
		pf = prime[++idx];
	}
	if(n!=1){ans*=2;}
	return ans;
}

int main() {
	memset(isprime,true,sizeof isprime);
	sieve(1000);
	int cnt = 0,i;
	
	for(i=0;i<=1000;i++){
		if(isprime[i]){prime[cnt] = i; cnt++;}
	}
	int n = cnt;
	ans[0] = 1;
	cnt=1;
	
	while(ans[cnt-1]<=1000000){
		ans[cnt] = ans[cnt-1]+numdiv(ans[cnt-1]);
		//if(ans[cnt]>900000){printf("ans[%d]: %d\n",cnt,ans[cnt]);}
		//printf("ans[%d]: %d\n",cnt,ans[cnt]);
		cnt++;
	}
	int tc,a,b;
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		scanf("%d %d",&a,&b);
		int idxawal = lower_bound(ans,ans+cnt,a) - ans;
		int idxakhir = upper_bound(ans,ans+cnt,b) - ans;
		printf("Case %d: %d\n",i,idxakhir-idxawal);
	}
	//printf("ans[%d]: %d\n",cnt,ans[cnt]);
	//for(i=0;i<cnt;i++){printf("%lld\n",ans[i]);}
	return 0;
}