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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int genap[maxn][32];
int ganjil[maxn][32];
int cntGenap[maxn][32];
int cntGanjil[maxn][32];
int n;
vector<vi> even, odd;
ii getIdx(int i, int l, int r, bool isGenap) {
	printf("i: %d l: %d r: %d isGenap: %d\n",i,l,r,isGenap);
	if(isGenap) {
		int idxAwal = lower_bound(even[i].begin(), even[i].end(), l) - even[i].begin();
		if(idxAwal == even[i].size()){
			return ii(0,-1);
		}
		
		int idxAwalReal = even[i][idxAwal];
		printf("idxAwal: %d real: %d n: %d\n",idxAwal, idxAwalReal,n);
		if(idxAwalReal + (1<<(i-1)) >= n) {
			return ii(0,-1);
		}
		int idxAkhir = upper_bound(even[i].begin(), even[i].end(), r-1) - even[i].begin();
		idxAkhir--;
		printf("idxAkhir: %d\n",idxAkhir);
		if(idxAkhir == even[i].size()){
			return ii(0,-1);
		}
		
		int idxAkhirReal = even[i][idxAkhir];
		if(idxAkhirReal + (1<<(i-1)) >= n) {
			return ii(0,-1);
		}
		return ii(idxAwal, idxAkhir);
	}else{
		int idxAwal = lower_bound(odd[i].begin(), odd[i].end(), l) - odd[i].begin();
		if(idxAwal == odd[i].size()){
			return ii(0,-1);
		}
		printf("idxAwal: %d\n",idxAwal);
		int idxAwalReal = odd[i][idxAwal];
		if(idxAwalReal + (1<<(i-1)) >= n) {
			return ii(0,-1);
		}
		int idxAkhir = upper_bound(odd[i].begin(), odd[i].end(), r-1) - odd[i].begin();
		idxAkhir--;
		if(idxAkhir == odd[i].size()){
			return ii(0,-1);
		}
		printf("idxAkhir: %d\n",idxAkhir);
		int idxAkhirReal = odd[i][idxAkhir];
		if(idxAkhirReal + (1<<(i-1)) >= n) {
			return ii(0,-1);
		}
		return ii(idxAwal, idxAkhir);
	}
}

int main(){
	int i,j;
	scanf("%d",&n);
	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		genap[i][0] = a[i];
		ganjil[i][0] = a[i];
	}
	even.assign(32, vi()); odd.assign(32, vi());
	for(i=1;i<32;i++){
		for(j=0;j<n;j+=2){
			int next = j + (1<<(i-1));
			if(next >= n){break;}
			genap[j][i] = genap[j][i-1] + genap[next][i-1];
			// printf("j: %d next: %d genap[%d][%d]: %d\n",j,next,j,i,genap[j][i]);
			if(genap[j][i] >= 10){
				genap[j][i] -= 10; cntGenap[j][i]++;
			}
		}
	}

	for(i=1;i<32;i++){
		for(j=1;j<n;j+=2){
			int next = j + (1<<(i-1));
			if(next >= n){break;}
			ganjil[j][i] = ganjil[j][i-1] + ganjil[next][i-1];
			// printf("j: %d next: %d ganjil[%d][%d]: %d\n",j,next,j,i,ganjil[j][i]);
			if(ganjil[j][i] >= 10){
				ganjil[j][i] -= 10;
				cntGanjil[j][i]++;
				// printf("push di odd %d yaitu %d\n", i,j);
			}
		}
	}
	
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		l--; r--;
		int ans = 0;
		for(i=1;i<30;i++){
			if(l & 1){
				// ii pas = getIdx(i, l, r, false);
				for(j=l;j<=r;j+=(1<<i)){
					if(cntGanjil[j][i]){
						int next = j + (1<<(i-1));
						if(next <= r){
							ans += cntGanjil[j][i];		
						}
					}
					
				}
				// printf("pas: %d %d\n",pas.first, pas.second);
				// ans += (pas.second - pas.first + 1);
			}else{
				// ii pas = getIdx(i, l, r, true);
				for(j=l;j<=r;j+=(1<<i)){
					if(cntGenap[j][i]){
						int next = j + (1<<(i-1));
						if(next <= r){
							ans += cntGenap[j][i];		
						}
					}
				}
				// printf("pas: %d %d\n",pas.first, pas.second);
				// ans += (pas.second - pas.first + 1);

			}
			
		}
		printf("%d\n",ans);
	}

	return 0;
};