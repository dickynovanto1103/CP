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

const int maxn = 1e6 + 6;
int a[maxn];

ll f(ll x){
	return x-1;
}

ii floydCycleFinding(ll x0){
	//cari k*mu
	ll tortoise = a[f(x0)], hare = a[f(f(x0))];
	while(a[tortoise]!=a[hare]){tortoise = f(tortoise); hare = f(f(hare));}
	//cari mu
	int mu = 0; hare = x0;
	while(a[tortoise]!=a[hare]){tortoise = f(tortoise); hare = f(f(hare)); mu++;}
	//finding lambda
	int lambda = 1;hare = f(tortoise);
	while(a[tortoise]!=a[hare]){hare=f(hare); lambda++;}
	return ii(mu,lambda);
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ll x0 = n;
	ii ans = floydCycleFinding(x0);
	printf("%d %d\n",ans.first, ans.second);
	return 0;
};