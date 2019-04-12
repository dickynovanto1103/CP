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

const int maxn = 1e5 + 5;

vector<vi> adj;


int main(){
	int tc,i,j;
	int n;
	scanf("%d",&tc);
	adj.assign(maxn, vi());
	int minim = inf;
	for(int tt=0;tt<tc;tt++){
		scanf("%d",&n);
		int bil;
		for(i=0;i<n;i++){
			scanf("%d",&bil);
			adj[tt].pb(bil);
			if(i == n-1){
				minim = min(minim, bil);
			}
		}
	}
	for(int tt=0;tt<tc;tt++){
		int ukuran = adj[tt].size();
		for(i=0;i<ukuran;i++){
			int bil = adj[tt][i];
			if(bil >= minim && i < ukuran-1){printf("-1\n"); return 0;}
		}
	}
	printf("%d\n",minim);
	return 0;
};