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

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		ll p,r,f;
		scanf("%lld %lld %lld",&p,&r,&f);
		// printf("%d %d %d\n",p,r,f);
		int ans = 0;
		if(r == 1){
			int selisih = f - p;
			ans = 1;
			ans += selisih / p;
		}else{
			while(p <= f){
				ans++;
				p*=r;
			}	
		}
		
		printf("%d\n",ans);
	}
	return 0;
};