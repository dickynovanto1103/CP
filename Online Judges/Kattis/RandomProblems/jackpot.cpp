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

ll countLCM(ll a, ll b){
	return a/(__gcd(a,b))*b;
}

int main(){
	int n,i,j;
	ll lcm = 0;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		bool isValid = true;
		lcm = 1;
		for(i=0;i<n;i++){
			ll bil;
			scanf("%lld",&bil);
			lcm = countLCM(lcm, bil);
			if(lcm > inf){isValid = false;}
		}	
		if(isValid){printf("%lld\n",lcm);}
		else{printf("More than a billion.\n");}
	}
	
	return 0;
};