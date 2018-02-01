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

int main(){
	ll ncow,ncar,nshow;
	while(scanf("%lld %lld %lld",&ncow,&ncar,&nshow)!=EOF){
		ll sisaM, sisa,total;
		sisaM = ncar-1;
		total = ncow+ncar;
		sisa = total-nshow-1;

		ll penyebut = total*sisa;
		ll pembilang = ncow*ncar + (total-ncow)*sisaM;
		printf("%.5lf\n",(double)pembilang/(double)penyebut);
	}
	return 0;
};