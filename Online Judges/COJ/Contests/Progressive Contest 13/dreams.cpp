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

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n,m;
		scanf("%d %d",&n,&m);
		bool vis[1010];
		memset(vis, false, sizeof vis);
		for(i=0;i<m;i++){
			int bil;
			scanf("%d",&bil);
			vis[bil] = true;
		}
		vi listBil;
		for(i=1;i<=n;i++){
			if(!vis[i]){listBil.pb(i);}
		}
		for(i=0;i<listBil.size();i++){
			if(i){printf(" ");}
			printf("%d", listBil[i]);
		}
		printf("\n");
	}
	return 0;
};