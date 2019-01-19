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

ll dpmin[55][5005];
ll dpmaks[55][5050];
int n;
ll a[55][55];

ll solvemaks(int node, int sisa) {
	int i;
	if(sisa == 0){return 0;}
	if(dpmaks[node][sisa] != -1){return dpmaks[node][sisa];}
	for(i=0;i<n;i++){
		dpmaks[node][sisa] = max(dpmaks[node][sisa], a[node][i] + solvemaks(i, sisa-1));
	}
	return dpmaks[node][sisa];
}

ll solvemin(int node, int sisa) {
	int i;
	if(sisa == 0){return 0;}
	if(dpmin[node][sisa] != INT_MAX){return dpmin[node][sisa];}
	for(i=0;i<n;i++){
		dpmin[node][sisa] = min(dpmin[node][sisa], a[node][i] + solvemin(i, sisa-1));
	}
	return dpmin[node][sisa];
}

int main(){
	int i,j;
	while(scanf("%d",&n), n) {
		memset(dpmaks, -1, sizeof dpmaks);

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				
				scanf("%lld",&a[i][j]);
			}
		}

		int m;
		scanf("%d",&m);
		for(i=0;i<n;i++){
			for(j=0;j<=m;j++){
				dpmin[i][j] = INT_MAX;
			}
		}
		ll maks = solvemaks(0, m);
		ll minim = solvemin(0, m);
		printf("%lld %lld\n",maks, minim);
	}
	
	
	return 0;
};