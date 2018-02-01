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

const int maxn = 5e5;
const int mod = 1e8 + 7;
ll a[maxn+10];
int main(){
	int tc,i;
	
	a[1] = 1;
	a[2] = 1;
	for(i=3;i<=maxn;i++){
		a[i] = a[i-1] + a[i-2];
		a[i]%=mod;
	}
	scanf("%d",&tc);
	while(tc--){
		int idx;
		scanf("%d",&idx);
		printf("%lld\n",a[idx]);
	}
	return 0;
};