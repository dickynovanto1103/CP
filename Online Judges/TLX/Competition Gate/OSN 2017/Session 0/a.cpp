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
	int n,i,j;
	ll a[100010];
	string dummy;
	cin>>dummy;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	
	ll cnt = 0;
	ll bil = a[0], idxAwal = 0;
	for(i=1;i<n;i++){
		if(bil!=a[i]){
			ll selisih = i-idxAwal;
			cnt+=((selisih * (selisih+1)) / 2);
			bil = a[i];
			idxAwal = i;
		}
	}
	ll selisih = i-idxAwal;
	cnt+=((selisih * (selisih+1)) / 2);
	printf("%lld\n",cnt);
	return 0;
}