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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

int main(){
	int tc,j;
	ll x = 0, y = 0;
	vii listPair;
	ll i;
	int arr[] = {1,2,3,4,6,9,13,18,26,37,52,74,105,148,210,297,420,594,840,1188,1680,2376,3361,4753,6722,9506,13444,19013,26888,38026,53777,76052,107554,152105,215109,304210,430218,608420,860436,1216841,1720873,2433682,3441746,4867364,6883492,9734728,13766985,19469457,27533970,38938914,55067940,77877828,110135881,155755657,220271762,311511314,440543525,623022628,881087050,1246045256,1762174101};
	// for(i=1;i<=2000000000;i++){
	// 	if(i*i > y){
	// 		x = i;
	// 		y += i*i;
	// 		listPair.pb(ii(x,y));
	// 		printf("%lld,",x);
	// 		// printf("x: %lld y: %lld\n",x,y);
	// 	}
	// }
	// cout<<sizeof(arr)/sizeof(arr[0])<<endl;
	scanf("%d",&tc);

	while(tc--){
		int n;
		scanf("%d",&n);
		int idx = lower_bound(arr, arr+61, n) - arr;
		if(arr[idx] == n){
			printf("%d\n",idx+1);
		}else{
			printf("%d\n",idx);
		}
		// printf("%d\n",idx+1);
	}
	return 0;
};