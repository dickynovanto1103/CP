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

int main(){
	int tc,i,j,n,m;
	scanf("%d",&tc);
	bool restricted[100010];
	while(tc--){
		scanf("%d %d",&n,&m);
		fill(restricted, restricted + n + 1, false);
		vi listRes;
		for(i=0;i<m;i++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			if(!restricted[b]) listRes.pb(b);
			restricted[b] = true;
		}
		vi notRestricted;
		for(i=1;i<=n;i++){
			if(!restricted[i]){notRestricted.pb(i);}
		}
		assert(notRestricted.size() > 0);
		vii edges;
		for(i=0;i<notRestricted.size() - 1;i++){
			edges.pb(ii(notRestricted[i], notRestricted[i+1]));
		}

		for(int res: listRes){
			edges.pb(ii(res, notRestricted[0]));
		}

		assert(edges.size() == (n-1));
		for(ii pas: edges) {
			printf("%d %d\n", pas.first, pas.second);
		}
	}
	
	return 0;
};