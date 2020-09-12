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

int prime[] = {2, 3, 5,7,11,13,17,23,29,31,37, 41, 43};

void factorize(ll a) {
	ll pf_idx = 0;
	ll pf = prime[pf_idx];
	while(pf*pf <= a) {
		int cnt = 0;
		while(a % pf == 0){
			a /= pf;
			cnt++;
		}
		if(cnt > 0){
			printf("%lld^%d x ",pf, cnt);
		}
		pf = prime[++pf_idx];
	}
	if(a > 1){
		printf("%lld^%d\n",a, 1);
	}
	printf("\n");
}

int main(){
	int n,i,j;
	int a[10];
	scanf("%d",&n);
	ll kali = 1;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		kali *= a[i];
	}
	ll ans = 1;
	ll mod = 1e9 + 7;
	printf("kali: %lld\n",kali);
	for(i=0;i<n;i++){
		ll temp = kali;
		int cnt = 0;
		while(temp % a[i] == 0){
			temp /= a[i];
			cnt++;
		}
		printf("kontribusi a[%d]: %d adalah %d\n",i, a[i], cnt);
	}
	factorize(kali);
	for(ll i=1;i*i<=kali;i++){
		if(kali % i == 0){
			ll bil1 = kali / i;
			ll bil2 = i;
			if(bil1 == bil2){
				ans *= bil1;
				ans %= mod;
			}else{
				ans *= bil1; ans %= mod;
				ans *= bil2; ans %= mod;
			}
			printf("bil1: %lld bil2: %lld\n",bil1, bil2);
		}
	}
	printf("ans; %lld\n",ans);
	return 0;
};