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
	int n;
	scanf("%d",&n);
	ll ans = 0;
	for(int i=5;i<=7;i++){
		ll jawab = 1;
		int iterasi = i;
	
		
		for(int j=0;j<iterasi;j++){
			jawab*=(ll)(n-j);
			jawab /= (j+1);
		}

		ans += jawab;
	}
	printf("%lld\n",ans);
	return 0;
};