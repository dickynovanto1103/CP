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
const int maxn = 1e5 + 5;
ll fac[maxn];

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

ll invMod(ll a){
	return modPow(a, mod-2);
}

int main(){
	int tc,i,j;

	fac[0] = 1;

	for(i=1;i<maxn;i++){
		fac[i] = i*fac[i-1];
		fac[i]%=mod;
	}

	scanf("%d",&tc);
	// printf("tc: %d\n",tc);
	string word;
	getline(cin,word);
	while(tc--){
		int n = 0;
		string kata;
		getline(cin, kata);

		for(i=4;i<kata.length();i++){
			char kar = kata[i];
			int bil = kar - '0';
			n*=10; n+=bil;
		}

		ll ans = fac[n-1];
		// printf("ans: %lld n: %d\n",ans,n);
		getline(cin,kata);

		int bil = 0;
		for(i=8;i<kata.length();i++){
			char kar = kata[i];
			if(kar == ' '){
				//bagi dulu
				ans*=invMod(bil-1);
				ans%=mod;
				// printf("bil :%d\n",bil);
				// printf("ans jd: %lld\n",ans);
				bil = 0;
			}else{
				bil*=10;
				bil+=(kar - '0');
				// printf("bil jd: %d\n",bil);
			}
		}
		if(bil!=0){
			ans*=invMod(bil-1);
			ans%=mod;	
		}
		
		// printf("ans final: %lld\n",ans);
		printf("%lld\n",ans);

		getline(cin,kata);
	}
	return 0;
};