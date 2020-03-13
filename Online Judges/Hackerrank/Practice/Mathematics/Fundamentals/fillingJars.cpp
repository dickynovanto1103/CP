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

ll ans[10000001];

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		int a,b,k;
		scanf("%d %d %d",&a,&b,&k);
		a--;b--;
		ans[a] += k; ans[b+1] -= k;
	}
	ll tot = 0;
	for(i=0;i<n;i++){
		if(i){
			ans[i] += ans[i-1];
		}
		tot += ans[i];
	}
	printf("%lld\n",tot/n);
	return 0;
};