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

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b % 2 == 1){return a*modPow(a,b-1);}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp;
		}
	}
}

int main(){
	ll a, b;
	scanf("%lld %lld",&a,&b);
	ll bil1 = modPow(2,b);
	ll bil2 = a;
	printf("%lld\n",(bil1 + (bil2-1))/bil2);
	return 0;
};