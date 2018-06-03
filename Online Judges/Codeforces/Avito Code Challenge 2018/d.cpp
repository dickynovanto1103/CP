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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll dp[55][55];
ll a[55];
int n,k;

ll solve(int idx, int banyakShelf, ll sum, ll sebelum) {
	int i,j;
	if(idx==n){
		if(banyakShelf<k){return -inf;}
		else{
			printf("masuk sini ga sih\n");
			dp[idx][banyakShelf] = max(dp[idx][banyakShelf], sebelum & sum);
			// printf("dp[%d][%d] jd: %lld\n",idx,banyakShelf,dp[idx][banyakShelf]);
			return dp[idx][banyakShelf];
		}
	}
	if(banyakShelf==k) {
		//langsung gas semua rata sampe akhir
		ll sum = 0;
		printf("idx: %d\n",idx);
		
		for(i=idx;i<n;i++){
			sum+=a[i];
		}
		if(sebelum==0){
			printf("halo\n");
		}
		if(sum==0){
			printf("sum: %lld sebelum: %lld\n",sum,sebelum);	
		}
		
		ll andSekarang = sebelum & sum;
		dp[idx][banyakShelf] = max(dp[idx][banyakShelf], sebelum & sum);
		printf("dp[%d][%d] jd: %lld\n",idx,banyakShelf,dp[idx][banyakShelf]);
		return dp[idx][banyakShelf];
		
	}
	if(dp[idx][banyakShelf]!=-1){
		return dp[idx][banyakShelf];
	}
	//antara mau lanjut atau ganti shelf dan ambil bil itu
	dp[idx][banyakShelf] = max(dp[idx][banyakShelf], solve(idx+1, banyakShelf, sum+a[idx], sebelum));//lanjut
	ll totalSekarang = sum+a[idx];

	// ll andSekarang = totalSekarang & sebelum;
	ll andSekarang = sebelum & totalSekarang;
	
	printf("sebelum jd: %lld\n",andSekarang);
	if(idx!=(n-1)){
		dp[idx][banyakShelf] = max(dp[idx][banyakShelf], andSekarang & solve(idx+1, banyakShelf+1, 0, andSekarang));	
	}
	
	return dp[idx][banyakShelf];
}

int main(){
	int i,j;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	memset(dp,-1,sizeof dp);
	ll ans = solve(0,1,0,(1LL<<50) - 1);
	printf("%lld\n",ans);
	return 0;
};