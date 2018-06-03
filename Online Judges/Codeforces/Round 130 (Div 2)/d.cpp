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

const int maxn = 55;

int main(){
	int n,i;
	ll a[maxn], price[10];
	ll counter[10];
	memset(counter,0,sizeof counter);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=0;i<5;i++){scanf("%lld",&price[i]);}
	ll uang = 0;
	for(i=0;i<n;i++){
		uang+=a[i];
		while(true){
			int idx = lower_bound(price, price+5, uang) - price;
			if(price[idx] > uang){idx--;}
			if(idx == -1){break;}
			ll banyak = uang / price[idx];
			counter[idx]+=banyak;
			uang = uang - (banyak*price[idx]);
		}
	}
	for(i=0;i<5;i++){
		if(i){printf(" ");}
		printf("%lld",counter[i]);
	}
	printf("\n");
	printf("%lld\n",uang);
	return 0;
};