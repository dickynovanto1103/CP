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
typedef pair<ii,int> iii;
vector<vi> AdjList;

const int maxn = 5e4 + 4;

struct pasangan{
	int cnt, minVal;
};

int main(){
	int tc;
	int n,m,k,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&n,&m,&k);
		AdjList.assign(n+1,vi());
		int asal[maxn];
		for(i=0;i<(n-1);i++){
			int a,b;
			scanf("%d %d",&a,&b);
			AdjList[a].pb(b); AdjList[b].pb(a);

		}
		queue<iii> q;
		for(i=0;i<m;i++){
			scanf("%d",&asal[i]);
			q.push(make_pair(ii(asal[i],k), -1));
		}

		int cnt[maxn];
		memset(cnt, 0, sizeof cnt);
		while(!q.empty()){
			iii front = q.front(); q.pop();
			int node = front.first.first, sisaK = front.first.second, parent = front.second;
			if(sisaK == -1){continue;}
			cnt[node]++;
			// printf("cnt[%d] jadi: %d\n",node,cnt[node]);
			for(i=0;i<AdjList[node].size();i++){
				int v = AdjList[node][i];
				if(v!=parent){
					q.push(make_pair(ii(v,sisaK-1), node));	
				}
			}
		}
		int ans = 0;
		for(i=1;i<=n;i++){
			if(cnt[i] == m){
				ans++;
			}
		}
		printf("%d\n",ans);

		AdjList.clear();
	}
	return 0;
};