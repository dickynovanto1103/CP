#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tt,tc,i,j;
	ll a,b,c;
	scanf("%d",&tc);
	for(tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%lld %lld %lld",&a,&b,&c);
		ll selisih = b-a+1;
		ll cnt = selisih/c;
		if(selisih<c){
			ll bagiAwal = a%c;
			if(bagiAwal==0){cnt = 1;}
			else{
				ll maks = c-1;
				ll diff = maks-bagiAwal;
				ll bil = a+diff;
				bil++;
				if(bil>=a && bil<=b){cnt = 1;}
				else{cnt = 0;}
			}
		}else if(selisih==c){
			cnt = 1;
		}else{
			if(b%c==0 && a%c==0 && c!=1){cnt++;}
		}
		printf("%lld\n",cnt);
	}
	return 0;
};