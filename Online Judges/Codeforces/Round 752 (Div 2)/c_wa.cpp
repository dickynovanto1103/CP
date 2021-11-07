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
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int a[maxn];
bool dihapus[maxn];
int pref[maxn];
vi bisa;

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d",&n);
		fill(pref, pref+n+1, 0);
		vi bisa;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i] % (i+1) != 0){
				bisa.pb(i);
				pref[i] = 1;
			}
			dihapus[i] = false;
			pref[i] += pref[i-1];
		}

		bool can = true;
		for(i=n;i>=1;i--){
			if(dihapus[i]) {continue;}
			int bil = a[i];
			//cari index skrg
			int banyakDihapus = pref[i] - bisa.size();
			int idx = i - banyakDihapus;
			// printf("i: %d banyakDihapus: %d idx: %d bil: %d\n", i, banyakDihapus, idx, bil);
			if(bil % (idx+1) != 0){
				if(banyakDihapus > 0) {
					//ga bs popback
				}else{
					// puts("masuk sini");
					assert(bisa.size() > 0);
					assert(bisa.back() == idx);
					bisa.pop_back();
				}
				
				continue;
			}
			//ga bs, harus cari index selisih minimal buat hapus
			int selisih = -1;
			for(j=idx-1;j>=1;j--){
				if(bil % (j+1) != 0) {
					selisih = idx-j;
					break;
				}
			}
			if(selisih == -1){can = false; break;}
			int banyakBisaDihapus = bisa.size();
			if(selisih > banyakBisaDihapus) {
				can = false; break;
			}

			//coba hapus
			while(banyakBisaDihapus--){
				int back = bisa.back(); bisa.pop_back();
				dihapus[back] = true;
			}


		}

		can ? puts("YES") : puts("NO");
	}
	
	return 0;
};