#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int memo[101][25001], a[110];

int solve(int id, int remVal, int n){
	if(remVal==0 || id==n){return 0;}
	if(memo[id][remVal]!=-1){return memo[id][remVal];}
	if(remVal < a[id]){return memo[id][remVal] = solve(id+1, remVal,n);}
	else{
		return memo[id][remVal] = max(solve(id+1,remVal,n), a[id] + solve(id+1, remVal-a[id],n));
	}
}

int main() {
	int tc, i,j,n;
	scanf("%d",&tc);
	while(tc--){

		scanf("%d",&n);
		memset(memo,-1,sizeof memo);

		int total = 0;
		for(i=0;i<n;i++){scanf("%d",&a[i]); total+=a[i];}
		//pengganti memset
		/*for(i=0;i<n;i++){
			for(j=0;j<=total/2;j++){
				memo[i][j] = -1;
			}
		}*/
		//printf("total: %d\n",total);
		int jawab = solve(0,total/2,n);
		int jawabLain = total-jawab;
		//printf("jawab: %d\n",jawab);
		printf("%d\n",abs(jawab-jawabLain));
	}
	return 0;
}