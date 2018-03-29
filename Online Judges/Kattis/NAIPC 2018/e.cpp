#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
 
const ll mod = 1e9+7;
const double pi = acos(-1);

int n,j,i,k,m;
ll a, sum, b;
string s[51], t;
bool belum[1000001];
ll fac[1000001];

ll modPow(ll a, ll b) {
	if(b==0){return 1;}
	else{
		if(b%2==1){return (a*modPow(a,b-1)) %mod;}
		else{
			ll temp = modPow(a,b/2);
			return (temp*temp)%mod;
		}
	}
}

ll invFac(ll n) {
	return modPow(n,mod-2);
}

ll nCr(ll n, ll r) {
	return ((fac[n]%mod*invFac(fac[r])%mod)%mod * invFac(fac[n-r])%mod)%mod;
}

int stringcmp(int a, int b){
	int i;
	for(i=0;i<s[a].size()&&i+b<t.size();i++){
		if(s[a][i]!=t[i+b])
			return s[a][i]-t[i+b];
	}
	return i!=s[a].size();
}

int find(int st){
	int l =0;
	int r = n-1;
	int mid = (l+r)>>1;
	while(l<r){
		int cmp = stringcmp(mid, st);
		if(cmp < 0)
			l = mid+1;
		else if(cmp > 0)
			r = mid-1;
		else
			l = r=mid;
		mid = (l+r)>>1;
	}
	return l;
}

int main(){
	//section factorial
	fac[0] = 1;
	
	for(ll i=1;i<=1000000;i++){
		fac[i] = i*fac[i-1];
		fac[i]%=mod;
	}
	memset(belum, true, sizeof belum);
	scanf("%d %d", &n, &m);
	for(i=0;i<n;i++)
		cin>>s[i];
	cin>>t;
	sort(s, s+n, [](const string&a, const string& b){
		int i;
		for(i=0;i<a.size()&&i<b.size();i++){
			if(a[i]!=b[i])
				return a[i]<b[i];
		}
		return a.size() < b.size();
	});
	a = n-1;
	b = m-1;
	// for(i=0;i<n;i++)
		// cout<<s[i]<<endl;
	for(i=0;i<t.size();){
		ll idx = find(i);
		cout<<i<<" "<<idx<<endl<<flush;
		if(a>0){
			ll ans = (((idx)%mod * nCr(a, b)%mod)%mod * fac[b]%mod)%mod;
			sum += ans;
			sum%=mod;
			a--;
			b--;
			printf("sum jd: %lld\n",sum);
		}
		else{
			for(j=0;j<=idx;j++){
				if(belum[j]){
					sum++; sum%=mod;
				}

			}
		}
		i += s[idx].size();
		belum[idx] = false;
		sum%=mod;
	}
	printf("%lld\n", sum);
	return 0;
}

//3 1 4
