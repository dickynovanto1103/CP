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

int main(){
	int i,j;
	ll l,r,x,y;
	
	scanf("%lld %lld %lld %lld",&l,&r,&x,&y);
	ll kali = x*y;
	int cnt = 0;
	for(i=l;i<=r;i++){
		if(kali%i==0){
			ll a = i;
			ll b = kali/i;
			if(b>=l && b<=r){
				ll gcd = __gcd(a,b);
				ll lcm = a*(b/gcd);
				if(gcd == x && lcm == y){
					printf("%lld %lld\n",a,b);
					cnt++;
				}
			}
		}
		
	}
	printf("cnt: %d\n",cnt);
	return 0;
};