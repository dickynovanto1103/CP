#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n=91,i;
	ll a[n];
	a[0] = 0; a[1] = 1; a[2] = 2;
	for(i=3;i<n;i++){
		a[i] = a[i-1] + a[i-2];
		//printf("a[%d]: %lld\n",i,a[i]);
	}
	ll bil;
	
	while(scanf("%lld",&bil)!=EOF){
		vi listIdx;
		vector<ll> listFib;	
		printf("%lld\n",bil);
		for(i=n-1;i>=1;i--){
			if(bil>=a[i]){bil-=a[i]; listIdx.pb(i); listFib.pb(a[i]);}
		}
		
		for(i=0;i<listIdx.size();i++){
			//if(i){printf(" ");}
			printf("%d ",listIdx[i]);
		}
		printf("\n");
	
		for(i=0;i<listFib.size();i++){
			//if(i){printf(" ");}
			//printf("sum jd: %lld\n",sum);
			printf("%lld ",listFib[i]);
		}
		printf("\n");
		printf("\n");
	}

	return 0;
}