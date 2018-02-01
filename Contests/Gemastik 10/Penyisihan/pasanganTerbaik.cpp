#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000LL
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

const int maxn = 100010;
ll a[maxn],b[maxn],c[maxn];
int main(){
	int tc,n,m,i,j;
	scanf("%d",&tc);
	
	//printf("test\n");
	while(tc--){
		scanf("%d %d",&n,&m);
		
		for(i=0;i<n;i++){scanf("%lld",&a[i]);}
			//printf("test\n");
		sort(a,a+n);
		for(i=0;i<n;i++){scanf("%lld",&b[i]);}
		sort(b,b+n);
		for(i=0;i<m;i++){scanf("%lld",&c[i]);}
		ll minim = inf;

		for(i=0;i<(min(n,3));i++){
			for(j=0;j<(min(n,3));j++){
				ll hasilkali = a[i]*b[j];
				ll hasil = hasilkali + c[hasilkali%m];
				minim = min(minim,hasil);
			}
		}
		printf("%lld\n",minim);
	}
	return 0;
};