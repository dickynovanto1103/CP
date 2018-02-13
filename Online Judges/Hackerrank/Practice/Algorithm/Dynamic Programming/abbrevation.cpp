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

const int maxn = 1001;
int dp[maxn][maxn];
string kata1, kata2;

int solve(int n, int m){
	int i,j;
	if(n==-1){
		if(m==-1){return 1;}
		else{return 0;}
	}
	if(m==-1){return 1;}
	if(dp[n][m]!=-1){return dp[n][m];}
	if(kata1[n]==kata2[m]){return dp[n][m] = solve(n-1,m-1);}
	if((kata1[n]-32)==kata2[m]){return dp[n][m] = (solve(n-1,m-1) | solve(n-1,m));}
	return dp[n][m] = solve(n-1,m);
}
int lcs(string &kata1, string &kata2, int pjg1, int pjg2){
	int i,j;
	for(i=0;i<=pjg1;i++){
		for(j=0;j<=pjg2;j++){
			if(i==0 || j==0){dp[i][j] = 0;}
			else{
				if(kata1[i-1]==kata2[j-1]){dp[i][j] = dp[i-1][j-1] + 1;}
				else{dp[i][j] = max(dp[i-1][j], dp[i][j-1]);}
			}
		}
	}
	return dp[pjg1][pjg2];
}

int main(){
	int tc,i,j;
	int pjg1, pjg2;
	// printf("%d\n",'a');
	
	scanf("%d",&tc);
	while(tc--){
		cin>>kata1>>kata2;
		pjg1 = kata1.length(); pjg2 = kata2.length();
		string kata1Besar = "";
		int pjgKata1 = pjg1;
		for(i=0;i<pjgKata1;i++){
			if(kata1[i]<97){kata1Besar+=kata1[i];}
		}
		pjg1 = kata1Besar.length();
		// cout<<"kata1Besar: "<<kata1Besar<<" kata2: "<<kata2<<endl;
		int ans = lcs(kata1Besar,kata2, pjg1, pjg2);
		// printf("ans: %d\n",ans);
		if(ans!=pjg1){
			// printf("masuk sini");
			printf("NO\n"); continue;
		}
		// printf("pass\n");
		pjg1 = kata1.length();
		
		memset(dp,-1,sizeof dp);

		ans = solve(pjg1-1, pjg2-1);
		if(ans==0){printf("NO\n");}
		else{printf("YES\n");}
	}
	return 0;
};