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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

void solve(){
	int n;
	scanf("%d",&n);
	int teaPrices[n+1];
	for(int i=0;i<n;i++){
		scanf("%d",&teaPrices[i]);
	}

	int t;
	scanf("%d",&t);
	int toppingPrices[t+1];
	for(int i=0;i<t;i++){
		scanf("%d",&toppingPrices[i]);
	}

	int minPrice = inf;
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int toppingKind;
			scanf("%d",&toppingKind);
			toppingKind--;
			int price = teaPrices[i] + toppingPrices[toppingKind];
			minPrice = min(minPrice, price);
		}
	}

	int money;
	scanf("%d",&money);
	printf("%d\n", max(money/minPrice - 1, 0));
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};