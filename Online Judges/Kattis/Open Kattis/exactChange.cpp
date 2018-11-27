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

int dp[101][10001];
int a[101],n;

int solve(int idx, int biaya){
	if(idx == n){
		if(biaya<=0){return 0;}
		else{return inf;}	
	}
	if(biaya <= 0){return 0;}

	
	if(dp[idx][biaya]!=-1){return dp[idx][biaya];}
	int minim = min(solve(idx+1, biaya), a[idx] + solve(idx+1, biaya-a[idx]));
	return dp[idx][biaya] = minim;
}
int jumlahKoin[101][20001];

int solveJumlahKoin(int idx, int biaya){
	if(idx == n){
		if(biaya==0){return 0;}
		else{return inf;}
	}
	if(biaya == 0){return 0;}
	if(jumlahKoin[idx][biaya]!=-1){return jumlahKoin[idx][biaya];}
	if(a[idx] > biaya){return jumlahKoin[idx][biaya] = solveJumlahKoin(idx+1, biaya);}
	int minim = min(solveJumlahKoin(idx+1, biaya), 1 + solveJumlahKoin(idx+1, biaya - a[idx]));
	return jumlahKoin[idx][biaya] = minim;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int biaya;
		scanf("%d",&biaya);
		scanf("%d",&n);
		memset(dp, -1, sizeof dp);
		memset(jumlahKoin, -1, sizeof jumlahKoin);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		int biayaMin = solve(0, biaya);
		int banyakKoin = solveJumlahKoin(0, biayaMin);
		printf("%d %d\n",biayaMin, banyakKoin);
	}
	return 0;
};