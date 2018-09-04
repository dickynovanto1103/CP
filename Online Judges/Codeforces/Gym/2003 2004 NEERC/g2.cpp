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

int n,i,j,m,k;
set<int> exist[501];
map<int, int> mep;
int dp[501], a[501], b[501];

int main(){
    freopen("gcis.in", "r", stdin);
    freopen("gcis.out", "w", stdout);
	memset(dp, 0, sizeof dp);
	scanf("%d", &n);
	for(i=0;i<n;++i){
		scanf("%d", a+i);
		if(i)
			exist[i] = exist[i-1];
		exist[i].insert(a[i]);
		mep[a[i]]=i;
	}
	scanf("%d", &m);
	for(i=0;i<m;++i){
		scanf("%d", b+i);
		if(mep.count(b[i]))
			dp[i]=1;
	}
	for(i=1;i<m;++i){
		if(!dp[i])
			continue;
		k = mep[b[i]];
		for(j=i-1;j>=0;--j){
			if(!dp[j] || b[j]>=b[i])
				continue;
			if(exist[k].count(b[j])){
				dp[i] = max(dp[i], 1+dp[j]);
			}
		}
	}
	int ma =*max_element(dp, dp+m);
	printf("%d\n", ma);
	std::vector<int> ans;
	int last = INT_MAX;
	for(i=m-1;i>=0 && ma>0;--i){
		if(dp[i] == ma && b[i] < last){
			last = b[i];
			ans.pb(b[i]);
			--ma;
		}
	}
	reverse(ans.begin(), ans.end());
	for(int x : ans)
		printf("%d ", x);
	puts("");
	return 0;
};