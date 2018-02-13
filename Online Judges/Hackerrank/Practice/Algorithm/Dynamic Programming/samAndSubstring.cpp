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

const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;

int main(){
	string kata;
	int i,j,n;
	cin>>kata;
	n = kata.length();
	ll pengali[maxn];
	pengali[n-1] = 1;
	for(i=n-2;i>=0;i--){
		pengali[i] = pengali[i+1]*10 + 1;
		pengali[i]%=mod;
		// printf("pengali[%d]: %lld\n",i,pengali[i]);
	}
	ll ans = 0;
	for(i=0;i<n;i++){
		ll bil = kata[i]-'0';
		ll jawaban = ((bil%mod*pengali[i]%mod)%mod*(i+1)%mod)%mod;
		ans+=jawaban;
		ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
};