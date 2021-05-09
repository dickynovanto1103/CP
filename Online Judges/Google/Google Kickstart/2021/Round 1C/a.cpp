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
	int tc,i,j,n,k;
	scanf("%d",&tc);
	int a[40];
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		scanf("%d %d",&n,&k);

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);

		vi list;
		list.pb(a[0] - 1);
		list.pb(k - a[n-1]);
		// printf("pushed: %d %d\n", a[0] -1, k - a[n-1]);

		for(i=0;i<n-1;i++){
			int selisih = a[i+1] - a[i] - 1;
			list.pb(((selisih + 1) / 2));
			// printf("selisih: %d ceil bagi 2: %d\n", selisih, (selisih + 1) / 2);
		}
		sort(list.begin(), list.end());
		int sz = list.size();
		int besar = list[sz - 1] + list[sz - 2];
		double ans1 = (double)besar / (double)k;
		int maks = 0;
		for(i=0;i<n-1;i++){
			int selisih = a[i+1] - a[i] - 1;
			maks = max(maks, selisih);
		}
		double ans2 = (double)maks / (double)k;

		printf("%.9lf\n", max(ans1, ans2));

	}
	
	return 0;
};