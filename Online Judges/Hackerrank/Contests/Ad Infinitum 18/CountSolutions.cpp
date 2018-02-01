#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;

ll determinan(ll a, ll b, ll c){
	return b*b-4*a*c;
}

int main(){
	map<ll,ll> mapper;
	ll a,b,c,d,i;
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		int ans = 0;
		for(i=1;i<=c;i++){
			ll first = 1;
			ll second = -b;
			ll third = i*i - i*a;
			ll det = determinan(first,second,third);
			if(det>=0){
				double akar = sqrt(det);
				ll akarLL = (ll) ceil(akar);
				//printf("akar: %lf akarll: %lld\n",akar,akarLL);
				if(akarLL == akar){
					ll pembilang1 = -second + akarLL, pembilang2 = -second - akarLL;
					//printf("%lld %lld\n",pembilang1,pembilang2);
					if(pembilang1%2==0){
						pembilang1/=2;
						if(pembilang1>=1 && pembilang1<=d){ans++;}
						// printf("i: %lld ans menjadi: %d di bagian 1\n",i,ans);
					}
					if(pembilang2%2==0 && akarLL!=0){
						pembilang2/=2;//dibagi 2a..dengan a = 1
						if(pembilang2>=1 && pembilang2<=d){ans++;}
					}
				}	
			}
			
		}
		printf("%d\n",ans);
		
	}
	return 0;
}