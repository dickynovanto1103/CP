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

const int maxn = 1e5 + 5;

int main(){
	int n,p;
	int l[maxn], r[maxn],i,j;
	scanf("%d %d",&n,&p);
	int banyak[maxn];
	for(i=0;i<n;i++){
		scanf("%d %d",&l[i],&r[i]);
		banyak[i] = (r[i]/p) - ((l[i] - 1) / p);
		// printf("banyak[%d]: %d\n",i,banyak[i]);
	}
	l[n] = l[0]; r[n] = r[0];
	banyak[n] = (r[n]/p) - ((l[n] - 1) / p);

	double ans = 0;
	for(i=0;i<n;i++){
		int banyak1 = r[i] - l[i] + 1;
		int banyak2 = r[i+1] - l[i+1] + 1;
		ll tot = (ll)banyak[i]*(ll)banyak2 + (ll)banyak[i+1]*(ll)banyak1 - ((ll)banyak[i]*(ll)banyak[i+1]);

		double peluang = (double)tot/((double)banyak1*(double)banyak2);
		// printf("i: %d tot: %d peluang: %lf\n",i,tot,peluang);
		ans += (peluang*2000.0);
	}
	printf("%.9lf\n", ans);
	return 0;
};