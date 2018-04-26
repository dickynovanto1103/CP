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
ll bit[maxn];
int n;

void update(int x, int bil) {
	for(int i=x;i<=n;i+=(i & -i)){
		bit[i]+=bil;
	}
}

ll query(int x) {
	ll sum = 0;
	for(int i=x;i>0;i-=(i & -i)) {
		sum+=bit[i];
	}
	return sum;
}

int main(){
	int i,j,a[maxn];
	scanf("%d",&n);
	AdjList.assign(n+1,vi());
	priority_queue<ii,vii, greater<ii> > pq;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i] = min(a[i], n);
		AdjList[a[i]].pb(i);
		update(i,1);
		pq.push(ii(a[i],i));
	}
	ll ans = 0;

	for(i=1;i<=n;i++){
		while(!pq.empty() && pq.top().first < i) {
			ii front = pq.top(); pq.pop();
			update(front.second, -1);
		}
		if(a[i] > i) {
			ll jawab = (query(a[i]) - query(i));
			// printf("i: %d jawab: %lld\n",i,jawab);
			// printf("dari %d ke %d\n",i,a[i]);
			ans+=jawab;
		}
		
	}
	printf("%lld\n",ans);
	return 0;
};