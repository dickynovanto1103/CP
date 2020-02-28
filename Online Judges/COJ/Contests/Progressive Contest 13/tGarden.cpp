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

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){
	int n,m,t,i,j;
	scanf("%d %d %d",&n,&m,&t);
	set<ii> vis, ined;
	ll ans = n;
	queue<ii> q;
	for(i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		vis.insert(ii(a,b));
		q.push(ii(a,b));
	}
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		ined.insert(ii(a,b));
	}
	for(i=0;i<t;i++){
		vii list;
		while(!q.empty()){
			ii front = q.front(); q.pop();
			list.pb(front);
		}
		int ukuran = list.size();
		for(j=0;j<ukuran;j++){
			ii front = list[j];
			int x = front.first, y = front.second;
			for(int k=0;k<4;k++){
				int xbaru = x + dx[k], ybaru = y + dy[k];
				if(vis.find(ii(xbaru, ybaru)) == vis.end() && ined.find(ii(xbaru, ybaru)) == ined.end()) {
					vis.insert(ii(xbaru, ybaru));
					q.push(ii(xbaru, ybaru));
				}
			}
		}
		ans += q.size();
	}
	printf("%lld\n",ans );
	return 0;
};