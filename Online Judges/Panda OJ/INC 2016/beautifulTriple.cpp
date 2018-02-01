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
	int tc,test=1,n;
	ll banyak[100010],jumlah[100010];
	scanf("%d",&tc);
	ll mod = 1000000007;
	while(tc--){
		printf("Case #%d: ",test++);
		scanf("%d",&n);
		memset(banyak,0,sizeof banyak);
		memset(jumlah,0,sizeof jumlah);
		ll ans = 0;
		for(ll i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			ans+=((banyak[bil]*i) - jumlah[bil]-banyak[bil]);
			jumlah[bil]+=i;
			banyak[bil]++;
			if(ans>=mod){ans%=mod;}
		}
		printf("%lld\n",ans);
	}
	return 0;
}