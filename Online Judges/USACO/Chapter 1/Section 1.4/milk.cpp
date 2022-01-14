/*
ID: dickyno1
LANG: C++14
TASK: milk
*/

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

int main(){
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
	
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	vii priceAndAmountList;
	for(i=0;i<m;i++){
		int p, a;
		scanf("%d %d",&p,&a);
		priceAndAmountList.pb(ii(p,a));
	}
	sort(priceAndAmountList.begin(), priceAndAmountList.end());
	int tot = 0;
	for(i=0;i<m;i++){
		int p = priceAndAmountList[i].first, a = priceAndAmountList[i].second;
		if(n <= a) {
			tot += p * n;
			break;
		}else{
			tot += p * a;
		}
		n -= a;
	}
	printf("%d\n", tot);

	return 0;
};