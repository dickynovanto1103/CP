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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

ll pref[maxn], a[maxn];

int main(){
	int n,i,j;
	ll s;

	while(scanf("%d %lld",&n,&s) !=EOF) {
		for(i=1;i<=n;i++) {
			scanf("%lld",&a[i]);
			pref[i] = a[i];
			pref[i] += pref[i-1];
		}
		int ans = -1;
		for(i=1;i<=n;i++){
			int kiri = i, kanan = n, mid;
			while(kiri <= kanan){
				mid = (kiri + kanan)/2;
				ll sum = pref[mid] - pref[i-1];
				if(sum > s) {
					kanan = mid-1;
				}else{
					if(sum == s){
						ans = mid;
						kanan = mid-1;
					}else{
						kiri = mid+1;	
					}
					
				}
			}
			if(ans != -1){printf("%d %d\n",i,ans ); break;}

		}
		if(ans == -1){printf("-1\n");}
	}
	
	
	return 0;
};