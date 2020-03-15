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

const int maxn = 100;

bool vis[maxn][maxn];
vii listPas;

void experiment(int x, int y) {
	memset(vis, false, sizeof vis);
	queue<ii> q;
	q.push(ii(x,y));
	vis[x][y] = true;
	listPas.pb(ii(x,y));
	while(!q.empty()) {
		ii front = q.front(); q.pop();
		x = front.first, y = front.second;
		if(x - y >= 1){
			if(!vis[x-y][y]){
				vis[x-y][y] = true;
				q.push(ii(x-y, y));
				listPas.pb(ii(x-y,y));
			}
		}
		if(x + y < maxn){
			if(!vis[x+y][y]) {
				vis[x+y][y] = true;
				q.push(ii(x+y,y));
				listPas.pb(ii(x+y,y));
			}
		}
		if(y-x >= 1){
			if(!vis[x][y-x]){
				vis[x][y-x] = true;
				q.push(ii(x,y-x));
				listPas.pb(ii(x,y-x));
			}
		}
		if(y+x < maxn){
			if(!vis[x][y+x]){
				vis[x][y+x] = true;
				q.push(ii(x,y+x));
				listPas.pb(ii(x,y+x));
			}
		}
	}
}

int main(){
	int tc,i,j;
	ll a,b,c,d;
	// experiment(4,12);
	// sort(listPas.begin(), listPas.end());
	// reverse(listPas.begin(), listPas.end());
	// for(ii a : listPas) {
	// 	if(a.first <= 4){continue;}
	// 	printf("%d %d\n",a.first, a.second);
	// }
	// return 0;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		ll g = __gcd(a,b);
		if(c % g == 0 && __gcd(c,d) == g){printf("YES\n");}
		else{printf("NO\n");}
	}
	return 0;
};