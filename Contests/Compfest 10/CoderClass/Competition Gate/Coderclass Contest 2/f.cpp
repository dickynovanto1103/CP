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
typedef pair<ii,ii> iiii;

const int maxn = 1e2 + 2;

vector<vii> AdjList;
bool isVisited[maxn];

struct pasangan{
	int jumlahMandor, jumlahKuli, jumlahSekretaris, jumlahBerat;	
};

vector<pasangan> listPas;
string arrRole[maxn];
int arrKontribusi[maxn];

int jumlahMandor, jumlahKuli, jumlahSekretaris, jumlahBerat;
int totalDaerah;

void dfs(int node){
	if(arrRole[node] == "mandor"){
		jumlahMandor++;
	}else if(arrRole[node] == "kuli"){
		jumlahKuli++;
	}else{
		jumlahSekretaris++;
	}
	// printf("node: %d\n",node);

	isVisited[node] = true;
	jumlahBerat+=arrKontribusi[node];
	for(int i=0;i<AdjList[node].size();i++){
		ii v = AdjList[node][i];
		int tetangga = v.first, berat = v.second;
		// printf("node: %d tetangga; %d i: %d\n",node, tetangga,i);
		if(!isVisited[tetangga]){
			jumlahBerat+=berat;
			dfs(tetangga);
		}
	}
}

ll dp[maxn][16][16][16];
bool foundSolution;

ll solve(int idx, int sisaK, int sisaM, int sisaS){

	if(sisaK < 0 || sisaM < 0 || sisaS < 0){
		return -inf;
	}
	if(idx == totalDaerah){
		if(sisaK == 0 && sisaM == 0 && sisaS == 0){
			foundSolution = true;
			return 0;
		}
		else{return -inf;}
	}

	if(dp[idx][sisaK][sisaM][sisaS] != -1){return dp[idx][sisaK][sisaM][sisaS];}
	// printf("idx: %d\n",idx);
	ll ans = -inf;
	int banyakKuli = listPas[idx].jumlahKuli;
	int banyakMandor = listPas[idx].jumlahMandor;
	int banyakSekretaris = listPas[idx].jumlahSekretaris;

	ll jawab1 = -inf;
	if(sisaK >= banyakKuli && sisaM >= banyakMandor && sisaS >= banyakSekretaris){
		jawab1 = listPas[idx].jumlahBerat + solve(idx+1,sisaK - banyakKuli, sisaM - banyakMandor, sisaS - banyakSekretaris);
	}

	ll jawab2 = solve(idx+1,sisaK, sisaM, sisaS);
	ans = max(ans, max(jawab1, jawab2));
	return dp[idx][sisaK][sisaM][sisaS] = ans;
}

int main(){
	int i,j;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n,p,k,m,s;
		scanf("%d %d %d %d %d",&n,&p,&k,&m,&s);
		AdjList.assign(n+1,vii());
		string role;
		int nilai;

		int cntMandor = 0, cntSekretaris = 0, cntKuli = 0;

		for(i=1;i<=n;i++){

			cin>>role>>nilai;
			arrRole[i] = role;
			arrKontribusi[i] = nilai;
			if(role == "mandor"){
				cntMandor++;
			}else if(role == "kuli"){
				cntKuli++;
			}else{
				cntSekretaris++;
			}
		}

		for(i=0;i<p;i++){
			int a,b,w;
			scanf("%d %d %d",&a,&b,&w);
			AdjList[a].pb(ii(b,w));AdjList[b].pb(ii(a,w));
		}

		if(cntMandor < m || cntKuli < k || cntSekretaris < s){
			printf("tidak mungkin\n");
		}else{
			totalDaerah = 0;
			memset(isVisited, false, sizeof isVisited);
			for(i=1;i<=n;i++){
				jumlahMandor = 0, jumlahKuli = 0, jumlahSekretaris = 0, jumlahBerat = 0;
				if(!isVisited[i]){
					totalDaerah++;
					dfs(i);	
					pasangan pas;
					pas.jumlahMandor = jumlahMandor; pas.jumlahKuli = jumlahKuli; pas.jumlahSekretaris = jumlahSekretaris; pas.jumlahBerat = jumlahBerat;
					listPas.pb(pas);
				}
			}	

			//start dp
			memset(dp, -1, sizeof dp);
			foundSolution = false;
			ll ans = solve(0, k,m,s);
			if(!foundSolution){
				printf("tidak mungkin\n");
			}else{
				printf("%lld\n",ans);	
			}
			
		}
		
		listPas.clear();
		AdjList.clear();
	}
	return 0;
};