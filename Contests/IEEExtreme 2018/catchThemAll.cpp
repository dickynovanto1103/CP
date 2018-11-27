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
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int maxn = 105;

int main(){
	int tc,n,m,l,timeDig,i,j;
	scanf("%d",&tc);
	int waktu[maxn][maxn];
	srand(time(NULL));
	
	while(tc--){
		scanf("%d %d %d %d",&n,&m,&l,&timeDig);
		viii listBil;	
		int minim = inf;
		int minimSatu = inf;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%d",&waktu[i][j]);
				listBil.pb(make_pair(ii(waktu[i][j] , i), 2*j )); listBil.pb(make_pair(ii(waktu[i][j] + timeDig, i), 2*j + 1));
				minim = min(minim,waktu[i][j] + timeDig);
				minimSatu = min(minimSatu, waktu[i][j]);
			}
		}
		if(l == 1){
			printf("%d\n",minimSatu);
			continue;
		}
		bool isTikusSampe[101];
		int cntTujuanVisited[301];
		memset(isTikusSampe, false, sizeof isTikusSampe); memset(cntTujuanVisited, 0, sizeof cntTujuanVisited);

		sort(listBil.begin(), listBil.end());
		int ans = 0;
		int cnt = 0;
		for(i=0;i<listBil.size();i++){
			int waktu = listBil[i].first.first, awal = listBil[i].first.second, akhir = listBil[i].second;

			if(!isTikusSampe[awal]){
				if(cntTujuanVisited[akhir] == 1){continue;}
				cnt++;
				ans = waktu;
				isTikusSampe[awal] = true;
				cntTujuanVisited[akhir]++;
				if(cnt == l){break;}
			}
		}

		printf("%d\n",ans);
	}
	return 0;
};