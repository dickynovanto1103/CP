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

		for(i=0;i<m;i++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);

			restricted[b] = true;
		}
		int notRestricted = 0;
		for(i=1;i<=n;i++){
			if(!restricted[i]){notRestricted = i; break;}
		}

		for(i=1;i<=n;i++){
			if(i == notRestricted) continue;
			printf("%d %d\n", notRestricted, i);
		}
		
	}
	
	return 0;
};