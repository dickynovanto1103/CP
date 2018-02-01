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

int waktu[55][55], harga[55][55], n;
ii memo[55][1001];

ii solve(int cur, int timeLeft){
	if(timeLeft<0){return ii(inf,inf);}
	if(cur==n-1){return ii(0,0);}
	if(memo[cur][timeLeft]!=ii(-1,-1)){return memo[cur][timeLeft];}
	ii ans = ii(inf,inf);
	//printf("ans.first jd: %d ans.second jd: %d\n",ans.first,ans.second);
	int x;
	//printf("n: %d\n",n);
	for(x=0;x<n;x++){
		//printf("x: %d\n", x);
		if(cur!=x){
			//printf("masuk sini\n");
			ii temp = solve(x,timeLeft - waktu[cur][x]);
			//printf("temp.first jd: %d temp.second jd: %d\n",temp.first,temp.second);
			if(temp.first + harga[cur][x] < ans.first){

				ans.first = temp.first + harga[cur][x];
				ans.second = temp.second + waktu[cur][x];
				//printf("ans.first jd: %d ans.second jd: %d\n",ans.first,ans.second);
			}
		}
	}
	return memo[cur][timeLeft] = ans;
}

int main() {
	int t,i,j;
	while(scanf("%d %d",&n,&t),(n||t)){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&waktu[i][j]);
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&harga[i][j]);
			}
		}

		//first untuk biaya, second untuk waktu
		//ans.first = inf, ans.second = inf;
		/*for(i=0;i<51;i++){
			for(j=0;j<=1000;j++){
				memo[i][j].first = -1; memo[i][j].second = -1;
			}
		}*/
		/*printf("n: %d t: %d\n",n,t);
		printf("waktu:\n");
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j){printf(" ");}
				printf("%d",waktu[i][j]);
			}
			printf("\n");
		}
		printf("harga:\n");
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j){printf(" ");}
				printf("%d",harga[i][j]);
			}
			printf("\n");
		}*/
		memset(memo,-1,sizeof memo);
		ii ans;
		ans = solve(0,t);
		printf("%d %d\n",ans.first,ans.second);
	}
	return 0;
}