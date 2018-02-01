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

ll fac[15];

ll c(ll a, ll b){
	return fac[a]/(fac[a-b]*fac[b]);
}

int main(){
	int tc,i,j,p,q;
	string kata;
	
	fac[0] = 1;
	for(i=1;i<=10;i++){fac[i] = i*fac[i-1];}
	scanf("%d",&tc);
	while(tc--){
		int banyakVowel = 0, banyakKonsonan = 0;
		cin>>kata;
		for(i=0;i<kata.length();i++){
			char kar = kata[i];
			if(kar=='a' || kar=='i' || kar=='e' || kar=='u' || kar=='o'){banyakVowel++;}
			else{banyakKonsonan++;}
		}
		scanf("%d %d",&p,&q);
		ll ans = c(banyakKonsonan,p)*c(banyakVowel,q)*fac[p+q];
		printf("%lld\n",ans);
	}
	

	return 0;
};