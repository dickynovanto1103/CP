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

const int maxn = 50010;

ll x[maxn],y[maxn];

int main(){
	int tc,i,j;
	int n,r,c;

	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&n,&r,&c);
		ll sum = 0;

		for(i=0;i<n;i++){
			scanf("%lld %lld",&x[i],&y[i]);
			sum += ((x[i]-1LL) + (y[i]-1LL));
		}	
		if(sum % 2LL==0){
			printf("-1 -1 -1 -1\n");
		}else{
			for(i=0;i<n;i++){
				if(x[i] > 1 || y[i] > 1){
					int a,b,ax,bx;
					a = x[i]; b = y[i];
					if(x[i] > 1){
						ax = a-1;
						bx = b;
					}else if(y[i] > 1){
						ax = a;
						bx = b-1;
					}
					printf("%d %d %d %d\n", a,b,ax,bx);
				}
			}
		}
	}
	
	return 0;
};