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

int memo[101][2001];
int a[101][2001];
int r,c;
ii pas[101];
int solve(int i, int j){
	if(i==r-1){return a[i][j];}
	if(memo[i][j]!=-1){return memo[i][j];}
	int ans = -inf;
	int idx1 = pas[i].first, idx2 = pas[i].second;
	int a,b;
	if(idx1!=j){
		a = a[i][j] + solve(i+1,idx1);
	}else{
		b = a[i][j] + solve(i+1, idx2);
	}
	
	return memo[i][j] = max(a,b);
}

int main() {
	int tc,i,j;
	
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&r,&c);
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(i=0;i<r;i++){
			int idx, maks = -inf;
			for(j=0;j<c;j++){
				if(a[i][j] > maks){maks = a[i][j]; idx = j; }
			}
			int idxMax2;
			maks = -inf;
			for(j=0;j<c;j++){
				if(j==idx){continue;}
				if(a[i][j] > maks){maks = a[i][j]; idxMax2 = j;}	
			}
			pas[i].first = idx; pas[i].second = idxMax2;
		}
		/*for(i=0;i<r;i++){

			printf("i: %d terbesar pertama idx: %d kedua: %d\n",i,pas[i].first,pas[i].second);
		}*/
		memset(memo,-1,sizeof memo);
		int ans = -inf;
		for(j=0;j<c;j++){
			ans = max(ans,solve(0,j));
		}
		printf("%d\n",ans);
	}
	return 0;
}