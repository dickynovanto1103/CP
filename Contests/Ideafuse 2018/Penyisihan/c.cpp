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

vector<vii> AdjList;

ll dp[101][101][1003][2];
int n,m;

ll solve(int row, int col, int sisa, int dariKiri,  int idx) {
	if(row==n){
		if(sisa==0){return 0;}
		else{return inf;}
	}//sudah sampe
	if(AdjList[row].size()==2){//langsung naik
		if(dariKiri){
			return dp[row][col][sisa][dariKiri][idx] = 1 + solve(row+1, col, sisa, dariKiri, 0);
		}else{
			return dp[row][col][sisa][dariKiri][idx] = 1 + solve(row+1, col, sisa, dariKiri, AdjList[row+1].size() - 1);
		}
	}

	if(col==0 || col==(m+1)){
		if(dariKiri){
			//antara naik atau ke kanan
			ll ans1;
			if(col==0){
				ans1 = 1 + solve(row+1, col, sisa, dariKiri, 0);	
				int jarak = AdjList[row][idx+1].first - AdjList[row][idx].first;
				ll ans2 = jarak + solve(row, AdjList[row][idx+1].first, max(0, sisa-AdjList[row][idx].second), dariKiri, idx+1);
				dp[row][col][sisa][dariKiri][idx] = min(dp[row][col][sisa][dariKiri][idx], min(ans1,ans2));	
				
			}else{
				ans1 = 1 + solve(row+1, col, sisa, 0, AdjList[row+1].size()-1);
				dp[row][col][sisa][dariKiri][idx] = min(dp[row][col][sisa][dariKiri][idx], ans1);
			}
			
			return dp[row][col][sisa][dariKiri][idx];
			
		}else{
			//naik atau ke kiri
			ll ans1;
			if(col==0){
				ans1 = 1+solve(row+1, col, sisa, 1, 0);
				dp[row][col][sisa][dariKiri][idx] = min(dp[row][col][sisa][dariKiri][idx], ans1);
			}else{
				ans1 = 1+solve(row+1,col,sisa, 0, AdjList[row+1].size()-1);
				int jarak = AdjList[row][idx]
			}
			
		}

		dp[row][col][sisa][dariKiri][idx] = min(dp[row][col][sisa][dariKiri][idx], 1 + solve(row+1, col, sisa, dariKiri, 0));
	}else{
		//dibawa ke kanan / kiri paling deket siapa
		if(dariKiri){//bisa ke kanan dan ngambil candy waktu jalan ke kanan
			//mau ke kanan atau balik ke kiri dan naik
			int jarak = col;
			int jarak2 = AdjList[row][idx+1].first - AdjList[row][idx].first;

			return dp[row][col][sisa][dariKiri][idx] = min(dp[row][col][sisa][dariKiri][idx], min(jarak+1+solve(row+1, 0, sisa, dariKiri, 0), jarak2+solve(row, AdjList[row][idx+1], max(0, sisa - AdjList[row][idx].second))));
		}else{
			int jarak = m+1 - col
			int jarak2 = AdjList[row][idx].first - AdjList[row][idx-1].first;
			return dp[row][col][sisa][dariKiri][idx] = min(dp[row][col][sisa][dariKiri][idx], min(jarak+1+solve()))
		}
	}
	
	if(idx==AdjList[row].size()) {
		int ukuran = AdjList[row].size();
		int titikAwal = AdjList[row][ukuran-1];
		int titikAkhir = m+1;
		int jarak = titikAkhir - titikAwal;
		return dp[row][col][sisa][dariKiri] = jarak+1+solve(row+1, col, sisa, 0, AdjList[row+1].size()-1);
	}

	if(sisa == 0){
		if(col==0 || col==(m+1)){//langsung naik tangga aja
			return solve(row+1, col, sisa, dariKiri, idx);
		}else{
			return solve(row+1, col, sisa);
		}
	}

	
	
	
}

int main(){
	int i,j,c;
	scanf("%d %d %d",&n,&m,&c);

	AdjList.assign(n+2,vii());
	string kata[110];

	for(i=0;i<n;i++){
		cin>>kata[i];
	}
	reverse(kata,kata+n);
	memset(dp,-1,sizeof dp);
	for(i=0;i<n;i++){
		AdjList[i].pb(ii(0,0));
		for(j=1;j<=m;j++){
			char kar = kata[i][j];
			int bil = kar - '0';
			if(bil>0){AdjList[i].pb(ii(j,bil));}
		}
		AdjList[i].pb(ii(j,0));
	}
	ll ans = solve(0,0,c,0);

	return 0;
};