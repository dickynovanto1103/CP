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
typedef pair<int,ii> iii;
typedef vector<ii> vii;


int main(){
	ll n,i,j;
	scanf("%lld",&n);
	ll freq[100], total[100];
	for(i=0;i<=46;i++){
		freq[i] = (1LL<<(i+1LL)) - 1LL;
		if(i==0){total[i]=1;}
		else{
			total[i] = total[i-1]*2LL + (1LL<<(i));	
		}
	}
	int idx = lower_bound(freq,freq+46,n) - freq;
	printf("idx: %d\n",idx);
	// n--;
	if(freq[idx] == n){
		if(n<=3){printf("%lld\n",3LL); return 0;}
		else{printf("%lld\n",total[idx]);return 0;}
		// n--;
	}
	
		n--;
		printf("n: %lld\n",n);
		ll ans = 0;
		for(i=idx;i>=0;i--){
			while(n>=freq[i]){
				n-=freq[i];
				ans+=total[i];
				printf("n jd: %lld\n",n);
				printf("ans jd :%lld\n",ans);
				if(n==0){break;}
			}
			if(n==0){break;}
		}
		printf("%lld\n",ans);
	

	
	return 0;
};