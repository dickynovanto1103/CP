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

ll modPow(ll a, ll b){
	if(b == 0){
		return 1;
	}else{
		if(b%2==1){return (a*modPow(a,b-1))%mod;}
		else{
			ll temp = modPow(a,b/2);
			return (temp*temp)%mod;
		}
	}
}

int main(){
	string kata;
	ll sum = 0;
	cin>>kata;
	for(int i=0;i<kata.length();i++){
		char kar = kata[i];
		int bil = kar-'0';
		sum*=10;
		sum %= (mod-1);
		sum += bil;
		sum %= (mod-1);
	}
	printf("%lld\n",modPow(2,sum));
	return 0;
};