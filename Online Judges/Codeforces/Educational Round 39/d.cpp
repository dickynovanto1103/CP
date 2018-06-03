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
int n,k;

vector<vi> AdjList;

int getNextIdx(int idx) {
	int tempIdx = idx+1;
	if(tempIdx==n){return tempIdx;}

	while(AdjList[tempIdx].size() == 0) {
		tempIdx++;
		if(tempIdx == n){break;}
	}
	return tempIdx;
}

bool sudah = false;

ll solve(int idx, int sisa, int idxAwal, int idxAkhir) {
	int i,j;
	if(sisa == 0){return 0;} //sudah habis..ga bs hapus course lg
	if(idx == n){//jika sudah melebihi batas..return 0

		return 0;
	}
	
	if(dp[idx][sisa]!=-1){
		if(!sudah) {
			printf("cek nilai dp idx: %d sisa: %d\n", idx, sisa);
			for(i=0;i<n;i++){
				for(j=0;j<k;j++){
					if(j){printf(" ");}
					printf("%lld",dp[i][j]);
				}
				printf("\n");
			}
			sudah = true;
		}
		return dp[idx][sisa];
	}

	
	//ada 3 pilihan..

	//skip ke idx setelah
	int tempIdx = getNextIdx(idx);
	
	if(tempIdx == n){
		dp[idx][sisa] = max(dp[idx][sisa], solve(tempIdx, sisa, 0, 0));
	}else{
		dp[idx][sisa] = max(dp[idx][sisa], solve(tempIdx, sisa, 0, AdjList[tempIdx].size()-1));
	}

	printf("idxAwal: %d idxAkhir: %d sisa: %d\n",idxAwal, idxAkhir, sisa);
	//hapus depan atau belakang dengan kondisi idxAwal <= idxAkhir
	if(idxAwal < idxAkhir) {
		int nilaiAwal = AdjList[idx][idxAwal], nilaiAkhir = AdjList[idx][idxAkhir], nilaiIdxMaju = AdjList[idx][idxAwal+1], nilaiIdxMundur = AdjList[idx][idxAkhir-1];
		int selisihMaju = nilaiIdxMaju - nilaiAwal;
		int selisihMundur = nilaiAkhir - nilaiIdxMundur;

		ll jawab1 = selisihMaju + solve(idx, sisa - 1, idxAwal+1, idxAkhir);
		ll jawab2 = selisihMundur + solve(idx, sisa - 1, idxAwal, idxAkhir-1);
		//lanjut indeks selanjutnya
		tempIdx = getNextIdx(idx);

		ll jawab3, jawab4;
		if(tempIdx==n){
			jawab3 = selisihMaju + solve(tempIdx, sisa-1, 0, 0);
			jawab4 = selisihMundur + solve(tempIdx, sisa-1, 0, 0);
		}else{
			// printf("sisa jadi: %d dan idxAwal jd: %d idxAkhir jd: %d\n",sisa-1, 0, AdjList[tempIdx].size()-1);
			jawab3 = selisihMaju + solve(tempIdx, sisa-1, 0, AdjList[tempIdx].size()-1);
			jawab4 = selisihMundur + solve(tempIdx, sisa-1, 0, AdjList[tempIdx].size()-1);
		}
		
		// printf("jawab1: %lld jawab2: %lld\n",jawab1,jawab2);
		dp[idx][sisa] = max(dp[idx][sisa], jawab3);
		//mundur
		dp[idx][sisa] = max(dp[idx][sisa], jawab4);
		dp[idx][sisa] = max(dp[idx][sisa], jawab1);
		//mundur
		dp[idx][sisa] = max(dp[idx][sisa], jawab2);
		
	}else if(idxAwal == idxAkhir) {
		//baik maju atau mundur
		//cari indeks setelahnya sampe size dari adjlist ga nol
		tempIdx = getNextIdx(idx);
		
		if(tempIdx == n){
			dp[idx][sisa] = max(dp[idx][sisa], solve(tempIdx, sisa, 0, 0));
			dp[idx][sisa] = max(dp[idx][sisa], 1 + solve(tempIdx, sisa - 1, 0, 0));
			
		}else{
			dp[idx][sisa] = max(dp[idx][sisa], solve(tempIdx, sisa, 0, AdjList[tempIdx].size()-1));
			dp[idx][sisa] = max(dp[idx][sisa], 1 + solve(tempIdx, sisa - 1, 0, AdjList[tempIdx].size()-1));
			
		}
	}

	return dp[idx][sisa];
}

int main(){
	int m,i,j;
	
	scanf("%d %d %d",&n,&m,&k);
	AdjList.assign(n+10,vi());
	for(i=0;i<n;i++){cin>>kata[i];}
	memset(dp,-1,sizeof dp);
	
	for(i=0;i<n;i++){//memset
		for(j=0;j<m;j++){
			if(kata[i][j] == '1'){AdjList[i].pb(j);}
		}
	}
	
	ll totalMasuk = 0;
	for(i=0;i<n;i++){
		if(AdjList[i].size() == 0){continue;}
		int waktu1 = AdjList[i][0];
		int waktu2 = AdjList[i][AdjList[i].size()-1];

		totalMasuk += (waktu2 - waktu1 + 1);
	}

	ll ans = solve(0, k, 0, AdjList[0].size()-1);

	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
			if(j){printf(" ");}
			printf("%lld",dp[i][j]);
		}
		printf("\n");
	}

	printf("%lld\n",totalMasuk - ans);
	return 0;
};