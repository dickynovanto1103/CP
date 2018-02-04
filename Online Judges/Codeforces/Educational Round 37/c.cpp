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

const int maxn = 2e5 + 5;

int main(){
	int n,i,j;
	string kata;
	scanf("%d",&n);
	int a[maxn], idx[maxn];
	for(i=0;i<n;i++){scanf("%d",&a[i]); a[i]--; idx[a[i]] = i;}
	cin>>kata;
	//catet idx yang ngawur
	vi listHalangan;
	for(i=0;i<kata.length();i++){
		if(kata[i]=='0'){
			listHalangan.pb(i);
			// printf("halangan kepush: %d\n",i);
		}
	}
	vi listIdxNgawur;
	for(i=0;i<n;i++){
		if(i!=a[i]){
			listIdxNgawur.pb(a[i]);
			// printf("idxSalah kepush: %d\n",a[i]);
		}
	}
	for(i=0;i<n;i++){
		if(i==a[i]){continue;}
		//cek yang bermasalah
		int posisiSekarang = idx[i];
		int posisiSeharusnya = i;
		// printf("cek: %d\n",i);
		// printf("posisiSekarang: %d posisiSeharusnya: %d\n",posisiSekarang,posisiSeharusnya);
		if(posisiSekarang > posisiSeharusnya){
			int idx = lower_bound(listHalangan.begin(), listHalangan.end(), posisiSeharusnya) - listHalangan.begin(); // buat cek sisi kanan
			if(idx==listHalangan.size()){continue;}
			int nilai = listHalangan[idx];
			// printf("idx: %d nilai: %d\n",idx,nilai);
			if(nilai>=posisiSeharusnya && nilai<=(posisiSekarang-1)){
				// printf("cek1\n");
				printf("NO\n"); return 0;
			}
		}else{
			int idx = lower_bound(listHalangan.begin(), listHalangan.end(), posisiSekarang) - listHalangan.begin(); // ini buat cek sisi kiri
			if(idx==listHalangan.size()){continue;}
			int nilai = listHalangan[idx];
			if(nilai>=posisiSekarang && nilai<=(posisiSeharusnya-1)){
				// printf("cek2\n");
				printf("NO\n"); return 0;
			}
		}
		
	}
	// for(i=0;i<listIdxNgawur.size();i++){
	// 	int idxSeharusnya = listIdxNgawur[i];
	// 	int posisi = idx[idxSeharusnya];
	// 	int idxPenghalangKiri = lower_bound(listHalangan.begin(), listHalangan.end(), posisi) - listHalangan.begin(); // buat cek sisi kiri
	// 	int idxPenghalangKanan = lower_bound(listHalangan.begin(), listHalangan.end(), idxSeharusnya) - listHalangan.begin(); // ini buat cek sisi kanan

	// 	if(posisi>idxSeharusnya){
	// 		if(idxPenghalangKanan>=listHalangan.size()){
	// 			continue; // cek penghalang berikutnya
	// 		}else{
	// 			int nilai = listHalangan[idxPenghalangKanan];
	// 			if(nilai>=idxSeharusnya && nilai<=posisi){
	// 				printf("NO\n"); return 0;
	// 			}
	// 		}
	// 	}else{
	// 		if(idxPenghalangKiri>=listHalangan.size()){
	// 			continue;
	// 		}else{
	// 			int nilai = listHalangan[idxPenghalangKiri];
	// 			if(nilai>=posisi && nilai<=idxSeharusnya){
	// 				printf("NO\n"); return 0;
	// 			}
	// 		}
	// 	}
	// }
	printf("YES\n");
	return 0;
};