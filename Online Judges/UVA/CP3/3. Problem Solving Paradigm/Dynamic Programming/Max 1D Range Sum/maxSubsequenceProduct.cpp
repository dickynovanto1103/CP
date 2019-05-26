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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int a[130];
	int bil;
	int i,j;
	int idx = 0;
	ll maks = 1;
	while(scanf("%d",&bil) != EOF) {
		if(bil == -999999){
			maks = -inf;
			//process
			for(i=0;i<idx;i++){
				ll ans = 1;
				for(j=i;j<idx;j++){
					ans *= a[j];
					maks = max(maks, ans);
				}
			}
			printf("%lld\n",maks);
			idx = 0;
		}else{
			a[idx++] = bil;
		}
	}
	// printf("%lld\n",maks);
	return 0;
};