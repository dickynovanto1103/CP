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

const int maxn = 3e5 + 5;

ll sum[maxn];
ll a[maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	

	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	if(n==1){printf("%lld\n",a[0]); return 0;}
	sort(a,a+n);
	for(i=0;i<n;i++){
		if(i==0){sum[i] = a[i];}
		else{sum[i] = a[i] + sum[i-1];}
	}	
	ll total = 0;
	ll sisa = sum[n-1];
	for(i=0;i<n-1;i++){
		total+=(2LL*sisa);
		sisa = sisa-a[i];
		//printf("total sementara: %lld\n",total);
		if(sisa==a[n-1]){break;}
		total-=(sisa);
		//printf("total sekarang: %lld\n",total);
	}
	printf("%lld\n",total);
	return 0;
};