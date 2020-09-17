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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

ll ar[maxn];
ll selisih[maxn];

int main(){
	//rough idea: 
	// 1. if q = 0, then we can do binary search of the answer and place the answer at the start of C (since C is non-increasing) and at the end of B (since B is non-decreasing)
	// then we can get the value of the other array element, then try simulating by iterating through the array and fill array with one of 2 possibilities (using previous value of B or C), then check whether the condition is still fulfilled
	// if we put the number to be so big, it is always possible to construct arrays B and C

	//the next step is how to get the value faster for each query..should be O(log(n)) / O(1) per query
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++){
		scanf("%lld",&ar[i]);
	}
	ll sum = 0;
	for(i=1;i<=n+1;i++){

		ll diff = (ar[i] - ar[i-1]);
		if(!(i == 1 || i == n + 1)){
			if(diff > 0){
				sum += diff;
			}
		}
		selisih[i] = diff;
	}

	ll angka = (sum + ar[1] + 1)/2;
	printf("%lld\n",angka);
	int q;
	scanf("%d",&q);
	while(q--){
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		ll cur = selisih[a];
		selisih[a] += w;
		ll cur1 = selisih[b+1];
		selisih[b+1] -= w;
		printf("a: %d b: %d w: %d cur: %lld selisih[%d]: %lld cur1: %lld selisih[%d]: %lld\n",a,b,w,cur,a,selisih[a], cur1, b+1, selisih[b+1]);
		ll now = 0;
		if(selisih[a] > 0){
			now = selisih[a];
		}

		if(cur > 0) {	
			sum += (now - cur);	
		}else {
			sum += now;
		}
		

		ll now1 = 0;
		if(selisih[b+1] > 0){
			now1 = selisih[b+1];
		}
		if(cur1 > 0) {
			sum += (now1 - cur1);
		}else{
			sum += now1;
		}
		

		if(a == 1){
			ar[a] += w; 
		}
		printf("sum: %lld ar[1]: %lld\n",sum, ar[1]);
		ll tambah = sum + ar[1];
		ll ans = 0;
		printf("tambah: %lld\n",tambah);
		if(tambah >= 0){
			ans = (tambah + 1) / 2;
		}else{
			ans = (tambah - 1) / 2;
		}
		// ll ans = (sum + ar[1] + 1) / 2;
		printf("%lld\n",ans);
	}
	
	return 0;
};