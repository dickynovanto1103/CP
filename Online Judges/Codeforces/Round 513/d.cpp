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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn], b[maxn];
	for(i=0;i<n;i++){scanf("%d %d",&a[i],&b[i]);}
	sort(a,a+n);
	sort(b,b+n);
	ll ans = 0;
	for(i=0;i<n;i++){
		ans += max(a[i],b[i]);
		ans++;
	}
	printf("%lld\n",ans);
	return 0;
};