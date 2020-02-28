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
	int a[300001];
	vi bil;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		int diff = -a[i+1] + a[i];
		// printf("diff: %d\n",diff);
		bil.pb(diff);
	}
	sort(bil.begin(), bil.end());
	k--;
	int ans = a[n-1] - a[0];
	for(i=0;i<k;i++){
		ans += bil[i];
		// printf("ans jd: %d\n",ans);
	}
	printf("%d\n",ans);

	return 0;
};