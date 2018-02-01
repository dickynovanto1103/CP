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

ll gcd(ll a, ll b){return b==0? a: gcd(b,a%b);}

int main(){
	int tc;
	ll fpb,kpk;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld",&fpb,&kpk);
		ll a = fpb, b = kpk;
		ll FPB = gcd(a,b);
		ll KPK = a*(b/FPB);
		if(FPB==a && KPK==b){printf("%lld %lld\n",FPB,KPK);}
		else{printf("-1\n");}
	}
	return 0;
};