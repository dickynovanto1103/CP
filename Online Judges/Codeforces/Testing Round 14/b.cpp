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

int main(){
	int n,i,j;
	int a,b;
	scanf("%d %d %d",&n,&a,&b);
	int ans = 0;
	int minim = min(a,b);
	int maks = max(a,b);
	int jumlah1 = 4, jumlah2 = 2;
	int panjang = n;
	vi listSisaPanjang;
	int cnt = 0;
	if((4*a + 2*b)<=panjang){printf("1\n"); return 0;}
	if(b>a && (b+a+a)<=n){printf("2\n"); return 0;}
	if(a>b){
		//mencari potongan-potongan sisa setelah motong yang besar

		while(jumlah1>0){
			panjang = n;
			if(panjang>=a){cnt++;}
			while(panjang>=a){
				panjang-=a; jumlah1--;
				if(jumlah1==0){break;}
			}
			if(jumlah1>0){listSisaPanjang.pb(panjang);}//dapetin sisa panjang

		}

		//entah ada sisa atau tidak..dapet panjang sekarang
		listSisaPanjang.pb(panjang);
		for(i=0;i<listSisaPanjang.size();i++){
			int pjg = listSisaPanjang[i];
			//mulai motongin kayu buat yang ukuran kecil
			while(pjg>=b){
				pjg-=b; jumlah2--;
				if(jumlah2==0){break;}
			}
			if(jumlah2==0){break;}
		}

		//dari sisa potongan panjang sudah habis..saat nya ngambil kayu utuh
		while(jumlah2>0){
			panjang = n;
			if(panjang>=b){cnt++;}
			while(panjang>=b){
				panjang-=b; jumlah2--;
				if(jumlah2==0){break;}
			}
		}
		printf("%d\n",cnt);
	}else{
		//mencari potongan-potongan sisa setelah motong yang besar

		while(jumlah2>0){
			panjang = n;
			if(panjang>=b){cnt++;}
			while(panjang>=b){
				panjang-=b; jumlah2--;
				if(jumlah2==0){break;}
			}
			if(jumlah2>0){listSisaPanjang.pb(panjang);}//dapetin sisa panjang

		}

		//entah ada sisa atau tidak..dapet panjang sekarang
		listSisaPanjang.pb(panjang);
		for(i=0;i<listSisaPanjang.size();i++){
			int pjg = listSisaPanjang[i];
			//mulai motongin kayu buat yang ukuran kecil
			while(pjg>=a){
				pjg-=a; jumlah1--;
				if(jumlah1==0){break;}
			}
			if(jumlah1==0){break;}
		}

		//dari sisa potongan panjang sudah habis..saat nya ngambil kayu utuh
		while(jumlah1>0){
			panjang = n;
			if(panjang>=a){cnt++;}
			while(panjang>=a){
				panjang-=a; jumlah1--;
				if(jumlah1==0){break;}
			}
		}
		printf("%d\n",cnt);
	}

	
	return 0;
};