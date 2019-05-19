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

const ll mod = 998244353;
const int maxn = 1e6 + 6;

ll fac[maxn];

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2){return a*modPow(a,b-1)%mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

ll c(ll n, ll x) {
	ll atas = fac[n];
	ll bawah = fac[x]*fac[n-x];
	bawah%=mod;
	return atas*modPow(bawah, mod-2)%mod;
}

int main(){
	int n,i,j;
	vi listBil;
	scanf("%d",&n);
	if(n == 1){printf("1\n"); return 0;}
	else if(n == 2){printf("2\n"); return 0;}
	else if(n == 3){printf("9\n"); return 0;}
	fac[0] = 1;
	for(i=1;i<maxn;i++){
		fac[i] = fac[i-1]*(ll)i;
		fac[i] %= mod;
	}
	ll ans = fac[n];
	for(i=1;i<=n-3;i++){
		ll tambahan = (fac[n-i] - 1);
		ll pengali = fac[n]*modPow(fac[n-i], mod-2);
		pengali%=mod;
		tambahan*=pengali;
		// printf("tambahan: %lld\n",tambahan);
		tambahan%=mod;
		ans += tambahan;
		// printf("ans jd: %lld\n",ans);
		ans %= mod;
	}
	ll tambahan = fac[n-1];
	// printf("tambahan awal: %lld\n",tambahan);
	tambahan *= modPow(2, mod-2);
	tambahan %= mod;
	tambahan *= n;
	tambahan %= mod;
	// printf("tambahan: %lld\n",tambahan);
	ans += tambahan;
	// printf("ans Final: %lld\n",ans);
	ans %= mod;
	if(ans < 0){ans += mod;}
	printf("%lld\n",ans);
	// for(i=1;i<=n;i++){
	// 	listBil.pb(i);
	// }
	// vi a;
	// do{

	// 	for(i=0;i<n;i++){
	// 		printf("%d ",listBil[i]);
	// 		a.pb(listBil[i]);
	// 	}
	// 	printf("\n");

	// }while(next_permutation(listBil.begin(), listBil.end()));
	
	// int pref[100000];
	// memset(pref, 0, sizeof pref);
	// for(i=0;i<a.size();i++){
	// 	pref[i] = a[i];
	// 	if(i > 0){pref[i] += pref[i-1];}
	// }
	// int kiri = 0, kanan = n-1;
	// int harapan = (n*(n+1))/2;
	// printf("harapan: %d\n",harapan);
	// int cnt = 0;
	// vector<string> listString;
	// for(i=0;i<a.size();i++){
	// 	if(kiri > 0){
	// 		if(pref[kanan] - pref[kiri-1] == harapan){
	// 			if(kiri%n != 0){
	// 				printf("%d %d -> ",kiri, kanan);
	// 				string kata = "";
	// 				for(j=kiri;j<=kanan;j++){printf("%d ",a[j]); kata += (a[j] + '0'); kata += " ";}
	// 				listString.pb(kata);
	// 				printf("\n");
					
	// 			}
	// 			cnt++;	
	// 		}
	// 	}else{
	// 		if(pref[kanan] == harapan){
	// 			if(kiri%n != 0){
	// 				printf("%d %d\n",kiri, kanan);	
	// 				string kata = "";
	// 				for(j=kiri;j<=kanan;j++){printf("%d ",a[j]);kata += (a[j] + '0'); kata += " ";}
	// 				listString.pb(kata);
	// 				printf("\n");
					
	// 			}
	// 			cnt++;
				
	// 		}
	// 	}
	// 	kiri++; kanan++;
	// 	if(kanan >= a.size()){break;}
	// }

	// sort(listString.begin(), listString.end());
	// set<string> s;
	// string cur = "";
	// int counter = 0;
	// for(i=0;i<listString.size();i++){
	// 	if(cur != listString[i]){
	// 		printf("ada: %d\n", counter);
	// 		counter = 1;
	// 		cur = listString[i];
	// 		cout<<listString[i]<<" ";	

	// 	}else{
	// 		counter++;
	// 	}
	// 	// cout<<listString[i]<<endl;
	// }
	// int fac[12];
	// fac[0] = 1;
	// for(i=1;i<=n;i++){
	// 	fac[i] = i*fac[i-1];
	// }
	// printf("ada: %d\n",counter);
	// printf("tot %d\n",cnt);

	return 0;
};