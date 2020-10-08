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

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		priority_queue<ii> pq;
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			pq.push(ii(bil, i));
		}
		int turn = 0;
		int lastIdx = -1;
		while(true) {
			if(pq.size() == 0) {
				break;
			}
			ii pas = pq.top(); pq.pop();
			if(pas.second == lastIdx) {
				//pick again
				if(pq.size() == 0){
					break;
				}else{
					ii again = pq.top(); pq.pop();
					int bil = again.first, idx = again.second;
					bil--;
					if(bil > 0) {
						pq.push(ii(bil, idx));
					}
					lastIdx = idx;
					pq.push(pas);
				}
			}else{
				int bil = pas.first, idx = pas.second;
				lastIdx = idx;
				bil--;
				if(bil > 0) {
					pq.push(ii(bil, idx));
				}
			}
			turn = 1 - turn;
		}

		if(turn == 0){
			printf("HL\n");
		}else{
			printf("T\n");
		}
	}
	
	return 0;
};