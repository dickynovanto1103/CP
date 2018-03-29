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

ll fac[100], power2[100];

int main(){
	fac[0] = 1;
	power2[0] = 1;
	for(ll i=1;i<100;i++){
		fac[i] = i*fac[i-1];
		power2[i] = 3LL*power2[i-1];
		printf("fac[%lld]: %lld power2[%lld]: %lld\n",i,fac[i], i, power2[i]);
		// if(fac[i] > power2[i]){break;}
	}
	
	return 0;
};