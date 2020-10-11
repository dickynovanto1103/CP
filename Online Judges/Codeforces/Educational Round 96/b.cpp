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
	ll a[200001];
	while(tc--){
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		for(i=n-2;i>=0 && k > 0;i--) {
			a[n-1] += a[i];
			a[i] = 0;
			k--;
		}
		printf("%lld\n",a[n-1]);
	}
	
	return 0;
};