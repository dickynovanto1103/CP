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
	ll tc,l,r,j,x;
	string kata;
	scanf("%lld",&tc);
	while(tc--){
		scanf("%lld %lld %lld %lld",&l,&r,&j,&x);
		cin>>kata;
		ll biaya = l*r*j;
		ll untung = x-biaya;
		if(kata=="bayar"){printf("%lld\n",untung);}
		else{printf("%lld\n",-biaya);}
		//cout<<kata<<" "<<x<<endl;
	}
	return 0;
}