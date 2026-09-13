#include <bits/stdc++.h>
#pragma GCC optimize("O3")

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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

void solve(){
	int n;
	
	while(scanf("%d",&n) != EOF) {
		ii firstNonZero = ii(-1,-1);
		ii lastNonZero = ii(-1,-1);
		int firstIdx, lastIdx;

		vi v(n);
		vi minHeights(n);
		map<ii, int> dist;
		for(int i=0;i<n;i++){
			int num;
			scanf("%d",&num);
			v[i] = num;
			minHeights[i] = num;
			if(num == 0) {

			}else{
				if(firstNonZero == ii(-1,-1)){
					firstNonZero = ii(1,num);
					firstIdx = i;
				}
				lastNonZero = ii(1,num);
				lastIdx = i;
			}
		}

		if(firstNonZero == ii(-1,-1)) {
			puts("0");
			continue;
		}

		//iterate from left to right and right to left
		ii curPair = firstNonZero;
		priority_queue<ii, vii, greater<ii>> q; //lowest idx, idx in array
		
		q.push(ii(firstNonZero.first, firstIdx));
		q.push(ii(lastNonZero.first, lastIdx));
		dist[ii(firstNonZero.first, firstIdx)] = 0;
		dist[ii(lastNonZero.first, lastIdx)] = 0;
		// printf("pushed %d, %d\n", firstNonZero.first, firstIdx);
		// printf("pushed %d, %d\n", lastNonZero.first, lastIdx);
		///SUDAH BENER
		for(int i=1;i<n-1;i++){
			int minHeightBurned = inf;
			if(v[i] > v[i-1]) {
				minHeightBurned = min(minHeightBurned, v[i-1] + 1);
			}else{
				minHeightBurned = min(minHeightBurned, v[i]);
			}

			if(v[i] > v[i+1]){
				minHeightBurned = min(minHeightBurned, v[i+1] + 1);
			}else{
				minHeightBurned = min(minHeightBurned, v[i]);
			}
			q.push(ii(minHeightBurned, i));
			dist[ii(minHeightBurned, i)] = 0;
			// printf("in middle pushed: %d %d\n", minHeightBurned, i);
		}

		
		while(!q.empty()) {
			ii front = q.top(); q.pop();
			
			int lowestHeight = front.first, idx = front.second;
			if(minHeights[idx] < lowestHeight) {
				continue;
			}
			// printf("front: %d %d\n",front.first, front.second);
			if(lowestHeight > 0) {
				minHeights[idx] = min(minHeights[idx], lowestHeight - 1);
				// printf("minHeights[%d] jadi: %d\n", idx, minHeights[idx]);
			}
			
			// printf("ans: %d, minHeights[%d]: %d\n", ans, idx, minHeights[idx]);
			//go to left, right, and down
			//left first
			if(idx > 0) {
				// printf("want to push LEFT, minHeights[%d]: %d\n", idx-1, minHeights[idx-1]);
				if(minHeights[idx-1] > lowestHeight && dist.find(ii(lowestHeight, idx-1)) == dist.end()) {
					dist[ii(lowestHeight, idx-1)] = dist[front] + 1;
					q.push(ii(lowestHeight, idx-1));
					minHeights[idx-1] = min(minHeights[idx-1], lowestHeight);

					// printf("PUSH LEFT push: %d, %d, dist: %d, minHeights[%d] jadi: %d\n", lowestHeight, idx-1, dist[ii(lowestHeight, idx-1)], idx-1, minHeights[idx-1]);
				}
			}

			if(idx < n-1){
				// printf("want to push RIGHT, minHeights[%d]: %d, lowestHeight: %d\n", idx+1, minHeights[idx+1], lowestHeight);
				if(minHeights[idx+1] > lowestHeight && dist.find(ii(lowestHeight, idx+1)) == dist.end()) {
					dist[ii(lowestHeight, idx+1)] = dist[front] + 1;
					q.push(ii(lowestHeight, idx+1));
					minHeights[idx+1] = min(minHeights[idx+1], lowestHeight);
					// printf("PUSH RIGHT push: %d, %d, dist: %d minHeights[%d] jadi: %d\n", lowestHeight, idx+1, dist[ii(lowestHeight, idx+1)], idx+1, minHeights[idx+1]);
				}
			}

			if(lowestHeight > 0 && dist.find(ii(lowestHeight-1, idx)) == dist.end()){
				dist[ii(lowestHeight-1, idx)] = dist[front] + 1;
				if(minHeights[idx] < lowestHeight - 1) {
					continue;
				}
				q.push(ii(lowestHeight - 1, idx));

				// printf("PUSH BELOW push: %d, %d, dist: %d\n", lowestHeight-1, idx, dist[ii(lowestHeight-1, idx)]);
				// printf("PUSH BELOW ans: %d, push: %d, %d\n", ans, lowestHeight-1, idx);
			}
		}

		int ans = 0;
		for(int i=0;i<n;i++){
			ans = max(ans, dist[ii(0, i)]);
		}

		printf("%d\n", ans);
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};