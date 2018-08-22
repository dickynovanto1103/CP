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

const int maxn = 1e5 + 5;

bool cmp(ll a, ll b){
	return a > b;
}

int main(){
	int n,i,j;
	ll m;
	ll a[maxn], b[maxn];
	scanf("%d %lld",&n,&m);
	vi selisih;
	ll sum = 0;
	for(i=0;i<n;i++){
		scanf("%lld %lld",&a[i],&b[i]);
		sum+= a[i];
		selisih.pb(a[i] - b[i]);
	}
	sort(selisih.begin(), selisih.end(), cmp);
	int cnt = 0;
	for(i=0;i<n;i++){
		if(sum <= m){break;}
		sum -= selisih[i];
		// printf("selisih: %lld\n",selisih[i]);
		cnt++;
		if(sum <= m){break;}
	}
	if(sum > m){
		printf("-1\n");
	}else{
		printf("%d\n",cnt);
	}

	return 0;
};