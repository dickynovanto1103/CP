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
	ll n,m,i,j;
	ll x,y,k;
	scanf("%lld %lld %lld",&n,&m,&k);
	if(k==(n-1)){
		printf("%d 1\n",n);
	}else if(k<(n-1)){
		printf("%d 1\n",1+k);
	}else{
		x = n; y =1;
		ll milestone = (m-1)*2LL;
		
	}

	return 0;
};