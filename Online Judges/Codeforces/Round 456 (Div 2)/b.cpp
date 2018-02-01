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
	ll n,k,i,j;
	scanf("%lld %lld",&n,&k);
	ll idx = 0;
	ll sum = 0;
	vi listBil;
	for(i=0;;i++){
		ll bil = (1LL<<i);
		
		if(n&bil==0){sum+=bil;}
		if(bil>n){break;}
	}
	if(k==1){
		printf("%lld\n",n); return 0;
	}else{
		printf("%lld\n",(1LL<<i)-1LL);
	}
	// for(i=listBil.size()-1;i>=0;i--){
	// 	ll bil = listBil[i];
	// 	sum^=bil;
	// 	//printf("dixor sama: %lld jd: %lld\n",bil,sum);
	// 	idx++;
	// 	if(idx==k){break;}
	// }
	// printf("%lld\n",sum);

	// for(i=0;;i++){
	// 	ll bil = (1LL<<i);
	// 	if(bil>n){break;}
	// 	sum^=bil;
	// 	idx++;
	// 	if(idx==k){break;}
	// }
	//printf("%lld\n",sum);
	return 0;
};