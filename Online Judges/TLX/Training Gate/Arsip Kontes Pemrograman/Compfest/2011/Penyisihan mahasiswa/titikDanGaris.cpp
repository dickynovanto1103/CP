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

ll a[1000000];

int main() {
	int i, idx;
	ll cnt = 0;
	i=0;
	a[i]=4;
	while(true){
		cnt++; i++;
		a[i] = a[i-1] + cnt;
		if(a[i]>inf){break;}
	}
	idx = i;
	int tc;
	ll n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld",&n);
		if(n<4){printf("-1\n");}
		else{
			int indeks = lower_bound(a,a+idx,n) - a;
			if(a[indeks]>n){indeks--;}
			printf("%d\n",indeks);
		}
	}
	
	return 0;
}