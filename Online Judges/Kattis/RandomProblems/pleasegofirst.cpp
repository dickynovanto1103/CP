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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	FastSlowInput
	while(tc--){
		vector<int> adj[256];
		// scanf("%d",&n);
		cin>>n;
		string kata;
		cin>>kata;
		for(i=0;i<n;i++){
			adj[kata[i]].pb(i);
		}
		int time1 = 0, time2 = 0;
		for(i=0;i<256;i++){
			int ukuran = adj[i].size();
			if(ukuran == 0){continue;}
			int idx = ukuran - 1;
			int terakhir = adj[i][idx];
			int penambahan = 5;
			for(j=ukuran-2;j>=0;j--){
				int el = adj[i][j];
				time1 += (terakhir - el)*5; time2 += penambahan;
				penambahan += 5;
			}
		}
		// printf("time1: %lld time2: %lld\n",time1, time2);
		printf("%d\n",time1 - time2);

	}
	return 0;
};