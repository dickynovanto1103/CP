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
typedef pair<double,double> dd;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

int up[maxn], down[maxn], n;
ll h[maxn];

void prepareUpAndDown(int a, int b, int u, int d){
	if(a > b){
		swap(a,b); swap(u,d);
	}
	int i,j;
	for(i=a;i<b;i++){
		up[i] = min(up[i], u);
		down[i] = min(down[i], d);
	}
}

bool check(double waktu){
	int i,j;
	double awalKiri = h[0] - waktu, awalKanan = h[0] + waktu;
	double kiri = awalKiri, kanan = awalKanan;
	for(i=0;i<(n-1);i++){
		kiri = max(kiri - down[i], h[i+1] - waktu);
		kanan = min(kanan + up[i], h[i+1] + waktu);
		if(kiri > kanan){return false;}
	}
	return true;
}

int main(){
	int tc,m,i,j;
	scanf("%d",&tc);
	
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d",&n,&m);
		ll w,x,y,z;
		scanf("%lld %lld",&h[0],&h[1]);
		scanf("%lld %lld %lld %lld",&w,&x,&y,&z);
		
		for(i=2;i<n;i++){
			h[i] = (w*h[i-2] + x*h[i-1] + y)%z;
			// printf("h[%d]: %lld\n",i,h[i]);
		}
		fill(up, up+maxn, inf); fill(down, down+maxn, inf);
		for(i=0;i<m;i++){
			int a,b,u,d;
			scanf("%d %d %d %d",&a,&b,&u,&d);
			a--; b--;
			prepareUpAndDown(a, b, u, d);
		}

		double kiri = 0, kanan = 1000000, mid, ans;

		while(fabs(kiri-kanan) > eps){//iterasi 100 kali
			mid = (kiri+kanan)/2.0;
			if(check(mid)){
				ans = mid;
				kanan = mid;
			}else{
				kiri = mid;
			}
		}
		printf("%.9lf\n",ans);
	}
	
	return 0;
};