#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll modPow(ll a, ll b, ll n){
	if(b==0){return 1;}
	else{
		if(b%2==0){
			ll temp = modPow(a,b/2,n);
			return ((temp%n)*(temp%n))%n;
		}else{
			return ((a%n)*(modPow(a,b-1,n)%n))%n;
		}
	}
}

int main(){
	ll a,b,c,n;
	cin>>a>>b>>c>>n;
	ll hasilmod = a;
	for(int i=0;i<c;i++){
		hasilmod = modPow(hasilmod,b,n);
	}
	hasilmod%=n;
	hasilmod++;
	cout<<hasilmod<<endl;
	return 0;
};