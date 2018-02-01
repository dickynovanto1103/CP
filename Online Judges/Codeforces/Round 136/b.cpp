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

set<int> s1,s2;

void parse(ll n){
	while(n>0){
		ll bil = n%10;
		s1.insert(bil);
		n/=10;
	}
}

int main(){
	ll n,i,j;
	scanf("%lld",&n);
	parse(n);
	int cnt = 0;
	for(i=1;i*i<=n;i++){
		if(n%i==0){
			ll bil1 = i;
			ll bil2 = n/i;
			if(bil1==bil2){
				while(bil1>0){
					ll bilangan = bil1%10;
					if(s1.count(bilangan)){cnt++; break;}
					bil1/=10;
				}
			}else{
				while(bil1>0){
					ll bilangan = bil1%10;
					if(s1.count(bilangan)){cnt++; break;}
					bil1/=10;
				}

				while(bil2>0){
					ll bilangan = bil2%10;
					if(s1.count(bilangan)){cnt++; break;}
					bil2/=10;
				}
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
};