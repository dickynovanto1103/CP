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

int banyakDigit(ll a){
	if(a==0){return 1;}
	int cnt = 0;
	while(a>0){
		a/=10;
		cnt++;
	}
	return cnt;
}

ll a[1010], b[1010], listGcd[1000010];

int main(){
	int n,m,i,j;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%lld",&b[i]);
	}
	int idx = 0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			int bilGcd = __gcd(a[i],b[j]);
			if(bilGcd!=1){
				listGcd[idx] = bilGcd;
				idx++;
				a[i]/=bilGcd;
				b[j]/=bilGcd;
			}
		}
	}

	ll ans = 1;
	bool lebih = false;
	for(i=0;i<idx;i++){
		ans*=listGcd[i];
		if(ans>=(ll)inf){
			lebih = true;
			ans%=(ll)inf;
		}
	}
	if(lebih){
		int digit = banyakDigit(ans);
		for(i=0;i<(9-digit);i++){
			printf("0");
		}
	}
	
	printf("%lld\n",ans);
	return 0;
};