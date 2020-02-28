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
typedef pair<ll,int> ii;
typedef vector<ii> vii;

const int maxn = 5e5 + 5;

int cnt[maxn];
vector<vi> AdjList;
ii q[maxn];
int ans[maxn];

int main(){
	int n,m,que,i,j;

	scanf("%d %d %d",&n,&m,&que);
	AdjList.assign(maxn, vi());
	for(i=0;i<n;i++){
		int el;
		scanf("%d",&el);
		cnt[el]++;
	}
	for(i=1;i<=m;i++){
		AdjList[cnt[i]].pb(i);
	}

	for(i=0;i<que;i++){
		scanf("%lld",&q[i].first); q[i].second = i;
	}
	sort(q, q+que);
	int level = 0;
	vi nodes;
	for(i=0;i<AdjList[0].size();i++){
		nodes.pb(AdjList[0][i]);
	}
	ll state = n;
	for(i=0;i<que;i++){
		//tingkat
		ll year = q[i].first;
		if(level == maxn){

		}else{
			
		}
	}

	for(i=0;i<que;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
};