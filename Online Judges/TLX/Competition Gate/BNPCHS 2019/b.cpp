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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		ll n,m;
		scanf("%lld %lld",&n,&m);
		ll miring = (n+m)*(n+m);
		ll sisi = 2*n;
		ll tengah = 3LL*n*n;
		double panjangTengah = (2.0/3.0)*sqrt(tengah);
		// printf("miring: %lld lurus: %lld h: %lld\n",miring, lurus,h);
		double tinggi = sqrt(miring-panjangTengah*panjangTengah);
		// printf("tinggi: %.9lf\n",tinggi);
		printf("%.9lf\n",tinggi+(double)n+(double)m);
	}
	return 0;
};