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

vector<vii> adj;
const int maxn = 2e5 + 5;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	adj.assign(n+1, vii());
	int q;
	scanf("%d",&q);
	vii listDua;
	int dua[maxn];
	memset(dua, 0, sizeof dua);
	for(i=0;i<q;i++){
		int com;
		scanf("%d",&com);
		if(com == 1){
			int person, x;
			scanf("%d %d",&person, &x);
			adj[person].pb(ii(x,i));
		}else{
			int x;
			scanf("%d",&x);
			listDua.pb(ii(x,i));
			dua[i] = x;
		}
	}

	for(i=maxn-2;i>=0;i--){
		dua[i] = max(dua[i], dua[i+1]);
	}

	for(i=1;i<=n;i++){
		int ukuran = adj[i].size();
		if(ukuran){
			ii terakhir = adj[i][ukuran-1];
			int idx = terakhir.second;
			int bil = terakhir.first;
			a[i] = bil;
			int maksSetelah = dua[idx+1];
			if(a[i] < maksSetelah){
				a[i] = maksSetelah;
			}
		}else{
			int maksSetelah = dua[0];
			if(a[i] < maksSetelah){
				a[i] = maksSetelah;
			}
		}
		if(i > 1){
			printf(" ");
		}
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;

};