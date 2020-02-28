#include <bits/stdc++.h>

using namespace std;
#define inf 1e18
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

int main(){
	ll m,k;
	int i,j;
	while(scanf("%lld %lld",&m,&k) != EOF) {
		
		int kiri = 0, kanan = k-1;
		ll minim =inf; 
		for(i=kanan;i<=50;i++) {
			// printf("kiri; %d i; %d\n", kiri, i);
			ll temp = m;
			if((i - kiri + 1) < k){break;}
			for(j=kiri;j<=i;j++){
				if(!(temp & (1LL<<j))) {
					temp += (1LL<<j);
				}
			}

			for(j=kiri-1;j>=0;j--) {
				if(temp & (1LL<<j)) {
					if(temp - (1LL<<j) >= m) {
						temp -= (1LL<<j);
						// printf("kurang\n");
					}
				}
			}

			kiri++;
			// printf("minim sebelum; %lld temp: %lld\n",minim,temp );
			minim = min(minim, temp);
		}
		printf("%lld\n",minim );
		// break;
	}
	return 0;
};