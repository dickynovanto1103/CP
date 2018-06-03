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

const int maxn = 510;
string kata[maxn];
ll dp[maxn][maxn];
int n;

vector<vi> AdjList;

ll solve(int idx, int sisa, int idxAwal, int idxAkhir) {
	if(idx == n){
		return 0;
	}
	if(sisa == 0){return 0;} //sudah habis..ga bs hapus jam lg
	if(dp[idx][sisa]!=-1){return dp[idx][sisa];}
	//ada 3 pilihan..
	//skip ke idx setelah
	int tempIdx = idx+1;
	while(AdjList[tempIdx].size() == 0) {
		if(tempIdx == n){break;}
		tempIdx++;
		if(tempIdx == n){break;}
	}

	ll ans = 0;
	if(tempIdx == n){ans = max(ans, solve(tempIdx, sisa, 0, 0));}
	else{ans = max(ans, solve(tempIdx, sisa, 0, AdjList[tempIdx].size()-1));}

	//hapus depan atau belakang dengan kondisi idxAwal <= idxAkhir
	if(idxAwal <= idxAkhir) {
		if(idxAwal == idxAkhir) {
			//baik maju atau mundur
			//cari indeks setelahnya sampe size dari adjlist ga nol
			tempIdx = idx+1;
			while(AdjList[tempIdx].size() == 0) {
				if(tempIdx == n){break;}
				tempIdx++;
				if(tempIdx == n){break;}
			}
			if(tempIdx == n){ans = max(ans, 1 + solve(tempIdx, sisa - 1, 0, 0));}
			else{ans = max(ans, 1 + solve(tempIdx, sisa - 1, 0, AdjList[tempIdx].size()-1));}
		}else{

			int nilaiAwal = AdjList[idx][idxAwal], nilaiAkhir = AdjList[idx][idxAkhir], nilaiIdxMaju = AdjList[idx][idxAwal+1], nilaiIdxMundur = AdjList[idx][idxAkhir-1];
			int selisihMaju = nilaiIdxMaju - nilaiAwal;
			int selisihMundur = nilaiAkhir - nilaiIdxMundur;
			// printf("idx: %d\n",idx);
			printf("idxAwal: %d idxAkhir: %d nilaiAwal: %d nilaiAkhir: %d nilaiIdxMaju: %d nilaiIdxMundur: %d\n",idxAwal, idxAkhir, nilaiAwal, nilaiAkhir, nilaiIdxMaju, nilaiIdxMundur);
			printf("nilai: %d\n", selisihMaju + solve(idx, ));
			//maju
			ans = max(ans, selisihMaju + solve(idx, sisa - 1, idxAwal+1, idxAkhir));
			//mundur
			ans = max(ans, selisihMundur + solve(idx, sisa - 1, idxAwal, idxAkhir-1));
		}
		
	}
	return dp[idx][sisa] = max(dp[idx][sisa], ans);
}

int main(){
	int m,k,i,j;
	
	scanf("%d %d %d",&n,&m,&k);
	AdjList.assign(n+10,vi());
	for(i=0;i<n;i++){cin>>kata[i];}
	memset(dp,-1,sizeof dp);
	AdjList.clear();
	for(i=0;i<n;i++){//memset
		for(j=0;j<m;j++){
			if(kata[i][j] == '1'){AdjList[i].pb(j);}
		}
	}
	AdjList[n].pb(1);//dummy
	AdjList[n+1].pb(1);
	
	ll totalMasuk = 0;
	for(i=0;i<n;i++){
		if(AdjList[i].size() == 0){continue;}
		int waktu1 = AdjList[i][0];
		int waktu2 = AdjList[i][AdjList[i].size()-1];

		totalMasuk += (waktu2 - waktu1 + 1);
	}

	ll ans = solve(0, k, 0, AdjList[0].size()-1);
	for(i=0;i<n;i++){
		for(j=0;j<=k;j++){
			if(j){printf(" ");}
			printf("%lld",dp[i][j]);
		}
		printf("\n");
	}

	printf("%lld\n",totalMasuk - ans);
	return 0;
};