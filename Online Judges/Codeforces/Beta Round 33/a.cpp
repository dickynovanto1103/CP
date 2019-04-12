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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,m,k,i,j;
	scanf("%d %d %d",&n,&m,&k);
	int v[n+1];
	memset(v, -1, sizeof v);
	for(i=0;i<n;i++){
		int r, c;
		scanf("%d %d",&r,&c);
		if(v[r] == -1){v[r] = c;}
		else{v[r] = min(v[r], c);}
	}
	ll sum = 0;
	for(i=1;i<=m;i++){
		if(v[i] != -1){sum += v[i];}
	}
	ll ans = min(sum, (ll)k);
	printf("%lld\n", ans);
	return 0;
};