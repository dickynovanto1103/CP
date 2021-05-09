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

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		int n;
		scanf("%d",&n);
		vi listNum;
		ll sumAllNum = 0;
		for(int i=0;i<n;i++){
			int p, m;
			scanf("%d %d",&p,&m);
			for(j=0;j<m;j++){
				listNum.pb(p);
				sumAllNum+=p;
			}
		}

		int len = listNum.size();
		ll ans = 0;
		for(i=0;i<(1<<len);i++){
			ll tempAllSum = sumAllNum;
			ll tempKali = 1;
			for(j=0;j<len;j++){
				if(((1<<j) & i)) {
					tempAllSum -= listNum[j];
					tempKali *= listNum[j];
				}
			}
			if(tempKali == tempAllSum) {
				ans = max(ans, tempKali);
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
};