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
	while(tc--){
		scanf("%d",&n);
		int a[200001];
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		ll sum = 0, maks = 0, maksBil = 0;
		bool valid = true;
		for(int i=0;i<n;i++){
			maksBil = max(maksBil, (ll)a[i]);

			sum += a[i];
			// printf("i: %d maksBil: %lld sum: %lld\n", i, maksBil, sum);
			if(sum <= 0) {
				sum = 0;
				maksBil = 0;
				maks = 0;
			}
			if(maks < sum) {
				maks = sum;
			}

			if(maks > maksBil) {
				// printf("maks: %lld maksBil: %lld\n", maks, maksBil);
				valid = false;
				break;
			}

			
		}

		if(!valid) {
			puts("NO");
		}else{
			puts("YES");
		}
	}
	
	return 0;
};