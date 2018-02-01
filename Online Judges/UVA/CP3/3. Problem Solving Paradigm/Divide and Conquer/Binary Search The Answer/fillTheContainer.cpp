#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,m,i,j;
	ll a[1000];
	while(scanf("%d %d",&n,&m)!=EOF){
		for(i=0;i<n;i++){scanf("%lld",&a[i]);}
		ll kanan = inf, kiri = 0, mid;
		ll ans;
		while(kiri<=kanan){
			mid = (kiri+kanan)/2;
			//cek dengan mid muat atau ga
			i=0; j=0;
			while(i<m && j<n){
				ll isi = mid;
				while(isi-a[j]>=0 && j<n){isi-=a[j]; j++;}
				if(j<n){i++;}//sudah ga cukup..ganti container
				
				//if(isi-ves>=0){isi-=ves; j++;}
				//else{i++;}
			}
			if(i<m){ans = mid ;kanan = mid-1;}//total container sekarang cukup untuk menampung semua a[]
			else{kiri = mid+1;}//ga cukup
		}
		printf("%lld\n",ans);
	}
	return 0;
}