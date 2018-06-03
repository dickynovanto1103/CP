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

const int maxn = 1e5 + 5;

int main(){
	int tc,i,j,n,q;
	int a[maxn];

	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&q);
		map<int,int> mapper;

		int sorted[maxn];
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sorted[i] = a[i];
			mapper[a[i]] = i;
		}
		sort(sorted+1, sorted+1+n);
		// printf("array asli:");
		// for(i=1;i<=n;i++){
		// 	printf(" %d",a[i]);
		// }
		// printf("\n");
		// printf("array sorted:");
		// for(i=1;i<=n;i++){
		// 	printf(" %d",sorted[i]);
		// }
		// printf("\n");
		while(q--){
			int x;
			scanf("%d",&x);

			int idx = mapper[x];
			int indeksAsli = lower_bound(sorted+1,sorted+1+n,x) - sorted;
			// printf("x: %d idx: %d indeksAsli: %d\n",x,idx,indeksAsli);
			int cntBawah = indeksAsli-1;
			int cntAtas = (n-indeksAsli);

			// printf("cntBawah: %d cntAtas: %d\n",cntBawah, cntAtas);
			//simulasi binser
			int kiri = 1, kanan = n, mid;
			
			int cntButuhLebihKecil = 0, cntButuhLebihBesar = 0;
			while(kiri<=kanan) {
				mid = (kiri + kanan) / 2;
				// printf("a[%d]: %d\n",mid,a[mid]);
				if(mid > idx){//bakal ke kiri
					if(a[mid] < x){//butuh a[mid] yg lebih besar daripada x
						cntButuhLebihBesar++;
						// printf("a[%d]: %d cntButuhLebihBesar jadi: %d\n",mid,a[mid], cntButuhLebihBesar);
					}else{//sudah benar a[mid] > x..berarti bil a[mid] ini jangan masukin perhitungan cntAtas..dikurangin
						cntAtas--;
					}
					kanan = mid-1;
				}else if(mid < idx) {//harusnya ke kanan..elemen di indeks mid harus lebih kecil
					if(a[mid] > x) {
						
						cntButuhLebihKecil++;
						// printf("a[%d]: %d cntButuhLebihKecil jadi: %d\n",mid,a[mid], cntButuhLebihKecil);
					}else{
						cntBawah--;
					}
					kiri = mid+1;
				}else{
					// printf("masuk sini\n");
					break;
				}
			}

			int ans = min(cntButuhLebihKecil,cntButuhLebihBesar);

			cntButuhLebihBesar-=ans; cntButuhLebihKecil-=ans;
			cntBawah-=ans; cntAtas-=ans;
			bool bisa = true;
			if(cntButuhLebihBesar>0){
				if(cntAtas < cntButuhLebihBesar){
					bisa = false;
				}else{
					ans+=cntButuhLebihBesar;
				}
			}
			if(cntButuhLebihKecil>0){
				if(cntBawah < cntButuhLebihKecil) {
					bisa = false;
				}else{
					ans+=cntButuhLebihKecil;
				}
			}

			if(bisa){
				printf("%d\n",ans);
			}else{
				printf("-1\n");
			}
		}
		mapper.clear();
	}
	return 0;
};