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

const int maxn = 2010;

unordered_map<int,int> mapper;

int main(){
	int n,i,j;
	ll a[maxn], b[maxn], c[maxn];

	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);

		for(i=0;i<n;i++){scanf("%lld",&a[i]);}
		for(i=0;i<n;i++){scanf("%lld",&b[i]);}
		for(i=0;i<n;i++){scanf("%lld",&c[i]); mapper[(int)c[i]]++; }
		ll ans = 0;
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				ll bil = a[i] + b[j];
				ll intended = -bil;
				ans+=(ll)mapper[intended];
			}
		}
		printf("%lld\n",ans);
		mapper.clear();
	}
	return 0;
};