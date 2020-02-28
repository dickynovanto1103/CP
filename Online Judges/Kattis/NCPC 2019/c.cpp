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

int main(){
	int n,m,i,j;
	ll a;
	scanf("%d %d %lld",&n,&m,&a);
	if(a % n == 0 || a % m == 0){printf("1\n");}
	else{
		//n*berapa supaya =a
		int ans = 3;
		if(a < n || a < m){ans = min(ans,2);}
		ll x = a/(ll)n;
		// printf("x: %lld\n",x);
		if(x == m-1){
			ans = min(ans, 2);
		}
		x = a/(ll)m;
		// printf("%s\n", );
		if(x == n-1){
			ans = min(ans, 2);
		}
		printf("%d\n",ans);
	}
	return 0;
};