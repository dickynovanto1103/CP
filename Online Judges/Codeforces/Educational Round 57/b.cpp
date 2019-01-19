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

const int maxn = 2e5 + 5;

const ll mod = 998244353;

int main(){
	int n,i,j;
	string kata;
	scanf("%d",&n);
	cin>>kata;
	int a[maxn];
	for(i=0;i<n;i++){
		a[i] = kata[i] - 'a';
	}
	bool isAllSame = true;
	int patokan = a[0];
	for(i=0;i<n;i++){
		if(a[i] != patokan) {isAllSame = false; break;}
	}
	ll ans = 0;
	if(isAllSame){
		ans = ((ll)n*(ll)(n+1LL))/2LL;
		ans %= mod;
		printf("%lld\n",ans);
		return 0;
	}
	if(a[0] == a[n-1]) {
		//cari tengah
		ll banyakKiri = 0;
		for(i=0;i<n;i++){
			if(a[i] == a[0]){banyakKiri++;}
			else{break;}
		}
		ll banyakKanan = 0;
		for(i=n-1;i>=0;i--){
			if(a[i] == a[0]){banyakKanan++;}
			else{break;}
		}
		ans = (banyakKanan + 1LL) * (banyakKiri+1LL);
		ans %= mod;
		
	}else{
		ll banyakKiri = 0;
		int idxKiri = 0;
		for(i=0;i<n;i++){
			if(a[i] == a[0]){banyakKiri++;}
			else{idxKiri = i; break;}
		}
		ll banyakKanan = 0;
		int idxKanan = 0;
		for(i=n-1;i>=0;i--){
			if(a[i] == a[n-1]){banyakKanan++;}
			else{idxKanan = i;break;}
		}
		ans = banyakKanan + banyakKiri + 1;
		ans %= mod;
	}

	printf("%lld\n",ans);

	return 0;
};