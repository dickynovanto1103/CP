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

const ll mod = 1e9 + 9;

ll modPow(ll a, ll b) {
	if(b==0){
		return 1;
	}else{
		if(b%2==1){return (a*modPow(a,b-1)) % mod;}
		else{
			ll temp = modPow(a,b/2);
			return (temp*temp)%mod;
		}
	}
}

ll modInverse(ll a) {
	return modPow(a,mod-2);
}

const int maxn = 1e5 + 5;

int main(){
	int n,k,i,j,a,b;
	int flag[maxn];
	scanf("%d %d %d %d",&n,&a,&b,&k);
	string kata;
	cin>>kata;
	for(i=0;i<kata.length();i++){
		if(kata[i] == '+'){flag[i] = 1;}
		else{flag[i] = -1;}
	}
	
	//hitung yang series sebanyak k
	ll sum1 = 0;
	for(i=0;i<k;i++){
		ll ans = (flag[i]*((modPow(a,k-i-1)%mod)*(modPow(b,i)%mod)) %mod);
		// printf("pangkata: %d pangkatb: %d\n",k-i-1, i);

		sum1+=ans;
		sum1%=mod;
		// printf("ans: %lld sum1 jd: %lld\n",ans,sum1);
	}


	ll sum2 = 0;
	ll bilAwal = modPow(a,n+1-k);
	// printf("pangkatBilAwal: %d jadi bilAwal: %lld\n",n+1-k,bilAwal);
	ll r = ((modPow(b,k)%mod) * (modInverse(modPow(a,k))%mod)) %mod;
	// printf("r: %lld\n", r);
	
	if(r==1){sum2 = (n+1)/k;}
	else{

		ll pembilang = bilAwal;
		ll bil2 = (modPow(r,(n+1)/k) - 1);
		if(bil2<0){bil2+=mod;}
		pembilang*=bil2;
		pembilang%=mod;

		ll penyebut = r-1;
		if(penyebut<0){penyebut+=mod;}
		penyebut%=mod;

		sum2 = (pembilang*modInverse(penyebut)) %mod;
	}
	
	ll ans = (sum1*sum2)%mod;
	if(ans<0){ans+=mod;}
	printf("%lld\n",ans);
	return 0;
};

//input: 2 2 3 3
// +-+
//output: 7

//input: 4 1 5 1
// -
//output: 999999228