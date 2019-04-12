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
typedef pair<int,ll> ii;
typedef vector<ii> vii;

vector<vi> AdjList;

int main(){
	int n,m,s,t,i,j;
	scanf("%d %d %d %d",&n,&m,&s,&t);
	AdjList.assign(101, vi());
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}
	queue<int> q;
	q.push(s);
	ll cnt[101];

	memset(cnt, 0, sizeof cnt);
	cnt[s] = 1;
	vii listBil;
	// printf("t: %d\n",t);
	for(i=0;i<t;i++){
		listBil.clear();
		bool vis[101];
		memset(vis, false, sizeof vis);
		while(!q.empty()){
			int front = q.front(); q.pop();
			if(vis[front]){continue;}
			listBil.pb(ii(front, cnt[front]));
			vis[front] = true;
			// printf("dipush: %d %lld\n",front,cnt[front]);
		}
		

		// printf("\n");
		for(int k=0;k<listBil.size();k++){
			ii d = listBil[k];
			int front = d.first;
			ll ukuran = d.second;
			// printf("front: %d\n",front);
			for(j=0;j<AdjList[front].size();j++){
				int v = AdjList[front][j];
				cnt[v] += ukuran;
				// printf("cnt[%d] jd: %lld\n",v,cnt[v]);
				q.push(v);
			}
			cnt[front] -= ukuran;
			// printf("cnt[%d] jd: %lld\n",front,cnt[front]);
		}
	}
	ll ans = 0;
	for(i=0;i<n;i++){
		ans += cnt[i];
	}
	printf("%lld\n",ans);
	return 0;
};