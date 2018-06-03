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
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int maxn = 2e5 + 5;

vector<vii> AdjList;
set<int> s[maxn];

int main(){
	int k,i,j;
	scanf("%d",&k);
	int n, a[maxn];
	map<int,int> mapper;
	int cnt = 0;
	AdjList.assign(maxn,vii());
	viii listPasanganBil;
	int sum[maxn];
	for(i=0;i<k;i++){
		scanf("%d",&n);
		int jumlah = 0;
		for(j=0;j<n;j++){
			scanf("%d",&a[j]);
			listPasanganBil.pb(make_pair(a[j], ii(i+1, j+1)));
			jumlah+=a[j];
		}
		sum[i] = jumlah;
		// printf("sum[%d]: %d\n",i,sum[i]);
		for(j=0;j<n;j++){
			int hasilSelisih = sum[i] - a[j];
			if(mapper.find(hasilSelisih) == mapper.end()) {
				mapper[hasilSelisih] = cnt;
				AdjList[cnt].pb(ii(i+1, j+1));
				s[cnt].insert(i+1);
				cnt++;
			}else{
				int idx = mapper[hasilSelisih];
				AdjList[idx].pb(ii(i+1,j+1));
				s[idx].insert(i+1);
			}
		}
	}

	for(i=0;i<listPasanganBil.size();i++) {
		iii front = listPasanganBil[i];
		int bil = front.first;
		int idxList = front.second.first;
		int idxArray = front.second.second;
		int harapan = sum[idxList - 1] - bil;
		// printf("i: %d harapan; %d bil: %d idxList: %d idxArray: %d\n",i,harapan,bil,idxList, idxArray);
		int idxMapper = mapper[harapan];
		// printf("idxMapper: %d ukuran set: %d\n",idxMapper, (int)s[idxMapper].size());

		if(s[idxMapper].size() > 1){
			for(j=0;j<AdjList[idxMapper].size();j++) {
				int idxListTetangga = AdjList[idxMapper][j].first;
				int idxArrayTetangga = AdjList[idxMapper][j].second;

				if(idxList != idxListTetangga) {
					printf("YES\n");
					printf("%d %d\n",idxList, idxArray);
					printf("%d %d\n",idxListTetangga, idxArrayTetangga);
					return 0;					
				}
			}	
		}else{
			if(*s[idxMapper].begin() == idxList){continue;}
			ii pasangan = AdjList[idxMapper][0];
			int idxListTetangga = pasangan.first;
			int idxArrayTetangga = pasangan.second;

			printf("YES\n");
			printf("%d %d\n",idxList, idxArray);
			printf("%d %d\n",idxListTetangga, idxArrayTetangga);
			return 0;
		}
		

	}
	printf("NO\n");


	
	return 0;
};