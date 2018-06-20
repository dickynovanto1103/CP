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

ll gcdExtended(ll a, ll b, ll &x, ll &y) {
	if(a==0){
		x = 0;
		y = 1;
		return b;
	}
	ll x1,y1;
	int nilaiGCD = gcdExtended(b%a, a, x1, y1);
	x = y1 - (b/a)*x1;
	y = x1;
	return nilaiGCD;
}

ll gcdExtended1(ll a, ll b, ll &x, ll &y) {
	if(a==0){
		x = 0;
		y = 1;
		return b;
	}
	ll x1,y1;
	int nilaiGCD = gcdExtended(a%b, a, x1, y1);
	x = y1 + x1;
	y = -1*(a/b)*x1;
	return nilaiGCD;
}


ll gcdExtended2(ll a, ll b, ll &x, ll &y) {
	if(a==0){
		x = 0;
		y = 1;
		return b;
	}
	ll x1,y1;
	int nilaiGCD = gcdExtended(b, a%b, x1, y1);
	x = y1;
	y = x1 - y1*(a/b);
	return nilaiGCD;
}

ll gcdExtended3(ll a, ll b, ll &x, ll &y) {
	if(a==0){
		x = 0;
		y = 1;
		return b;
	}
	ll x1,y1;
	int nilaiGCD = gcdExtended(b, b%a, x1, y1);
	x = -y1*(b/a);
	y = x1 + y1;
	return nilaiGCD;
}


int main(){
	ll a,b;
	while(scanf("%lld %lld",&a,&b)!=EOF){
		ll absis, ordinat;
		ll x[4], y[4];

		ll d = gcdExtended(a,b,x[0],y[0]);
		// gcdExtended1(a,b,x[1],y[1]);
		gcdExtended2(a,b,x[2],y[2]);
		// gcdExtended3(a,b,x[3],y[3]);
		ll minim = (ll)inf*100LL;
		for(int i=0;i<4;i++){
			if(abs(x[i] + y[i]) < minim) {
				absis = x[i]; ordinat = y[i];
			}else if(abs(x[i] + y[i]) == minim){
				if(x[i] <= y[i]) {
					absis = x[i], ordinat = y[i];
				}
			}
		}
		// absis = x[2]; ordinat = y[2];
		printf("%lld %lld %lld\n",absis,ordinat,d);	
	}
	
	return 0;
};