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

int main(){
	int n,i,j,k;
	scanf("%d",&n);
	ll sum = 0;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			int gcd = __gcd(j,i);
			for(k=1;k<=n;k++){
				int gcd1 = __gcd(gcd, k);
				sum += gcd1;
			}
		}
	}
	printf("%lld\n",sum);
	return 0;
};