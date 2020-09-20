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
	int tc,i,j;
	ll x;
	vi bisa;
	ll dua = 1;
	ll sum = 0;
	ll pref[1000];
	int idx = 0;
	for(ll i=1;i<=10000000000LL;){
		// printf("i: %d\n",i);
		sum += (i*(i+1))/2;
		// printf("%lld\n",sum);
		pref[++idx] = sum;
		if(sum >= (ll)inf*inf){
			// printf("halo i: %d\n",i);
			break;
		}
		dua*=2;
		i += dua;
	}
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld",&x);
		for(i=1;i<=1000;i++){
			// printf("x: %lld pref[%d]: %lld\n",x, i, pref[i]);
			if(x < pref[i]){
				printf("%d\n",i-1);
				break;
			}
		}
	}
	
	return 0;
};