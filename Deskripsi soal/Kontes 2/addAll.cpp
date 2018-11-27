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

int main(){
	int n,i,j;
	scanf("%d",&n);
	priority_queue<ll, vector<ll>, greater<ll> > pq;
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		pq.push(bil);
	}

	ll ans = 0;

	while(pq.size() > 1){
		ll tot = pq.top(); pq.pop();
		tot += pq.top(); pq.pop();
		pq.push(tot);
		ans += tot;
		printf("tot: %lld ans jd: %lld\n",tot, ans);
	}

	printf("%lld\n",ans);
	return 0;
};