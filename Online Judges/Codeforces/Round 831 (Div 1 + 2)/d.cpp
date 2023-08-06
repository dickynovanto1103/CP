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

bool inStore[100010];

int main(){
	int tc;
	scanf("%d",&tc);

	while(tc--){
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		for(int i=0;i<=k;i++){
			inStore[i] = false;
		}
		int target = k;
		vi v(k);
		int slots = (n-1) *(m-1);
		int tambahanSlots = (n - 1) + (m - 1) - 1 - 2;
		slots += tambahanSlots;
		for(int i=0;i<k;i++){
			int bil;
			scanf("%d",&bil);
			v[i] = bil;

		}

		bool valid = true;

		for(int i=0;i<k;i++){
			if(v[i] == target) {
				//ok
				target--;
			}else{
				//cek di inStore dulu, apakah ada target
				while(target > 0 && inStore[target]) {
					inStore[target] = false;
					target--;
					slots++;
				}
				if(v[i] == target) {
					target--;
					continue;
				}
				
				if(slots == 0) {
					valid = false;
					break;
				}
				inStore[v[i]] = true;
				slots--;
			}
		}

		if(!valid) {
			printf("TIDAK\n");
			continue;
		}
		
		while(target > 0 && inStore[target]) {
			inStore[target] = false;
			target--;
			slots++;
		}

		assert(target == 0);

		printf("YA\n");
	}
	
	return 0;
};