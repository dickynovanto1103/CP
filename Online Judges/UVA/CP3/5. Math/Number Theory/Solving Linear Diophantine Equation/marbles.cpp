#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll x,y,d;

void extendedEuclid(ll a, ll b){
	if(b==0){x=1; y=0; d=a; return;}
	extendedEuclid(b,a%b);
	ll x1 = y;
	ll y1 = x - (a/b)*y;
	x = x1; y = y1;
}

int main() {
	ll n,n1,n2,c1,c2;
	while(scanf("%lld",&n),n){
		scanf("%lld %lld",&c1,&n1);
		scanf("%lld %lld",&c2,&n2);
		extendedEuclid(n1,n2);
		if(n%d!=0){printf("failed\n");}
		else{
			if(y<0){swap(x,y);}
			ll pengali = n/d;
			ll xbaru = x*pengali, ybaru = y*pengali;
			ll koefX = n2/d, koefY = n1/d;
			/*printf("xbaru: %lld ybaru: %lld\n",xbaru,ybaru);
			printf("koefX: %lld koefY: %lld\n",koefX,koefY);*/
			ll bawah, atas;
			if(xbaru%koefX==0){bawah = abs(xbaru)/koefX;}
			else{bawah = abs(xbaru)/koefX + 1;}
			atas = ybaru/koefY;
			printf("xbaru: %lld ybaru: %lld\n",xbaru,ybaru);
			printf("koefX: %lld koefY: %lld\n",koefX,koefY);
			printf("bawah: %lld atas: %lld\n",bawah,atas);
			//double bawah = abs(xbaru)/(double)koefX, atas = abs(ybaru)/(double)koefY;
			//ll bawahLL = (ll)ceil(bawah), atasLL = (ll)floor(atas);
			bool keAtas = (c1<c2)? true:false;
			ll biaya = inf;
			ll kiri = bawah, kanan = atas, mid;
			ll jawab1,jawab2;
			if(keAtas){
				for(ll i=kanan;i>=kiri;i--){
					ll ans1 = xbaru + koefX*i, ans2 = ybaru-(koefY*i);
					ll jumlah = (n1*ans1 + n2*ans2);
					printf("ans1: %lld ans2: %lld\n",ans1,ans2);
					printf("jumlah: %lld\n",jumlah);
					if(jumlah==n){
						jawab1 = ans1, jawab2 = ans2;
						printf("masuk turun\n");
						break;
					}
				}
			}else{
				for(ll i=kiri;i<=kanan;i++){
					ll ans1 = xbaru + koefX*i, ans2 = ybaru-(koefY*i);

					ll jumlah = (n1*ans1 + n2*ans2);
					if(jumlah==n){
						jawab1 = ans1, jawab2 = ans2;
						printf("masuk naik\n");
						break;
					}	
				}
			}
			
			/*while(kiri<=kanan){
				mid = (kiri+kanan)/2;
				ll ans1 = xbaru + koefX*mid, ans2 = ybaru-(koefY*mid);
				ll jumlah = (n1*ans1 + n2*ans2);
				if(jumlah==n){
					jawab1 = ans1, jawab2 = ans2;
					if(keAtas){kiri = mid+1;}
					else{kanan = mid-1;}
					
				}else if(jumlah < n){
					kiri = mid+1;
				}else{
					kanan = mid-1;
				}
			}*/
			printf("%lld %lld\n",jawab1,jawab2 );
		}
	}
	return 0;
}