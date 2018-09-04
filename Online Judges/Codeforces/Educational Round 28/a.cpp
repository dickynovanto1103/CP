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

const int maxn = 101;

int main(){
	int n,i,j;
	int a[maxn];
	scanf("%d",&n);
	int idx1 = -1, idx2 = -1;
	vi listBil, listJumlah;
	int cur = -1;
	int jumlah = 0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=cur){
			if(cur == -1){
				listBil.pb(a[i]);
				cur = a[i];
				jumlah++;
			}else{
				listJumlah.pb(jumlah);
				jumlah = 0;
				cur = a[i];
				listBil.pb(cur);
				jumlah++;
			}
		}else{
			jumlah++;
		}	
	}
	listJumlah.pb(jumlah);
	if(listJumlah.size() == 1){
		printf("%d\n",listJumlah[0]);
		return 0;
	}
	// for(i=0;i<listBil.size();i++){
	// 	if(i){printf(" ");}
	// 	printf("%d",listBil[i]);
	// }
	// printf("\n");
	// for(i=0;i<listJumlah.size();i++){
	// 	if(i){printf(" ");}
	// 	printf("%d",listJumlah[i]);
	// }
	// printf("\n");
	int prefNol[maxn], prefSatu[maxn];
	memset(prefSatu, 0, sizeof prefSatu);
	memset(prefNol, 0, sizeof prefNol);
	int ukuran = listBil.size();
	for(i=0;i<ukuran;i++){
		//anggep aja mulai dari indeks ini
		int bil = listBil[i];
		if(bil == 0){//antara selanjutnya 1 semua..atau 0 dulu baru 1
			prefNol[i]+=listJumlah[i];
		}else{//kalau 1..seterusnya harus 1
			prefSatu[i] += listJumlah[i];
		}
	}
	for(i=1;i<ukuran;i++){
		prefNol[i] += prefNol[i-1];
		prefSatu[i] += prefSatu[i-1];
	}
	int maks = 0;

	for(i=0;i<ukuran;i++){
		int bil = listBil[i];
		int ans = 0;

		if(bil == 1){
			ans += prefSatu[i];
			ans += prefSatu[ukuran-1] - prefSatu[i];//ditambah 1 setelahnya
			maks = max(maks, ans);
		}else{//dia tambah 0 terus sampe 1
			ans = prefNol[i];
			for(j=i;j<ukuran;j++){
				ans = prefNol[i];
				ans += prefNol[j] - prefNol[i];
				ans += prefSatu[ukuran-1] - prefSatu[j];
				maks = max(maks, ans);
			}
			maks = max(maks, ans);
		}
		
		
	}
	printf("%d\n",maks);
	return 0;
};
