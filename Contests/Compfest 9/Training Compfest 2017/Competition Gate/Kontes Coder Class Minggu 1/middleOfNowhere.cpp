#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int tc,i;
	ll n,m;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld",&n,&m);
		double sum = 0;
		double hasilBagi = (double)n/(double)m;
		sum = (((double)1.0 / hasilBagi)*(double)m);
		/*if(n%m==0){
			double hasilBagi = (double)n/(double)m;
			sum+=(((double)1.0 / hasilBagi)*(double)m);
		}else{
			ll hasilBagi = n/m;
			ll sisaLebihTinggi = n%m;
			sum+=(((double)1.0 / ((double)hasilBagi + (double)1.0))*(double)sisaLebihTinggi);
			ll sisaLebihRendah = m- sisaLebihTinggi;
			sum+=(((double)1.0 / (double)hasilBagi)*(double)sisaLebihRendah);
		}*/
		printf("%.9lf\n",sum);
	}
	return 0;
}