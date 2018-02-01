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

const int maxn = 1e3 + 1;
ll memo[maxn][maxn];
int absis, ordinat;
ll solve(int a, int b){

}

int main(){
	int n,k,tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		ll total = 0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				absis = k;
				ordinat = j;
				ll ans = solve(0,i);
				total+=ans;
				printf("awal x: 0 awal y: %d absis: %d ordinat: %d jarak: %lld\n",i,absis,ordinat,ans);
			}
		}
		printf("total: %lld\n",total);
	}
	return 0;
};