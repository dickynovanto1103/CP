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

const ll mod = 1e9 + 7;

ll modPow(ll a, ll b){
	if(b==0){return 1;}
	else{
		if(b%2==1){return (a*modPow(a,b-1)) %mod;}
		else{
			ll temp = modPow(a,b/2);
			return (temp*temp) %mod;
		}
	}
}

int main(){
	int tc,i,w;
	ll n;
	scanf("%d",&tc);
	int banyak[] = {9,8,7,6,5,4,3,2,1,0};
	while(tc--){
		scanf("%lld %d",&n,&w);
		if(w<-9 || w>9){printf("0\n");}
		else{
			ll pengali;
			if(w<0){pengali = banyak[-w] + 1;}
			else{pengali = banyak[w];}

			printf("%lld\n",((pengali%mod)*(modPow(10LL, (ll)n-2LL))%mod))%mod;
		}
	}
	return 0;
};