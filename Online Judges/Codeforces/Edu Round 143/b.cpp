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
	int tc;
	scanf("%d",&tc);

	while(tc--){
		int n,k;
		scanf("%d %d",&n,&k);
		int cnt[51];
		memset(cnt, 0, sizeof cnt);
		int l,r;
		for(int i=0;i<n;i++){
			scanf("%d %d",&l,&r);
			if(l <= k && k <= r) {
				for(int j=l;j<=r;j++) cnt[j]++;
			}
		}

		bool valid = true;
		int val = cnt[k];
		for(int i=1;i<=50;i++){
			if(i == k) continue;
			if(cnt[i] >= val) {
				valid = false; break;
			}
		}

		if(valid) {
			puts("YES");
		}else{
			puts("NO");
		}
	}
	
	return 0;
};