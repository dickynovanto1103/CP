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

const int maxn = 1e5 + 5;
ll a[maxn];
ll listGcd[maxn], listGcdBalik[maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}

	if(n==1){printf("%lld\n",a[0]+1); return 0;}//agar tidak ada yang bisa membagi a[0]

	listGcd[0] = a[0];
	for(i=1;i<n;i++){
		listGcd[i] = __gcd(listGcd[i-1],a[i]);
	}
	listGcdBalik[n-1] = a[n-1];
	for(i=n-2;i>=0;i--){
		listGcdBalik[i] = __gcd(listGcdBalik[i+1],a[i]);
	}
	//cek 2 ujung
	//cek awal
	if(a[0]%listGcdBalik[1]!=0){printf("%lld\n",listGcdBalik[1]); return 0;}
	if(a[n-1]%listGcdBalik[n-2]!=0){printf("%lld\n",listGcdBalik[n-2]);}
	for(i=1;i<n-1;i++){
		ll ans = (__gcd(listGcd[i-1],listGcdBalik[i+1]));
		if(a[i]%ans!=0){printf("%lld\n",ans); return 0;}
	}
	return 0;
};