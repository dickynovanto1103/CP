#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000LL
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

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	int a[maxn], aAsli[maxn];
	int diff[maxn], diffAsli[maxn];
	scanf("%d",&n);
	if(n<=2){printf("0\n"); return 0;}
	for(i=0;i<n;i++){scanf("%d",&a[i]); aAsli[i] = a[i];}
	int minim = 2000000000, maks = -2000000000;
	for(i=0;i<(n-1);i++){
		diff[i] = a[i+1] - a[i];
		diffAsli[i] = diff[i];
		minim = min(minim, diff[i]);
		maks = max(maks, diff[i]);
	}
	if(minim == maks){printf("0\n"); return 0;}
	
	int kiri = minim, kanan = maks;
	ll ans = inf;
	while(kiri<=kanan) {
		//cari tujuan optimum
		for(i=0;i<(n-1);i++){ //reset array diff
			diff[i] = diffAsli[i];
		}

		ll mid = (kiri+kanan) / 2;
		ll langkah = 0;
		for(i=1;i<(n-1);i++){
			ll selisih1 = abs(diff[i-1] - mid);
			ll selisih2 = abs(diff[i] - mid);
			if(i==1){
				if(selisih1>selisih2) {
					langkah+=selisih1;
					diff[i] = mid;
				}else{
					langkah+=selisih1;
					if(diff[i] > mid) {
						diff[i] -= selisih1;	
					}else{
						diff[i] += selisih1;
					}
				}
			}else{
				if(selisih1>selisih2) {
					langkah+=selisih1;
					if(diff[i] > mid) {
						ll sisa = selisih1 - selisih2;
						diff[i] -= sisa;
					}else{
						ll sisa = selisih2 - selisih1;
						diff[i] += sisa;
					}
					
				}else{
					langkah+=selisih1;
					if(diff[i] > mid) {
						diff[i] -= selisih1;
					}else{
						diff[i] += selisih1;
					}
				}
			}
		}
		ans = min(ans, langkah);

		for(i=0;i<(n-1);i++){ //reset array diff
			diff[i] = diffAsli[i];
		}

		mid++;
		langkah = 0;
		for(i=1;i<(n-1);i++){
			ll selisih1 = abs(diff[i-1] - mid);
			ll selisih2 = abs(diff[i] - mid);
			if(i==1){
				if(selisih1>selisih2) {
					langkah+=selisih1;
					diff[i] = mid;
				}else{
					langkah+=selisih1;
					if(diff[i] > mid) {
						diff[i] -= selisih1;	
					}else{
						diff[i] += selisih1;
					}
				}
			}else{
				if(selisih1>selisih2) {
					langkah+=selisih1;
					if(diff[i] > mid) {
						ll sisa = selisih1 - selisih2;
						diff[i] -= sisa;
					}else{
						ll sisa = selisih2 - selisih1;
						diff[i] += sisa;
					}
					
				}else{
					langkah+=selisih1;
					if(diff[i] > mid) {
						diff[i] -= selisih1;
					}else{
						diff[i] += selisih1;
					}
				}
			}
		}
		ans = min(ans, langkah);
		break;
	}
	printf("%lld\n",ans);
	return 0;
};