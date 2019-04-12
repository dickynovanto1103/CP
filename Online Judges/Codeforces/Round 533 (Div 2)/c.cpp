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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

int dp[3]; //dp[i][j] menyatakan banyaknya array sampe idx i yang sisa mod 3 nya adalah j

const int mod = 1e9 + 7;

int cnt[4];

void banyak(int l, int r) {
	int cnt1,cnt2,cnt3;
	cnt1 = cnt2 = cnt3 = r/3;
	if(r%3 == 1){
		cnt1++;
	}else if(r%3 == 2){
		cnt1++; cnt2++;
	}
	int b1,b2,b3;
	b1 = b2 = b3 = (l-1)/3;
	if((l-1)%3 == 1){
		b1++;
	}else if((l-1)%3 == 2){
		b1++; b2++;
	}
	cnt1 -= b1; cnt2 -= b2; cnt3 -= b3;
	cnt[1] = cnt1, cnt[2] = cnt2, cnt[3] = cnt3;
}

void add(int &a, ll b){
	b %= mod;
	// if(b >= mod){b -= mod;}
	a += b;
	if(a >= mod) {a-=mod;}
}

int main(){
	int n,i,j, l,r;
	scanf("%d %d %d",&n,&l,&r);
	banyak(l,r);
	// for(i=0;i<3;i++){
	// 	cnt[i] = banyak(i+1,l,r);
	// 	printf("banyak %d: %d\n",i+1, banyak(i+1,l,r));	
	// }

	for(i=0;i<3;i++){
		add(dp[(i+1)%3], cnt[i+1]);
	}
	
	for(i=0;i<n-1;i++){
		int temp[3];
		memset(temp, 0, sizeof temp);

		for(j=0;j<3;j++){

			add(temp[(j+1)%3], (ll)dp[j] * cnt[1]);
			add(temp[(j+2)%3], (ll)dp[j] * cnt[2]);
			add(temp[j], (ll)dp[j] * cnt[3]);
		}
		for(j=0;j<3;j++){
			dp[j] = temp[j];
		}
	}
	// for(i=0;i<=n;i++){
	// 	for(j=0;j<3;j++){
	// 		printf("dp[%d][%d]: %d\n",i,j,dp[i][j]);	
	// 	}
		
	// }
	printf("%d\n",dp[0]);
	return 0;
};