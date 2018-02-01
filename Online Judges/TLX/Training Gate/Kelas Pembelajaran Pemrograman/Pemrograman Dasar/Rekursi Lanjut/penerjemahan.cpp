#include <bits/stdc++.h>

using namespace std;
int a[130][130],minc,minr,r,c;
vector <string> ans;

int minPelebaran(int a){
	int bil;
	for(int i = 0; i < 10; i++){

		bil = pow(2,i);
		//printf("bil: %d a: %d\n",bil,a);
		if(bil >= a){break;}
	}
	return bil;
}

void solve(int b_awal, int b_akhir, int c_awal, int c_akhir, string kata, int idx) {
	int i,j;
	if(idx == kata.length()){
		//isi dengan 1
		/*cout<<"kata: "<<kata<<endl;
		printf("b_awal: %d, b_akhir: %d c_awal: %d, c_akhir: %d\n",b_awal, b_akhir, c_awal, c_akhir);*/
		for(i=b_awal;i<=b_akhir;i++){
			for(j=c_awal;j<=c_akhir;j++){
				a[i][j] = 1;
			}
		}
	}else {
		int tengah_baris = b_awal + ((b_akhir - b_awal)/2);
		int tengah_kolom = c_awal + ((c_akhir - c_awal)/2);
		//bagi jadi 4 matriks
		if(kata[idx]=='0'){
			solve(b_awal,tengah_baris,c_awal,tengah_kolom, kata, idx+1);	
		}else if(kata[idx]=='1'){
			solve(b_awal,tengah_baris,tengah_kolom+1,c_akhir, kata, idx+1);	
		}else if(kata[idx]=='2'){
			solve(tengah_baris+1,b_akhir,c_awal,tengah_kolom, kata, idx+1);
		}else if(kata[idx]=='3'){
			solve(tengah_baris+1,b_akhir,tengah_kolom+1,c_akhir, kata, idx+1);
		}
	}
}

int main() {
	int i,j,n, r_lama, c_lama;
	string kata[16500];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		cin>>kata[i];
	}
	scanf("%d %d",&r,&c);
	r_lama = r; c_lama = c;
	//perluas klo perlu
	
	minr = minPelebaran(r);
	minc = minPelebaran(c);
	minr = max(minr, minc);
	minc = minr;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=r;i<minr;i++){
		for(j=0;j<c;j++){
			a[i][j] = 0;
		}
	}
	for(i=0;i<r;i++){
		for(j=c;j<minc;j++){
			a[i][j] = 0;
		}
	}
	r = minr; c = minc;
	//inisialisasi
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			a[i][j] = 0;
		}
	}
	
	//rekursi
	for(i=0;i<n;i++){
		solve(0,r-1,0,c-1,kata[i],1);
	}
	
	for(i=0;i<r_lama;i++){
		for(j=0;j<c_lama;j++){
			if(j>0){printf(" ");}
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
