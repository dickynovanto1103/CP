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

int a[200010];

int main(){
	int n,i,j;
	while(scanf("%d",&n) != EOF){
		for(i=0;i<2*n;i++){
			scanf("%d",&a[i]);
		}

		vii pasMin;
		int minim = inf + 1;
		int idxMinim = -1;
		for(i=0;i<n;i++){
			if(minim > a[i]) {
				minim = a[i];
				pasMin.clear();
				pasMin.pb(ii(a[i], a[i+n]));
				idxMinim = i;
			}
		}

		sort(pasMin.begin(), pasMin.end());
		int minimPas = pasMin[0].second;
		// printf("pasMin pertama: %d %d\n", pasMin[0].first, pasMin[0].second);
		if(minimPas <= pasMin[0].first) {
			printf("%d %d\n", pasMin[0].first, pasMin[0].second);
		}else {
			int batasMaks = a[idxMinim + n];
			vi listIdx;
			for(i=idxMinim;i<n;i++){
				if(a[i] <= batasMaks){
					listIdx.pb(i);
				}
			}

			vi listBil;
			for(i=0;i<listIdx.size();i++){
				int idx = listIdx[i];
				listBil.pb(a[idx]);
			}
			for(i=0;i<listIdx.size();i++){
				int idx = listIdx[i] + n;
				listBil.pb(a[idx]);
			}

			for(i=0;i<listBil.size();i++){
				if(i) {printf(" ");}
				printf("%d", listBil[i]);
			}
			puts("");
		}
	}
	

	return 0;
};