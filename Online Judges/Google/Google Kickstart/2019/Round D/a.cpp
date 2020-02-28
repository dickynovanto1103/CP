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

int a[100001];

int solve(int n) {
	int i,j;
	int ans = 0;
	for(i=0;i<n;i++){
		int sor = 0;
		for(j=i;j<n;j++){
			sor ^= a[j];
			int banyak = __builtin_popcount(sor);

			if(banyak % 2 == 0){
				ans = max(ans, j-i + 1);
				// printf("sor: %d banyak: %d ans: %d\n",sor, banyak, ans);
				// printf("i: %d j: %d\n",i,j);
			}
		}
	}
	return ans;
}

int main(){
	int tc,i,j,n,q;
	scanf("%d",&tc);
	
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d:",tt);
		scanf("%d %d",&n,&q);

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		while(q--){
			int idx, val;
			scanf("%d %d",&idx,&val);
			a[idx] = val;
			printf(" %d",solve(n));
		}
		printf("\n");
	}
	return 0;
};