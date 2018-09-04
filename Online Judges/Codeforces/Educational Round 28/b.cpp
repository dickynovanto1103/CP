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

const int maxn = 50;

int main(){
	ll n,k,m,i,j;
	scanf("%lld %lld %lld",&n,&k,&m);
	ll a[maxn];
	ll sum = 0;
	for(i=0;i<k;i++){
		scanf("%lld",&a[i]);
		sum += a[i];
	}
	sort(a,a+k);
	//semua ambil yang sebagian"doang
	int maksPoint = 0;
	for(i=0;i<=n;i++){
		int point = 0;
		ll waktuTotal = i*sum;
		if(waktuTotal > m){
			break;
		}else{
			point = i*(k+1);
			ll sisaWaktu = m - waktuTotal;
			//cobain satu"
			ll sisaSoal = n-i;
			for(j=0;j<k;j++){
				ll waktu = sisaSoal*a[j];
				if(sisaWaktu >= waktu){
					sisaWaktu -= waktu;
					point += sisaSoal;
				}else{
					//dapetin point sisa
					point += (sisaWaktu / a[j]);
					break;
				}
			}

			maksPoint = max(maksPoint, point);
		}
	}
	printf("%d\n",maksPoint);
	return 0;
};