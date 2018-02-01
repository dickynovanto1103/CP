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

ll jarak(ll a, ll b, ll x, ll y){
	return max(abs(a-x),abs(b-y));
}

int main(){
	ll n,m,i,j;
	ll x1,y1,x2,y2;
	scanf("%lld %lld",&n,&m);
	scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
	//printf("%lld %lld %lld %lld\n",x1,y1,x2,y2);
	if(x1==x2 && y1==y2){printf("0\n"); return 0;}

	ll xOptimal[] = {1,1,1,x2,n,n,n,x2};
	ll yOptimal[] = {1,y2,m,m,m,y2,1,1};

	ll maks = -inf;
	ll ans = 0;
	for(i=0;i<8;i++){
		ll jarakVega = jarak(x1,y1,xOptimal[i],yOptimal[i]);
		ll jarakJuri = jarak(x2,y2,xOptimal[i],yOptimal[i]);

		if(jarakJuri<jarakVega){
			ans = max(ans,jarakVega);
		}
	}
	printf("%lld\n",ans+1);

	return 0;
};