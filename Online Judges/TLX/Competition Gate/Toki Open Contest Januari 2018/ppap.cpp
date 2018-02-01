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

int main(){
	int n,i,j;
	string kata;
	scanf("%d",&n);
	cin>>kata;
	int cntP = 0;
	for(i=0;i<n;i++){
		char kar = kata[i];
		if(kar=='P'){
			cntP++;
		}
	}
	int cnt = 0;
	vi a,b;
	
	for(i=0;i<n;i++){
		char kar = kata[i];
		if(kar=='P'){
			cnt++;
		}else{
			a.pb(cnt);
			b.pb(cntP-cnt);
		}
	}
	ll ans = 0;
	for(i=0;i<a.size();i++){
		ll banyak1 = a[i];
		ll banyak2 = b[i];
		ll banyakKombinasi1 = banyak1*(banyak1-1);
		ll banyakKombinasi2 = banyak2;
		// printf("banyak1: %lld banyak2: %lld\n",banyak1,banyak2);
		if(banyakKombinasi1>0 && banyakKombinasi2>0){
			ll total = banyakKombinasi1/2LL;
			total*=banyakKombinasi2;
			ans+=(total);
			ans%=mod;
			// ans*=(banyakKombinasi2);
			// ans%=mod;	
		}
		
		
	}
	printf("%lld\n",ans);
	return 0;
};