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
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;
iii pas[maxn];

bool cmp(iii a, iii b){
	if(a.first.first == b.first.first) {return a.first.second < b.first.second;}
	return a.first.first < b.first.first;
}

map<int, ll> mapper;
map<int,int> banyakDiIdx;
map<int,int> isKiri;
int k;
vi listIdxAcuan;

ll prosesKiri(int idx, bool isKeKiri) {
	
	if(isKeKiri) {
		
		int idxKiri = idx - k + 1;
		
		int idxDiList = lower_bound(listIdxAcuan.begin(), listIdxAcuan.end(), idxKiri) - listIdxAcuan.begin();
		if(idxDiList==listIdxAcuan.size()){idxDiList--;}
		int bil = listIdxAcuan[idxDiList];
		if(isKiri[bil] == 1){
			// printf("yang direturn 1: %lld\n",mapper[idx] - mapper[bil-1]);
			return mapper[idx] - mapper[bil-1];
		}else{
			ll banyak = mapper[idx] - mapper[bil];
			ll banyakKanan = bil - idxKiri + 1;
			// printf("mapper[%d]: %lld mapper[%d]: %lld\n",idx-1,mapper[idx-1], bil,mapper[bil]);
			// printf("banyak: %lld banyakKanan: %lld\n",banyak, banyakKanan);

			banyak+=(banyakKanan*banyakDiIdx[bil]);
			// printf("yang direturn: %lld\n",banyak);
			return banyak;
		}
	}else{
		// printf("\nisKeKanan gan\n\n");
		int idxKanan = idx+k-1;
		// printf("idxKanan: %d\n",idxKanan);
		int idxDiList = lower_bound(listIdxAcuan.begin(), listIdxAcuan.end(), idxKanan) - listIdxAcuan.begin();
		if(idxDiList==listIdxAcuan.size()){idxDiList--;}
		int bil = listIdxAcuan[idxDiList];
		if(isKiri[bil] == 1) {
			if(idxKanan == bil) {
				// printf("yang direturn: %lld\n",mapper[bil-1] - mapper[idx-1] + banyakDiIdx[bil]);
				return mapper[bil-1] - mapper[idx-1] + banyakDiIdx[bil];	
			}else{
				// printf("yang direturn: %lld\n",mapper[bil-1] - mapper[idx-1]);
				return mapper[bil-1] - mapper[idx-1];	
			}
		}else{
			ll banyak = mapper[bil] - mapper[idx-1];
			ll banyakKanan = bil - idxKanan;
			// printf("bil: %d idxKanan: %d banyak: %lld\n",bil,idxKanan,banyak);
			banyak-=(banyakKanan*banyakDiIdx[bil]);


			// printf("halo yang direturn: %lld\n",banyak);
			return banyak;
		}
	}
}

ll prosesKanan(int idx, bool isKeKiri) {
	// printf("proses kanan idx: %d\n",idx);
	if(isKeKiri) {
		int idxKiri = idx - k + 1;
		// printf("idxKiri: %d\n",idxKiri);
		int idxDiList = lower_bound(listIdxAcuan.begin(), listIdxAcuan.end(), idxKiri) - listIdxAcuan.begin();
		if(idxDiList==listIdxAcuan.size()){idxDiList--;}
		int bil = listIdxAcuan[idxDiList];
		// printf("idxDiList: %d bil: %d\n",idxDiList, bil); printf("mapper[%d]: %lld mapper[%d]: %lld\n",idx,mapper[idx],bil-1, mapper[bil-1]);
		if(isKiri[bil]==1){
			// printf("yang direturn %lld\n",mapper[idx] - mapper[bil-1]);
			return mapper[idx] - mapper[bil-1];
		}else{
			ll banyak = mapper[idx] - mapper[bil];
			ll banyakKanan = bil - idxKiri+1;
			banyak+=(banyakKanan*banyakDiIdx[bil]);
			// printf("yang direturn: %lld\n",banyak);
			return banyak;
		}
	}else{
		int idxKanan = idx+k-1;
		// printf("\n");
		// printf("ke kanan idxKanan: %d\n",idxKanan);
		int idxDiList = lower_bound(listIdxAcuan.begin(), listIdxAcuan.end(), idxKanan) - listIdxAcuan.begin();
		if(idxDiList==listIdxAcuan.size()){idxDiList--;}
		int bil = listIdxAcuan[idxDiList];
		// printf("idxDiList: %d bil: %d\n",idxDiList, bil); printf("mapper[%d]: %lld mapper[%d]: %lld\n",idx-1,mapper[idx-1],bil-1, mapper[bil-1]);
		if(isKiri[bil] == 1){
			if(idxKanan == bil) {
				// printf("yang direturn: %lld\n",mapper[bil-1] - mapper[idx-1] + banyakDiIdx[bil]);
				return mapper[bil-1] - mapper[idx-1] + banyakDiIdx[bil];
			}else{
				// printf("yang direturn: %lld\n",mapper[bil-1] - mapper[idx-1]);
				return mapper[bil-1] - mapper[idx-1];
			}
		}else{
			ll banyak = mapper[bil] - mapper[idx-1];
			ll banyakKanan = bil - idxKanan;

			// printf("mapper[%d]: %lld mapper[%d]: %lld\n",bil,mapper[bil], idx-1, mapper[idx-1]);
			// printf("banyak: %lld banyakKanan: %lld\n",banyak, banyakKanan);
			// printf("bil: %d idxKanan: %d\n",bil, idxKanan);
			banyak-=(banyakKanan*banyakDiIdx[bil]);
			// printf("idx: %d yang direturn terakhir: %lld\n",idx, banyak);
			return banyak;
		}
	}
}

int main(){
	int tc,i,j;
	int m;
	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d",&m,&k);
		int maksR = 0;
		for(i=0;i<m;i++){
			int a,b,w;
			scanf("%d %d %d",&a,&b,&w);
			maksR = max(maksR, b);
			banyakDiIdx[a] = w; banyakDiIdx[b] = w;
			pas[i] = make_pair(ii(a,b), w);
		}
		sort(pas,pas+m,cmp);
		
		for(i=0;i<m;i++){
			int l = pas[i].first.first, r = pas[i].first.second;
			isKiri[l] = 1; isKiri[r] = 0;
			ll w = (ll)pas[i].second;
			listIdxAcuan.pb(l); listIdxAcuan.pb(r);
			if(i==0){
				mapper[l-1] = 0;
				mapper[l] = w;
				mapper[r] = w*(ll)(r-l+1LL);
				mapper[r-1] = mapper[r] -w;
				if(r+k-1 > maksR) {
					listIdxAcuan.pb(r+k-1); mapper[r+k-1] = mapper[maksR];
				}
				if(l+k-1 > maksR) {
					listIdxAcuan.pb(l+k-1); mapper[r+k-1] = mapper[maksR];
				}
			}else{
				mapper[l-1] = mapper[pas[i-1].first.second];
				mapper[l] = mapper[l-1] + w;
				mapper[r] = mapper[l-1] + w*(ll)(r-l+1LL);
				mapper[r-1] = mapper[r] - w;
				if(r+k-1 > maksR) {
					listIdxAcuan.pb(r+k-1); mapper[r+k-1] = mapper[r];
				}
				if(l+k-1 > maksR) {
					listIdxAcuan.pb(l+k-1); mapper[r+k-1] = mapper[maksR];
				}
			}
		}

		ll ans = 0;
		for(i=0;i<m;i++){
			int l = pas[i].first.first, r = pas[i].first.second;
			//coba ke kiri sama ke kanan dari masing-masing l sama r
			//lower_bound dari l ke l-k+1
			
			ans = max(ans, prosesKiri(l, true));
			ans = max(ans, prosesKiri(l,false));
			ans = max(ans, prosesKanan(r, true));
			ans = max(ans, prosesKanan(r, false));
		}
		printf("%lld\n",ans);
		listIdxAcuan.clear(); mapper.clear(); banyakDiIdx.clear(); isKiri.clear();
	}

	return 0;
};