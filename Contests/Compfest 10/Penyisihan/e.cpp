#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000LL
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

const int maxn = 1e5 + 5;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	int jenis[maxn], banyak[maxn];
	int hal[maxn];
	ll banyakTotal[maxn];
	while(tc--){
		int n,m;
		scanf("%d %d",&n,&m);
		memset(banyakTotal, 0, sizeof banyakTotal);
		for(i=0;i<n;i++){scanf("%d",&banyak[i]);}
		for(i=0;i<n;i++){
			scanf("%d",&jenis[i]);
			banyakTotal[jenis[i] - 1] += (ll)banyak[i];
		}
		for(i=0;i<m;i++){
			scanf("%d",&hal[i]);
		}
		ll minim = 0;
		int ans;
		for(i=0;i<m;i++){
			ll banyakHal = banyakTotal[i];
			ll kecepatan = hal[i];
			ll hari = banyakHal / kecepatan;
			if(banyakHal % kecepatan != 0){
				hari++;
			}
			if(minim < hari){
				minim = hari;
				ans = i;
			}else if(minim == hari){
				if(ans > i){
					ans = i;
				}
			}
		}
		printf("%d\n",ans+1);
	}
	return 0;
};