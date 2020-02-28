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

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	int cnt[1010];
	memset(cnt, 0, sizeof cnt);
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		cnt[bil]++;
	}
	int maks = (n+1)/2;
	int ans = 0;
	for(i=1;i<=k;i++){
		int bagi2 = cnt[i]/2;
		if(maks >= bagi2){
			maks -= bagi2;
			ans += (bagi2*2);
			cnt[i]-=(bagi2*2);
		}
	}
	// printf("ans: %d\n",ans);
	for(i=1;i<=k;i++){
		if(cnt[i] == 1) {
			if(maks >= 1){
				maks--;
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
};