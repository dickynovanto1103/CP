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
	int tc,i,j;
	string a,b;
	scanf("%d",&tc);
	while(tc--){
		cin>>a>>b;
		//cari hasil mod a dengan mod
		int pjgA = a.length();
		ll sumA = 0;
		for(i=0;i<pjgA;i++){
			int angka = a[i]-'0';
			sumA*=10;
			sumA+=angka;
			sumA%=mod;
		}

		int pjgB = b.length();
		ll sumB = 0;
		for(i=0;i<pjgB;i++){
			int angka = b[i] - '0';
			sumB*=10;
			sumB+=angka;
			sumB%=(mod-1);
		}

		printf("%lld\n",modPow(sumA,sumB));
	}
	return 0;
};