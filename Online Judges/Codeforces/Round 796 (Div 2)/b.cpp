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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[200001];
	while(tc--) {
		scanf("%d",&n);

		int even = 0, odd = 0;
		int minStepsToBecomeOdd = inf;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i] % 2 == 1) {
				odd++;
			}else{
				even++;
				int bil = a[i];
				int steps = 0;
				while(bil % 2 == 0){
					bil /= 2;
					steps++;
				}

				minStepsToBecomeOdd = min(minStepsToBecomeOdd, steps);
			}
		}

		if(odd) {
			printf("%d\n", even);
			continue;
		}

		//even semua dapet min steps
		int ans = minStepsToBecomeOdd;
		even--;
		ans += even;
		printf("%d\n", ans);
	}
	
	return 0;
};