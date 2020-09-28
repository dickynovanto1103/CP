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
	int tc,n,k,i,j;
	scanf("%d",&tc);
	int a[1001];
	while(tc--){
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		ll ans = 0;
		for(i=1;i<n;i++){
			int selisih = k - a[i];
			int banyakKali = selisih / a[0];
			ans += banyakKali;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
};