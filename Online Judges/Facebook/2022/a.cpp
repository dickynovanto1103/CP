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
	int cnt[120];
	int a[120];

	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		int n,k;
		scanf("%d %d",&n,&k);
		memset(cnt, 0, sizeof cnt);

		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}

		if(k * 2 < n) {
			puts("NO");
			continue;
		}

		bool valid = true;
		for(int i=0;i<n;i++){
			if(cnt[a[i]] >= 3) {
				valid = false;
				break;
			}
		}

		if(!valid) {puts("NO"); continue;}
		puts("YES");
	}
	
	return 0;
};