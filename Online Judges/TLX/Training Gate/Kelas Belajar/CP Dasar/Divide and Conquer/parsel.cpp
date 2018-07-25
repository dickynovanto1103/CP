#include <bits/stdc++.h>

using namespace std;
#define inf 9e18
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll n,m,a[1<<18],i;	

int main() {
	
	scanf("%lld %lld",&n,&m);
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	ll kiri = 0, kanan = inf;
	//printf("kanan: %lld\n",kanan);
	//cari batas bawah dulu..jd klo sama ...cari yg lebih rendah
	//printf("test\n");
	ll bawah = inf,atas = -inf;
	while(kiri<=kanan){
		ll mid = (kiri+kanan)/2;
		ll tot = 0;
		for(i=0;i<n;i++){tot+=(mid/a[i]); if(tot>m){break;}}
		if(tot>m){kanan = mid-1;}//kecilkan mid nya
		else if(tot<m){kiri = mid+1;}
		else{bawah = mid; kanan = mid-1;}
	}
	kiri = 0; kanan = inf;
	//cari batas atas
	while(kiri<=kanan){
		ll mid = (kiri+kanan)/2;
		ll tot = 0;
		for(i=0;i<n;i++){tot+=(mid/a[i]); if(tot>m){break;}}
		if(tot>m){kanan = mid-1;}//kecilkan mid nya
		else if(tot<m){kiri = mid+1;}
		else{atas = mid; kiri = mid+1;}
	}
	//printf("atas: %lld bawah: %lld\n",atas,bawah);
	ll ans = atas-bawah+1;
	if(bawah==inf && atas==-inf){ans = 0;}
	printf("%lld\n",ans);
	return 0;
}