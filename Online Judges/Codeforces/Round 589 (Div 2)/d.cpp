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
typedef vector<ii> vii;

vector<vi> adj;

const int maxn = 1e5 + 5;

int warna[maxn];

bool check(int n) {
	vi list23, list12, list13;
	int i,j;
	for(i=1;i<=n;i++){
		if(warna[i] == 1) {
			list12.pb(i); list13.pb(i);
		}else if(warna[i] == 2){
			list12.pb(i); list23.pb(i);
		}else if(warna[i] == 3){
			list13.pb(i); list23.pb(i);
		}
	}
	// sort(list12.begin(), list12.end()); sort(list13.begin(), list13.end()); sort(list23.begin(), list23.end());
	for(i=1;i<=n;i++){
		int col = warna[i];
		vi v;
		for(j=0;j<adj[i].size();j++){
			v.pb(adj[i][j]);
		}
		sort(v.begin(), v.end());
		// printf("i: %d\n",i);
		if(col == 1){
			if(v != list23){

				return false;
			}
		}else if(col == 2){
			if(v != list13){
				return false;
			}
		}else {
			if(v != list12){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	adj.assign(n+1,vi());
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].pb(b); adj[b].pb(a);
	}
	
	memset(warna, -1, sizeof warna);
	int idxWarna = 1;
	for(i=1;i<=n;i++){
		// printf("i: %d warna: %d\n",i,warna[i]);
		if(warna[i] == -1){
			// printf("sini\n");
			set<int> s;
			set<int>::iterator it;
			for(j=1;j<=n;j++){
				s.insert(j);
			}
			for(j=0;j<adj[i].size();j++){
				int v = adj[i][j];
				s.erase(v);
			}
			int nanti = idxWarna;
			// printf("i: %d sisa:\n",i);

			for(it=s.begin();it!=s.end();it++){
				int node = *it;
				// printf("node: %d\n",node);
				if(warna[node] != -1){
					printf("-1\n");
					return 0;
				}else{
					warna[node] = idxWarna;
					nanti = idxWarna+1;
				}
			}
			idxWarna = nanti;
			if(idxWarna == 5){
				printf("-1\n");
				return 0;
			}
		}
	}
	int maks = 0;
	set<int> s;
	s.insert(1); s.insert(2); s.insert(3);
	for(i=1;i<=n;i++){
		maks = max(maks, warna[i]);
		if(s.find(warna[i]) != s.end()){
			s.erase(warna[i]);
		}
		if(warna[i] == -1){
			printf("-1\n");
			return 0;
		}
	}
	if(maks == 3 && s.empty()){
		if(check(n)){
			for(i=1;i<=n;i++){
				if(i>1){printf(" ");}
				printf("%d",warna[i]);
				assert(warna[i] >= 1 && warna[i] <= 3);
			}
			printf("\n");	
		}else{
			// printf("sini\n");
			printf("-1\n");
		}
		
	}else{
		printf("-1\n");
	}
	
	return 0;
};