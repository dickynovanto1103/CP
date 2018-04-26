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

const int maxn = 1e4 + 4;
ll a[maxn], p[maxn];

int main(){
	int n,m,i,j;
	ll k;
	scanf("%d %d %lld",&n,&m,&k);
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	for(i=0;i<m;i++){scanf("%lld",&p[i]);}
	srand(time(NULL));
	for(i=0;i<n;i++){
		ll d = (ll)rand()%k;
		a[i]+=d;
	}
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%lld",a[i]);
	}
	printf("\n");
	return 0;
};