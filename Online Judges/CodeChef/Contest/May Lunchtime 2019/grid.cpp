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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		ll n,m,k;
		scanf("%lld %lld %lld",&n,&m,&k);
		if(__gcd(n,k) == 1 && __gcd(m,k) == 1){
			printf("%lld\n",n*m);
		}else{
			printf("-1\n");
		}
	}
	return 0;
};