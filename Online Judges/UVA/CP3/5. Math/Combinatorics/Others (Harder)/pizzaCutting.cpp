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

int main() {
	ll n;
	while(scanf("%lld",&n),(n>=0)){
		n++;
		//double n1 = (double)n;

		/*double ans = 0.5*n1*n1 - 0.5*n1 + 1.0;
		double bawah = floor(ans);
		double atas = ceil(ans);*/
		ll jawab = n*n/2 - n/2 + 1;
		//printf("ans: %lf atas: %lf bawah: %lf\n",ans,atas,bawah);
		/*if(fabs(ans-bawah) > fabs(ans-atas)){jawab = (ll)atas;}
		else{jawab = (ll)bawah;}*/
		printf("%lld\n",jawab);
	}

	return 0;
}