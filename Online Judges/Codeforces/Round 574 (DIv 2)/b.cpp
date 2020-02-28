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

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	ll kiri = 1, kanan = 1e9, mid, ans;
	while(kiri <= kanan) {
		mid = (kiri + kanan)/2;
		ll val1 = (mid*(mid+1LL))/2LL;
		ll val2 = n - mid;
		if(val1 - val2 > k){
			kanan = mid-1;
		}else if(val1 - val2 < k){
			kiri = mid+1;
		}else{
			ans = val2;
			break;
		}
	}
	printf("%lld\n",ans);
	return 0;
};