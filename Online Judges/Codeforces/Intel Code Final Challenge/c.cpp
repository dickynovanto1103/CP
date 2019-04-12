#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
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
	int n,m,k,i,j;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<k;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		if(n == m){
			if(x == y){printf("%d\n",x);}
			else{printf("-1\n");}
			continue;
		}
		int posX[2], posY[2];
		posX[0] = x, posX[1] = 2*n - x;
		posY[0] = y, posY[1] = 2*m - y;
		ll ans = inf;
		for(j=0;j<2;j++){
			for(int l=0;l<2;l++){
				int koef1 = 2*n, koef2 = 2*m;
				int c = posY[l] - posX[j];
				int g = __gcd(koef1, koef2);
				koef1 /= g; koef2 /= g;
				if(c%g != 0){
					continue;
				}else{
					c /= g;	
				} 
				int a,b;
				if(find_any_solution(koef1, -koef2, c,a,b,g)) {
					// printf("posX: %d posY: %d a: %d b: %d g: %d\n",posX[j],posY[l],a,b,g);
					int pengali;
					if(a >= 0 && b >= 0){
						pengali = (-a) / (-koef2);
								
					}else if(a <0 && b < 0){
						int bagi1 = (-a / (-koef2)) + (-a%(-koef2) == 0 ? 0 : -1);
						int bagi2 = (-b / (-koef1)) + (-b%(-koef1) == 0 ? 0 : -1);
						pengali = min(bagi1, bagi2);	
					}

					ll x = a + (ll)pengali*(-koef2);
					assert(x >= 0);
					ll jawab = x*2LL*(ll)n + (ll)posX[j];
					if(jawab < 0){continue;}
					ans = min(ans, jawab);
				}
			}
		}
		if(ans == inf){printf("-1\n");}
		else{printf("%lld\n",ans);}
	}
	return 0;
};