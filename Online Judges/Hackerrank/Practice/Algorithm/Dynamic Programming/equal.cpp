#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int coinValue[]={1,2,5};
ll memo[4][1001];

ll solve(int id, int v){
	if(v==0){return 0;}
	if(id==3 || v<0){return inf;}
	if(memo[id][v]!=-1){return memo[id][v];}
	return memo[id][v] = min(solve(id+1,v), 1+solve(id,v-coinValue[id]));
}


int main() {
	int tc,i,j,a[10010];
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		int minim = inf;
		for(i=0;i<n;i++){scanf("%d",&a[i]); minim = min(minim, a[i]);}
		ll ans = (ll)inf*(ll)1000;
		
		//int batasbawah = max(0,minim-5);
		memset(memo,-1,sizeof memo);
		for(i=minim;i>=minim-4;i--){//batas

			ll sum = 0;
			//printf("i: %d\n",i);
			for(j=0;j<n;j++){
				sum+=solve(0,a[j]-i);
				//printf("dengan a[%d] = %d sum jadi: %d\n",j,a[j],sum);
			}
			ans = min(ans,sum);
			//printf("ans: %d\n",ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}