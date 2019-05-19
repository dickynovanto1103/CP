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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}


int main(){
	ll fib[200];
	fib[0] = 1;
	fib[1] = 1;
	ll x[100], y[100];
	x[0] = 1; x[1] = 0;
	y[0] = 0; y[1] = 1;
	int i,j;
	for(i=2;i<100;i++){
		fib[i] = fib[i-1] + fib[i-2];
		x[i] = x[i-1] + x[i-2];
		y[i] = y[i-1] + y[i-2];
	}
	int n,tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		ii ans = ii(inf,inf);
		for(i=2;i<100;i++){
			if(fib[i] == n){ans = min(ans, ii(1,1)); break;}
			else if(fib[i] < n){
				ll c = n - fib[i];
				ll x0, y0;
				ll koef1 = x[i], koef2 = y[i];
				ll g;

				if(find_any_solution(koef1, koef2, c, x0, y0, g)) {
					ll pengali;
					ll minim = (-x0*g)/koef2;
					if(x0%koef2 != 0 && x0 < 0){
						minim++;
					}
					ll maks = y0*g/koef1;
					if((y0*g) % koef1 != 0 && y0 < 0){
						maks--;
					}
					ll x,y;
					if(minim > maks){continue;}
					pengali = minim;
					ii jawab = ii(inf,inf);
					ll kiri = minim, kanan = maks, mid, jawaban=kiri;
					while(kiri <= kanan) {
						mid = (kiri+kanan)/2;
						x = x0 + koef2*mid/g;
						y = y0 - koef1*mid/g;
						if(x > y){
							kanan = mid-1;
						}else{
							jawaban = mid;
							kiri = mid+1;
						}
					}
					x = x0 + koef2*jawaban/g;
					y = y0 - koef1*jawaban/g;	
					if(x > y){continue;}
					if(ans.second > y+1){
						ans = ii(x+1, y+1);
						continue;
					}else if(ans.second == y+1){
						if(ans.first > x+1){
							ans = ii(x+1, y+1);
							continue;
						}
					}
				}
			}else{
				break;
			}
		}
		printf("%lld %lld\n",ans.first, ans.second);
	}
	return 0;
};