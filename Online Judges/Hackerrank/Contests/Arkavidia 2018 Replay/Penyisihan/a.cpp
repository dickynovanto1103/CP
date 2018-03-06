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
	int tc,i,j,n;
	int a[maxn];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int minim = inf;
		for(i=0;i<n;i++){scanf("%d",&a[i]); minim = min(minim,a[i]);}
		ll sisa = 0;
		for(i=0;i<n;i++){
			sisa+=(a[i]-minim);
		}
		printf("%lld\n",sisa);
	}
	return 0;
};