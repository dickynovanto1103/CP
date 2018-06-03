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
	int tc,n,k,i;
	string kata;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		cin>>kata;
		int a[1010];
		for(i=0;i<n;i++){
			a[i] = kata[i] - '0';
		}
		ll hasilKali = 0;
		for(i=0;i<=(n-k);i++){
			ll ans = 1;
			for(int j=0;j<k;j++){
				ans*=a[i+j];
			}
			hasilKali = max(hasilKali, ans);
		}

		printf("%lld\n",hasilKali);

	}
	return 0;
};