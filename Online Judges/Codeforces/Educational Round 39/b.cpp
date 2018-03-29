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

int main(){
	ll a,b;
	scanf("%lld %lld",&a,&b);
	while(true){
		if(a==0 || b==0){printf("%lld %lld\n",a,b); return 0;}
		else{
			if(a>=(2LL*b)){
				ll pengali = a/(2LL*b);
				a-=(pengali*(2LL*b));
			}else if(b>=(2LL*a)){
				ll pengali = b/(2LL*a);
				b-=(pengali*(2LL*a));
			}else{
				printf("%lld %lld\n",a,b); return 0;
			}
		}	
	}	
	
	return 0;
};