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

int cnt[1000001];

int main(){
	int tc,i,j,n,k,d;
	scanf("%d",&tc);
	int a[200010];
	while(tc--){
		scanf("%d %d %d",&n,&k,&d);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int ans = 0;
		int maks = inf;
		for(i=0;i<d;i++){
			cnt[a[i]]++;
			if(cnt[a[i]] == 1){
				ans++;
			}
		}
		maks = ans;
		int l = 0, r = d-1;
		while(r < n){
			cnt[a[l]]--;
			if(cnt[a[l]] == 0){
				ans--;
			}
			l++;
			r++;
			if(r >= n){break;}
			cnt[a[r]]++;
			if(cnt[a[r]]==1){
				ans++;
			}
			maks = min(maks, ans);
		}
		printf("%d\n",maks);
		for(i=n-d;i<n;i++){
			cnt[a[i]] = 0;
		}

	}
	return 0;
}; 	