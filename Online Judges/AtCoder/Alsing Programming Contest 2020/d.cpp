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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll modPow(ll a, ll b, ll c) {
	if(b==0){return 1;}
	else{
		if(b % 2 == 1){
			return a * modPow(a,b-1,c) % c;
		}else{
			ll temp = modPow(a, b/2, c);
			return temp*temp%c;
		}
	}
}

int main(){
	int n,i,j;
	string s;
	cin>>n;
	cin>>s;
	int cnt1 = 0;
	for(i=0;i<s.size();i++){
		if(s[i] == '1'){cnt1++;}
	}
	
	ll bilModMin = 0, bilModPlus = 0;
	int pangkat = 0;
	ll bilBener = 0;

	for(i=n-1;i>=0;i--){
		if(s[i] == '1'){
			bilModPlus += modPow(2, pangkat, cnt1 + 1);
			bilModPlus %= (cnt1 + 1);

			if((cnt1 - 1) > 0){
				bilModMin += modPow(2, pangkat, cnt1 - 1);
				bilModMin %= (cnt1 - 1);
			}
			bilBener += (1LL<<pangkat);
			// printf("bilModMin: %lld bilModPlus: %lld\n",bilModMin, bilModPlus);
			// printf("i: %d bilBener: %lld\n",i, bilBener);
		}
		pangkat++;
		// printf("pangkat: %d bilBener: %lld\n",pangkat, bilBener);
	}

	// printf("bilModPlus: %lld bilModMin: %lld bilBener: %lld\n", bilModPlus, bilModMin,bilBener);

	pangkat = 0;
	vi list;
	for(i=n-1;i>=0;i--){
		ll bil;
		if(s[i] == '1')	{
			bil = bilModMin;
			int mod = cnt1 - 1;
			if(mod == 0){
				bil = 0;
				list.pb(0);
				continue;
			}
			bil -= modPow(2, pangkat, mod);
			bil %= (mod);
			if(bil < 0){bil += mod;}


		}else{
			bil = bilModPlus;
			int mod = cnt1 + 1;
			bil += modPow(2, pangkat, mod);
			bil %= mod;
		}
		// printf("i: %d bil: %lld\n",i, bil);
		pangkat++;
		int ans = 1;
		while(bil){
			int popcount = __builtin_popcount(bil);
			bil = bil % popcount;
			ans++;
		}
		list.pb(ans);
		// printf("%d\n",ans);
	}
	reverse(list.begin(), list.end());
	for(i=0;i<n;i++){
		printf("%d\n",list[i]);
	}
	
	return 0;
};