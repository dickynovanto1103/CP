#include <bits/stdc++.h>
using namespace std;

int n,a[100010];

int binarySearch(int bil){
	int hasil = -1, idx;
	int tengah,kiri,kanan;
	kiri = 0; kanan = n-1;
	while((kiri<=kanan) && (hasil==-1)){
		tengah = (kiri+kanan)/2;
		if(bil < a[tengah]){
			kanan = tengah-1;
		}else if(bil > a[tengah]){
			kiri = tengah+1;
		}else{//ketemu
			hasil = a[tengah];
		}
	}
	return tengah;
}

int getIdxAwal(int x){
	int tengah = binarySearch(x);
	while(a[tengah]<=x && tengah<n){tengah++;}
	return tengah;
}
int getIdxAkhir(int y){
	int tengah = binarySearch(y);
	if(a[tengah]>y){
		while(a[tengah]>y && tengah>=0){tengah--;}	
	}else if(a[tengah]==y){
		while(a[tengah]==y && tengah<n){tengah++;}	
		tengah--;
	}
	

	return tengah;
}

int main(){
	int i,q,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&x,&y);
		int idxawal = getIdxAwal(x);
		int idxakhir = getIdxAkhir(y);
		//printf("idxawal: %d idxakhir: %d\n",idxawal,idxakhir);
		printf("%d\n",idxakhir-idxawal+1);
		//coba kasus semua nilainya sama ...tp x sama y nya lebih ebsar dari semua nilai di array..dan juga sebaliknya
	}
	return 0;
}