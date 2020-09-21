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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int a,b,c,d;

int findMinim(int sisi1) {
	int kiri = b, kanan = c, mid, ans = -1;
	while(kiri <= kanan) {
		mid = (kiri + kanan)/2;
		int tambah = sisi1 + mid - 1;
		if(tambah >= c){
			ans = mid;
			kanan = mid-1;
		}else{
			kiri = mid+1;
		}
	}
	return ans;
}

int findMax(int sisi1) {
	int kiri = b, kanan = c, mid, ans = c;
	while(kiri <= kanan) {
		mid = (kiri + kanan)/2;
		int tambah = sisi1 + mid - 1;
		if(tambah <= d){
			ans = mid;
			kiri = mid+1;
		}else{
			kanan = mid-1;
		}
	}
	return ans;
}

int main(){
	int i,j,k;
	while(scanf("%d %d %d %d",&a,&b,&c,&d) != EOF) {
		ll cnt = 0;
		for(i=a;i<=b;i++){
			int minimSisi2 = findMinim(i);
			assert(minimSisi2 != -1);
			ll maksContribution = d - c + 1;
			int minimSisi3 = min(i + minimSisi2 - 1, d);
			ll kontribusi = minimSisi3 - c + 1;
			int selisihKontribusi = maksContribution - kontribusi;
			if(selisihKontribusi == 0) {
				cnt += (ll)(c - b + 1) * (d - c + 1);
			}else{
				int selisihSisi2 = c - minimSisi2;
				if(selisihSisi2 >= selisihKontribusi){
					//berarti suatu saat nanti bakal plateu ke (d - c + 1) contribution
					//cari sisi 2 minim sehingga kontribusi = d - c;
					ll num1 = (maksContribution * (maksContribution + 1))/2;
					ll num2 = ((kontribusi - 1) * kontribusi) / 2;

					cnt += num1;
					cnt -= num2;
					selisihSisi2 -= selisihKontribusi;
					cnt += (selisihSisi2 * maksContribution);
				}else{
					//berarti ga bakal sampe maksContribution = (d - c + 1)
					ll maksimum = kontribusi + selisihSisi2;

					ll num1 = (maksimum * (maksimum + 1))/2;
					ll num2 = ((kontribusi - 1) * kontribusi) / 2;
					cnt += num1;
					cnt -= num2;
				}
			}

			// ll jarak = maksSisi2 - minimSisi2 + 1;
			// cnt += (jarak * (jarak+1)) / 2;
			// ll sisa = c - maksSisi2;
			// printf("i: %d minimSisi2: %d maksSisi2: %d minimSisi3: %d maksSisi3: %d cntJadi: %lld\n",i, minimSisi2, maksSisi2, minimSisi3, maksSisi3, cnt);


			// for(j=b;j<=c;j++){
			// 	//optimize this
			// 	int tambah = i + j - 1;
			// 	if(tambah >= c) {
			// 		tambah = min(tambah, d);
			// 		cnt += (tambah - c + 1);
			// 	}
			// }
		}
		printf("%lld\n",cnt);
	}
	
	
	return 0;
};