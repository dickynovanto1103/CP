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
typedef pair<ll,ii> iii;
typedef vector<ii> vii;

int a[100001];

ll calcTime(ll bil, ll bagi) {
	//7 / 3 -> 3 2 2 -> 3x + 2y = 7 
	//7 / 4 -> 2 2 2 1 -> 
	// formula: bil / bagi means that the minNum = bil / bagi, the maxNum = bil + bagi-1 / bagi, numOfMaxNum = bil % bagi, numOfMinNum = bagi - bil % bagi
	if(bil % bagi == 0){
		ll minBil = bil / bagi;
		return minBil*minBil*bagi;
	}else{
		ll minBil = bil / bagi;
		ll maksBil = (bil + bagi - 1) / bagi;
		ll numOfMaxNum = bil % bagi;
		ll numOfMinNum = bagi - numOfMaxNum;
		return minBil*minBil*numOfMinNum + maksBil*maksBil*numOfMaxNum;
	}
}

int main(){
	int n,k,i,j;
	while(scanf("%d %d",&n,&k) != EOF) {
		priority_queue<iii> pq;
		ll ans = 0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			ll timeNow = calcTime(a[i], 1);
			ans += timeNow;
			ll timeLater = calcTime(a[i], 2);
			ll diff = timeNow - timeLater;
			pq.push(iii(diff, ii(a[i], 1)));
		}
		// printf("ans: %lld\n",ans);
		while(n < k){
			iii top = pq.top(); pq.pop();
			ll diff = top.first;
			ii pas = top.second;
			int bil = pas.first, numBagi = pas.second;
			// printf("diff: %lld\n", diff);

			ans -= diff;
			n++;
			// printf("ans jd: %lld\n", ans);

			ll timeNow = calcTime(bil, numBagi + 1);
			ll timeLater = calcTime(bil, numBagi + 2);
			diff = timeNow - timeLater;
			// printf("push diff: %lld bil: %d %d\n",diff, bil, numBagi);
			pq.push(iii(diff, ii(bil, numBagi + 1)));
		}
		printf("%lld\n",ans);
	}
	
	return 0;
};