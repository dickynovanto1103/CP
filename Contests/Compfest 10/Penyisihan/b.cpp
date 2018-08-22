#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int s, d, r;

long double modi(long double x){
	double pengurangan = 4.0 * s;
	if(x >= pengurangan){
		int loop = floor(x/pengurangan);
		double titikSekarang = x - pengurangan*(double)loop;
		
		double titikKeBawah = 2.0*s - titikSekarang;
		if(titikKeBawah >= -s && titikKeBawah <= s){
			return titikKeBawah;
		}
		double selisihTinggi = fabs(s - titikKeBawah);
		double titikKeAtas = titikKeBawah + 2*selisihTinggi;
		return titikKeAtas;
	}else{
		double titikKeBawah = 2.0*s - x;
		if(titikKeBawah >= -s && titikKeBawah <= s){
			return titikKeBawah;
		}
		double selisihTinggi = fabs(s - titikKeBawah);
		double titikKeAtas = titikKeBawah + 2*selisihTinggi;
		return titikKeAtas;
	}
}

int main(){
	scanf("%d", &t);
	for(int cc=1;cc<=t;++cc){
		scanf("%d %d", &n, &s);
		long double x=0, y=0;
		for(i=0;i<n;++i){
			scanf("%d %d", &d, &r);
			x += r*cos(pi*d/180.0);
			y += r*sin(pi*d/180.0);
			// cout<<x<<" "<<y<<endl;
			if(x < -s)
				x = -modi(fabs(x));
			else if(x > s)
				x = modi(x);
			if(y < -s)
				y = -modi(fabs(y));
			else  if(y > s)
				y = modi(y);
			// cout<<x<<" "<<y<<endl;
		}
		printf("%.9Lf %.9Lf\n", x, y);
	}
	return 0;
}