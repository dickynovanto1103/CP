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

int cap[1010], wei[1010],n,memo[1001][3001];

int solve(int id, int w){
	if(id==n){return 0;}
	if(w<wei[id]){return solve(id+1,w);}
	if(memo[id][w]!=-1){return memo[id][w];}
	return memo[id][w] = max(solve(id+1,w), 1+solve(id+1,min(w-wei[id],cap[id])));
}

int main() {
	int i;
	while(scanf("%d",&n),n){

		for(i=0;i<n;i++){
			scanf("%d %d",&wei[i],&cap[i]);
		}
		memset(memo,-1,sizeof memo);
		int maks = 1,curmax = -1;
		for(i=0;i<n;i++){
			int maksKardus = n-i;
			if(maksKardus < maks){break;}//sudah ga mungkin melebihi jawaban maksimal, keluar dari loop
			if(cap[i]<=curmax){continue;}//kalo kapasitas selanjutnya lebih kecil atau sama dengan
			else{curmax = cap[i];}
			int ans = solve(i+1,cap[i])+1;
			maks = max(maks,ans);
		}
		printf("%d\n",maks);
	}
	return 0;
}