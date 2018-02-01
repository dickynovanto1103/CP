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

int main(){
	int n,q,i,j;
	ll k;
	scanf("%d %d",&n,&q);
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	sort(a,a+n);
	ll gcd = 0;
	for(i=1;i<n;i++){
		gcd = __gcd(gcd,a[i]-a[0]);
	}
	while(q--){
		scanf("%lld",&k);
		printf("%lld\n",(ll)__gcd(a[0]+k,gcd));
	}

	return 0;
};