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
	int n,i,j;
	scanf("%d",&n);
	ll tot = 0;
	for(i=1;i<=n;i++){
		tot += ((ll)i * (ll)(i+1)) / 2LL;
	}
	// printf("tot: %lld\n",tot);

	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(a > b){swap(a,b);}
		ll kanan = n - b + 1;
		ll kiri = a;
		tot -= (kanan * kiri);
	}
	printf("%lld\n",tot);
	
	return 0;
};