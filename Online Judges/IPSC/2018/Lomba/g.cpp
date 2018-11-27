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

const ll mod = 1e9 + 7;

int main(){
	string kata;
	ll ans = 0;
	while(cin>>kata){
		int i;
		for(i=0;i<kata.length();i++){
			ans += (kata[i]*(i+1));
			ans %= mod;
		}
		printf("i+1 akhir: %d\n",i+1);
		ans += ((i+1)*10);
		ans %= mod;
	}
	printf("%lld\n",ans);
	return 0;
};