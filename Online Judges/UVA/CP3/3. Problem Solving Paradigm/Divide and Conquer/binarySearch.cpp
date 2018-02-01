#include <bits/stdc++.h>
using namespace std;

int n;

void binarySearch(int a[], int bil){
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
			idx = tengah;
		}
	}
	if(hasil==-1){printf("tidak ditemukan\n");}
	else{printf("ditemukan %d di indeks %d\n",hasil,idx);}
}

int main(){
	int bil,i,a[20];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	scanf("%d",&bil);
	binarySearch(a, bil);
	return 0;
}