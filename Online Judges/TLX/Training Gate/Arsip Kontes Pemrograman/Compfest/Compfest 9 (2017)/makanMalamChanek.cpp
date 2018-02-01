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

const int maxn = 2e3 + 1;
int n,m;
int a[maxn], b[maxn];
ll memo[maxn][maxn][2];

int jarakMinimal(int pos1, int pos2){
	return min(abs(pos1-pos2), m-abs(pos1-pos2));
}

ll solve(int i, int j, int idx, int pos){
	if(i==n && j==n){return 0;}
	if(memo[i][j][idx]!=inf){return memo[i][j][idx];}
	if(i==n){//majukan j
		return memo[i][j][idx] = min(memo[i][j][idx],jarakMinimal(pos,b[j+1]) + solve(i,j+1,1, b[j+1]));
	}
	if(j==n){
		return memo[i][j][idx] = min(memo[i][j][idx],jarakMinimal(pos,a[i+1]) + solve(i+1,j,0, a[i+1]));
	}
	ll ans1 = jarakMinimal(pos,a[i+1])+ solve(i+1,j,0, a[i+1]);
	ll ans2 = jarakMinimal(pos,b[j+1]) + solve(i,j+1,1, b[j+1]);
	
	return memo[i][j][idx] = min(memo[i][j][idx],min(ans1,ans2));

}

int main(){
	int tc,i,j,k;
	
	scanf("%d",&tc);
	while(tc--){
		for(i=0;i<maxn;i++){
			for(j=0;j<maxn;j++){
				for(k=0;k<2;k++){
					memo[i][j][k] = inf;
				}
			}
		}
		scanf("%d %d",&m,&n);
		for(i=1;i<=n;i++){scanf("%d",&a[i]);}
		for(i=1;i<=n;i++){
			scanf("%d",&b[i]);
			b[i]+=m/2;
			b[i]%=m;
		}
	
		solve(0,0,0,0);

		printf("%lld\n",min(memo[0][0][0], memo[0][0][1]));
	}
	
	return 0;
};