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

int main(){
	int tc,n,m,i,j;
	scanf("%d",&tc);
	ll sum;
	while(tc--){
		scanf("%d %d",&n,&m);
		ll bil;
		sum = 0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%lld",&bil);
				sum+=bil;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
};