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

const int maxn = 100000;
int a[maxn+10];
int counter[maxn+10];

vector<vi> listIdx;
vii listIdxGanda, listIdxGandaTetap;
vi listIdxTunggal, listIdxTunggalTetap;

void geserTunggal() {
	int i,j;
	int n = listIdxTunggal.size();
	int terakhir = listIdxTunggal[n-1];
	for(i=n-1;i>=0;i--){
		listIdxTunggal[i] = listIdxTunggal[i-1];
	}
	listIdxTunggal[0] = terakhir;
}

void geserGanda() {
	int i,j;
	int n = listIdxGanda.size();
	ii terakhir = listIdxGanda[n-1];
	for(i=n-1;i>=0;i--){
		listIdxGanda[i] = listIdxGanda[i-1];
	}
	listIdxGanda[0] = terakhir;
}

int ans[maxn+10];

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);

	while(tc--){
		scanf("%d",&n);
		memset(counter,0,sizeof counter);
		listIdx.assign(maxn+10,vi());

		for(i=0;i<n;i++){scanf("%d",&a[i]); counter[a[i]]++; listIdx[a[i]].pb(i);}

		for(i=0;i<n;i++){	
			if(listIdx[a[i]].size()==2){
				int bil1 = listIdx[a[i]][0];
				int bil2 = listIdx[a[i]][1];

				listIdxGanda.pb(ii(bil1,bil2)); listIdxGandaTetap.pb(ii(bil1,bil2));
				listIdx[a[i]].clear();
			}else if(listIdx[a[i]].size()==1){
				listIdxTunggal.pb(listIdx[a[i]][0]);
				listIdxTunggalTetap.pb(listIdx[a[i]][0]);
			}
		}

		bool listTunggalBerubah = false, listGandaBerubah = false;
		if(listIdxTunggal.size()>1){listTunggalBerubah = true;}
		if(listIdxGanda.size()>1){listGandaBerubah = true;}

		if(listTunggalBerubah){geserTunggal();}
		if(listGandaBerubah){geserGanda();}

		int ukuranTunggal = listIdxTunggal.size(), ukuranGanda = listIdxGanda.size();
		
		vi listTunggalSementara, listGandaSementara;
		
		for(i=0;i<ukuranTunggal;i++){
			listTunggalSementara.pb(listIdxTunggal[i]);
		}

		for(i=0;i<ukuranGanda;i++){
			listGandaSementara.pb(listIdxGanda[i].first);
			listGandaSementara.pb(listIdxGanda[i].second);
		}

		int minim = min(2*ukuranGanda, ukuranTunggal);
		
		for(i=0;i<minim;i++){
			swap(listTunggalSementara[i], listGandaSementara[i]);
		}

		listIdxTunggal.clear(); listIdxGanda.clear();
		for(i=0;i<ukuranTunggal;i++){
			listIdxTunggal.pb(listTunggalSementara[i]);
		}
		int idx = 0;
		for(i=0;i<ukuranGanda;i++){
			listIdxGanda.pb(ii(listGandaSementara[idx], listGandaSementara[idx+1]));
			idx+=2;
		}
		
		for(i=0;i<ukuranTunggal;i++){
			idx = listIdxTunggalTetap[i];
			int idxBaru = listIdxTunggal[i];
			
			ans[idx] = a[idxBaru];
		}

		for(i=0;i<ukuranGanda;i++){
			ii indeks = listIdxGandaTetap[i];
			ii idxBaru = listIdxGanda[i];
			
			ans[indeks.first] = a[idxBaru.first];
			ans[indeks.second] = a[idxBaru.second];
		}
		
		int cnt = 0;
		for(i=0;i<n;i++){
			if(ans[i]!=a[i]){cnt++;}
		}
		printf("%d\n",cnt);
		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");
		
		listIdx.clear();
		listIdxGanda.clear();listIdxGandaTetap.clear(); listIdxTunggal.clear(); listIdxTunggalTetap.clear();
	}
	return 0;
};