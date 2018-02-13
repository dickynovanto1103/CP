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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	ll bil;
	while(scanf("%lld",&bil), bil){
		vi a;
		int i;
		if(bil==0){break;}
		if(bil<0){a.pb(-1); bil = abs(bil);}
		ll temp = bil;
		for(i=2;i*i<=bil;i++){
			while(temp%i==0){temp/=i; a.pb(i);}
			if(i>temp){break;}
		}
		if(temp!=1){a.pb(temp);}
		printf("%lld = ",bil);
		for(i=0;i<a.size();i++){
			if(i){printf(" x ");}
			printf("%lld",a[i]);
		}
		printf("\n");
	}
	return 0;
};