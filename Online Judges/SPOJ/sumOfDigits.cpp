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

vi digit;
ll dp[12][1<<(10)][2];
void parse(int bil){
	digit.clear();
	// printf("bil: %d\n",bil);
	while(bil > 0){
		int a = bil % 10;
		bil /= 10;
		digit.pb(a);
		// printf("yang dipush: %d\n",a);
	}
	reverse(digit.begin(), digit.end());

}

ll solve(int idx, int mask, int sudahLebihKecil){
	// printf("idx: %d sudahLebihKecil: %d\n",idx,sudahLebihKecil);
	if(idx == digit.size()){
		return 0;
	}
	ll& ans = dp[idx][mask][sudahLebihKecil];
	if(ans != -1){
		// printf("lgsg balik ans: %lld\n",ans);
		return ans;
	}
	int batas = digit[idx];
	if(sudahLebihKecil){
		batas = 9;
	}
	ans = 0;
	for(int i=0;i<=batas;i++){
		if(i == batas){
			ans += i + solve(idx+1, (1<<i) | mask, sudahLebihKecil);
		}else{
			ans += i + solve(idx+1, (1<<i) | mask, 1);
		}
	}
	// printf("yang direturn ans: %lld\n",ans);
	return ans;
}

int main(){
	int a,b;
	while(scanf("%d %d",&a,&b)){
		if(a == -1 && b == -1){break;}
		memset(dp, -1, sizeof dp);
		// printf("a: %d b: %d\n",a,b);
		parse(b);

		ll ans1 = solve(0, 1,0);
		ll ans2 = 0;
		memset(dp, -1, sizeof dp);
		if(a != 0){
			
			parse(a-1);	
			ans2 = solve(0,0,0);
		}
		// printf("ans1: %lld ans2: %lld\n",ans1,ans2);
		ll ans = ans1 - ans2;
		printf("%lld\n",ans);
	}
	
	
	return 0;
};