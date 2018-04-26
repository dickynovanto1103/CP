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

const ll mod = 1e6;

struct matrix{
	void init(ll k, ll l){
		m[0][0] = k%mod;
		m[0][1] = l%mod;
		m[1][0] = 1;
		m[1][1] = 0;
	}
	void identity(){
		m[0][0]=m[1][1] = 1;
		m[0][1]=m[1][0] = 0;
	}
	friend matrix operator*(matrix& a, matrix&b){
		matrix w;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				w.m[i][j] = 0;
				for(int k=0;k<2;k++){
					w.m[i][j] += a.m[i][k]*b.m[k][j];
					w.m[i][j] %= mod;
				}
			}
		}
		return w;
	}
	ll m[2][2];
};

matrix p[60];

void print(ll a){
	printf("%06lld\n", a);
}

int main(){
	ll n,k,l;
	scanf("%lld %lld %lld", &n, &k, &l);
	n/=5;
	if(n==1){
		print(k);
		return 0;
	}
	p[0].init(k, l);
	for(int i=1;i<60;i++)
		p[i] = p[i-1]*p[i-1];
	matrix res;
	res.identity();
	for(int i=0;n;i++){
		if(n&1){
			res = res*p[i];
		}
		n>>=1;
	}
	print(res.m[0][0]);
	return 0;
};