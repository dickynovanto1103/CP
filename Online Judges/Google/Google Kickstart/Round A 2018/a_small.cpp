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

bool isAllGenap(ll n){
	
	while(n>0){
		ll bil = n%10;
		if(bil%2==1){return false;}
		n/=10;
	}
	return true;
}

int main(){
	int tc,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		cerr<<"case "<<tt<<"done"<<endl;
		ll n;
		scanf("%lld",&n);
		//naik dulu
		ll i;
		ll banyakAtas = 0;
		for(i=0;;i++){
			ll bil1 = n+i;
			if(isAllGenap(bil1)){banyakAtas = i;break;}
			


		}
		ll banyakBawah;
		for(i=0;;i++){
			ll bil = n-i;
			if(isAllGenap(bil)){banyakBawah = i; break;}
		}
		printf("%lld\n",min(banyakBawah,banyakAtas));
	}
	return 0;
};