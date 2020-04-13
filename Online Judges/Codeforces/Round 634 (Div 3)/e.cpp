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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

int pref[201][200000];
vector<vi> adj;

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);
	int a[200001];

	while(tc--){
		scanf("%d",&n);
		adj.assign(201, vi());
		for(i=1;i<=200;i++){
			for(j=0;j<n;j++){
				pref[i][j] = 0;
			}
		}
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			adj[a[i]].pb(i);
			pref[a[i]][i]++;
			if(i){
				for(j=1;j<=200;j++){
					pref[j][i] += pref[j][i-1];
				}
			}
		}

		viii listPas;

		for(i=1;i<=200;i++){
			int ukuran = adj[i].size();
			if(ukuran){
				int banyak = 0;
				for(j=0;j<ukuran;j++){
					int pas = ukuran - j - 1;
					if(adj[i][j] < adj[i][pas]){
						banyak += 2;
						listPas.pb(iii(ii(adj[i][j], adj[i][pas]), banyak));
					}else if(adj[i][j] == adj[i][pas]){
						banyak++;
						listPas.pb(iii(ii(adj[i][j], adj[i][pas]), banyak));
					}else{
						break;
					}
				}
			}
		}

		int ukuran = listPas.size();
		int ans = 0;
		for(i=0;i<ukuran;i++){
			int awal = listPas[i].first.first, akhir = listPas[i].first.second;
			int banyak = listPas[i].second;
			int maksTambahan = 0;
			for(j=1;j<=200;j++){
				if(akhir == 0){continue;}
				int tambahan = pref[j][akhir-1] - pref[j][awal];
				maksTambahan = max(maksTambahan, tambahan);
			}
			ans = max(ans, banyak + maksTambahan);
		}

		printf("%d\n",ans);

	}
	return 0;
};