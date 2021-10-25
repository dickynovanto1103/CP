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

const int maxn = 3e5 + 5;
int a[maxn], t[maxn], dist[maxn];

int main(){
	int tc,n,k,i,j;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d %d",&n,&k);
		for(i=0;i<=n;i++){
			dist[i] = 2*inf;
		}
		priority_queue<ii, vii, greater<ii> > pq;
		for(i=0;i<k;i++){
			scanf("%d",&a[i]);
			a[i]--;
		}
		for(i=0;i<k;i++){
			scanf("%d",&t[i]);
			pq.push(ii(t[i], a[i]));
			dist[a[i]] = t[i];
		}
		while(!pq.empty()) {
			ii front = pq.top(); pq.pop();
			int temp = front.first, idx = front.second;
			if((idx-1) >= 0 && dist[idx-1] > dist[idx] + 1) {
				dist[idx-1] = dist[idx] + 1;
				pq.push(ii(dist[idx-1], idx-1));
			}
			if(idx+1 < n && dist[idx+1] > dist[idx] + 1) {
				dist[idx+1] = dist[idx] + 1;
				pq.push(ii(dist[idx+1], idx+1));
			}
		}

		for(i=0;i<n;i++){
			assert(dist[i] < 2*inf);
			printf("%d ", dist[i]);
		}
		printf("\n");
	}
	
	return 0;
};