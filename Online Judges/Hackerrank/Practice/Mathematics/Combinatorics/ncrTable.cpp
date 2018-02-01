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

const ll mod = (ll)inf;

int main(){
	ll a[1000][1000];
	int i,j;
	for(i=1;i<1000;i++){
		for(j=0;j<=i;j++){
			if(j==0 || j==i){a[i][j] = 1;}
			else{a[i][j] = (a[i-1][j-1] + a[i-1][j])%mod;}
		}
	}
	int tc,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<=n;i++){
			if(i){printf(" ");}
			printf("%lld",a[n][i]);
		}
		printf("\n");
	}
	return 0;
};