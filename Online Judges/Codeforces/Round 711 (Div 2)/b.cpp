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

int cnt[20];
int twoPowerToIdx[1000001];

void generateTwoPowerToIdx() {
	int bil = 1;
	int idx = 0;
	while(bil <= 1000000) {
		twoPowerToIdx[bil] = idx;
		bil *= 2;
		idx++;
	}
}

int getMinHeight(int n, int w) {
	int height = 0;
	while(true) {
		int sisaW = w;
		if(n == 0){
			break;
		}
		for(int i=19;i>=0;i--){
			if(cnt[i] == 0){
				continue;
			}
			while(sisaW >= (1<<i) && cnt[i] > 0) {
				sisaW -= (1<<i);
				n--;
				cnt[i]--;
				if(n == 0){
					break;
				}
			}
		}
		height++;
	}
	return height;
}

int main(){
	int tc,i,j;
	generateTwoPowerToIdx();
	scanf("%d",&tc);

	while(tc--){
		int n,w;
		scanf("%d %d",&n,&w);
		memset(cnt, 0, sizeof cnt);

		for(int i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			int idx = twoPowerToIdx[bil];
			cnt[idx]++;
		}
		printf("%d\n",getMinHeight(n, w));
	}
	
	return 0;
};