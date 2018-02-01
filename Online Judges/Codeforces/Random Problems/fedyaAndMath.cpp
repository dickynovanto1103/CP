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

const ll mod = 5;

ll modPow(ll a, ll b){
	if(b==0){return 1;}
	else{
		if(b%2==1){
			return (a*modPow(a,b-1))%mod;
		}else{
			ll temp = modPow(a,b/2);
			return (temp*temp)%mod;
		}
	}
}

int main(){
	string kata;
	int i,j,n;
	cin>>kata;
	int pjg = kata.length();
	int pangkat = 0;
	for(i=0;i<pjg;i++){
		int bil = kata[i]-'0';
		pangkat*=10; pangkat+=bil;
		pangkat%=(mod-1);
	}
	ll ans = 0;
	for(i=1;i<=4;i++){
		ans+=(modPow((ll)i,(ll)pangkat));
		ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
};