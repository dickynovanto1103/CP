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



int main(){
	int tc,n,i,j;
	ll a[7500];
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		scanf("%d",&n);
		ll jumlah0 = 0;
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
			if(a[i] == 0){
				jumlah0++;
			}
		}
		ll ans = 0;
		
		sort(a,a+n);
		
		int cnt[200010];
		
		cerr<<"done preprocess"<<endl;
		memset(cnt, 0, sizeof cnt);
		for(i=n-1;i>=0;i--){
			for(j=0;j<i;j++){
				if(a[i] == 0 || a[j] == 0){continue;}
				ll kali = a[i]*a[j];
				if(kali > 200000){continue;}
				ans += cnt[kali];
			}
			cnt[a[i]]++;
		}
		ans += (jumlah0*(jumlah0-1)*(jumlah0-2))/6LL;
		ans += (jumlah0*(jumlah0-1)/2LL)*(n-jumlah0);
		cerr<<"case "<<tt<<endl;	
		printf("Case #%d: %lld\n",tt,ans);
	}
	return 0;
};