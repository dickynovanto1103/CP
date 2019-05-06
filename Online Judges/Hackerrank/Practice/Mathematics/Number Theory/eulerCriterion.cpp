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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll modPow(ll a, ll b, ll mod) {
	if(b == 0){return 1;}
	else{
		if(b%2 == 1){return a*modPow(a,b-1, mod)%mod;}
		else{
			ll temp = modPow(a, b/2, mod);
			return temp*temp%mod;
		}
	}
}

int main(){
	int tc,a,m;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&a,&m);
		if(a == 0){printf("YES\n"); continue;}
		int phi = m-1;
		int d = __gcd(phi, 2);
		if(modPow(a, phi/d, m) == 1){printf("YES\n");}
		else{printf("NO\n");}
		// if(m != 2){
		// 	if(modPow(a,(m-1)/2, m) == 1){
		// 		printf("YES\n");
		// 	}else{
		// 		printf("NO\n");
		// 	}	
		// }else{
		// 	if(a == 0){printf("YES\n");}
		// 	else if(a==1){
		// 		printf("YES\n");
		// 	}else{
		// 		assert(false);
		// 	}
			
		// }
		
	}
	return 0;
};