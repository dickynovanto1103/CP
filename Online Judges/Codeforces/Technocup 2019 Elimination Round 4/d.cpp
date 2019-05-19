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

vector<vi> AdjList;

int main(){
	int n,s,i,j;
	scanf("%d %d",&n,&s);
	AdjList.assign(n+1, vi());
	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}
	int cnt = 0;
	for(i=1;i<=n;i++){
		if(AdjList[i].size() == 1){
			cnt++;
		}
	}
	double ans = ((double)s*2.0) / (double)cnt;
	printf("%.9lf\n",ans);
	return 0;
};