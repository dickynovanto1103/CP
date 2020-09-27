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
	ll n;
	scanf("%d",&tc);
	while(tc--){

		scanf("%lld",&n);
		int turn = 0;
		ll ans = 0;
		while(n){
			// printf("n: %lld\n",n);
			if(!turn){
				if(n % 2 == 1){
					n--;
					ans++;
				}else{
					ll bagi = n/2LL;
					if(bagi % 2 == 0){
						ll bagiLagi = bagi/2LL;
						if(bagiLagi == 1){
							n = bagi;
							ans+=bagi;
						}else{
							n--;
							ans++;	
						}
					}else{
						n = bagi;
						ans += bagi;
					}
				}
			}else{
				if(n % 2 == 1){
					n--;
				}else{
					ll bagi = n/2LL;
					if(bagi % 2 == 0){
						ll bagiLagi = bagi/2LL;
						if(bagiLagi == 1){
							n = bagi;
						}else{
							n--;
						}
					}else{
						n = bagi;
					}				}
			}
			turn = 1 - turn;
			// printf("ans skrg: %lld\n",ans);
		}
		printf("%lld\n",ans);
	}
	
	return 0;
};