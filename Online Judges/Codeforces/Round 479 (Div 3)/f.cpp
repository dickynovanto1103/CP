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

const int maxn = 2e5 + 5;

int idxSiapMasuk[maxn];
int ukuranMaks[maxn];
bool siap[maxn];
bool sudah[maxn];

vector<vi> AdjList;

int main(){
	int n = 10;
	scanf("%d",&n);
	AdjList.assign(n+1,vi());
	int a[maxn];
	int i,j;
	map<int,int> mapper;
	int cnt = 0;
	memset(siap,false,sizeof siap);

	for(i=0;i<n;i++){
		idxSiapMasuk[i] = i;
		scanf("%d",&a[i]);
		if(mapper.find(a[i]) == mapper.end()) {
			// printf("mapper[%d]: %d\n",a[i],cnt);
			mapper[a[i]] = cnt++;
		}
	}
	memset(sudah,false,sizeof sudah);
	for(i=0;i<n;i++){
		if(mapper.find(a[i] - 1) == mapper.end()){
			//ga ada sebelumnya, masukin ae ke indeksnya a[i]
			int idx = mapper[a[i]];
			if(siap[idx]){continue;}
			if(sudah[idx]){continue;}
			AdjList[idx].pb(i);
			idxSiapMasuk[idx] = idx;
			siap[idx] = true;
			ukuranMaks[idx] = 1;
			sudah[idx] = true;
			// printf("siap[%d] jd true\n", idx);
		}else{
			int idxSebelum = mapper[a[i] -1];
			if(siap[idxSebelum]){

				int indeksMasuk = idxSiapMasuk[idxSebelum];
				AdjList[indeksMasuk].pb(i);
				siap[idxSebelum] = false;
				int idx1 = mapper[a[i]];
				siap[idx1] = true;
				idxSiapMasuk[idx1] = indeksMasuk;
				sudah[idx1] = true;
				// printf("siap[%d] jd false siap[%d] jd true\n",idxSebelum, idx1);
			}else{
				int idx1 = mapper[a[i]];
				if(sudah[idx1]){continue;}
				AdjList[idx1].pb(i);
				idxSiapMasuk[idx1] = idx1;
				siap[idx1] = true;
				ukuranMaks[idx1] = 1;
				sudah[idx1] = true;
				// printf("siap[%d] jd true\n", idx1);
			}
		}
	}
	int maksUkuran = 0;
	for(i=0;i<=n;i++){
		// printf("node %d:",i);
		// for(j=0;j<AdjList[i].size();j++){
		// 	if(j){printf(" ");}
		// 	printf("%d",AdjList[i][j]);
		// }
		// printf("\n");
		maksUkuran = max(maksUkuran, (int)AdjList[i].size());
		
	}
	for(i=0;i<=n;i++){
		if(AdjList[i].size() == maksUkuran){
			printf("%d\n",maksUkuran);
			for(j=0;j<maksUkuran;j++){
				if(j){printf(" ");}
				printf("%d",AdjList[i][j]+1);
			}
			printf("\n");
			return 0;
		}
	}
	return 0;
};