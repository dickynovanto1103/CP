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

const ll mod = 1e9 + 7;

const int maxn = 5e4 + 4;

int main(){
	string dum;
	int n,k,i,j;
	cin>>dum;
	scanf("%d %d",&n,&k);
	ll tot = 0;
	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	// printf("n: %d k: %d\n",n,k);
	// printf("halo\n");
	if(k==1){
		for(i=0;i<n;i++){
			for(j=i;j<n;j++){
				// printf("i: %d j: %d\n",i,j);
				int gcd = 0;
				for(int l=i;l<=j;l++){
					gcd = __gcd(gcd, a[l]);
				}
				// printf("gcd: %d\n",gcd );
				tot+=gcd;
				// printf("tot jd: %d\n",tot);
				tot%=mod;
			}
		}	
	}
	printf("%lld\n",tot);
	return 0;
};