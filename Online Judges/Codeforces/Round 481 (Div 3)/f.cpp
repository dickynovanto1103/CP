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

const int maxn = 2e5 + 5;

vector<vi> AdjList;

int main(){
	int n,m,i,j;
	int a[maxn], temp[maxn];
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1,vi());
	for(i=0;i<n;i++){scanf("%d",&a[i]); temp[i] = a[i];}
	sort(temp,temp+n);
	for(i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		u--; v--;
		AdjList[u].pb(v); AdjList[v].pb(u);
	}
	vi ans;
	for(i=0;i<n;i++){
		int idx = lower_bound(temp,temp+n,a[i]) - temp;
		// printf("idx: %d\n",idx);
		for(j=0;j<AdjList[i].size();j++){
			int v = AdjList[i][j];
			// printf("v: %d\n",v);
			if(a[v]<a[i]){
				idx--;
			}
		}
		ans.pb(idx);
	}
	for(i=0;i<ans.size();i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
};