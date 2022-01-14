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

bool cmp(ii a, ii b) {
	return a.first > b.first;
}

ii a[200010];
int pos[200010];

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);

	while(tc--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i].first);
			a[i].second = i;
			pos[i] = -1;
		}
		sort(a+1, a+n+1, cmp);

		pos[0] = 0;
		int kiri = -1, kanan = 1;
		bool isKiri = 1;
		ll sum = 0;
		for(i=1;i<=n;i++){
			int building = a[i].second;
			if(isKiri) {
				pos[building] = kiri--;
				sum += (-(ll)pos[building]*2*a[i].first);
			}else{
				pos[building] = kanan++;
				sum += ((ll)pos[building] * 2 * a[i].first);
			}
			// printf("building i: %d = %d pos: %d\n",i, building, pos[building] );
			isKiri = 1 - isKiri;
		}

		printf("%lld\n", sum);
		for(i=0;i<=n;i++){
			printf("%d ", pos[i]);
		}
		puts("");
	}
	
	return 0;
};