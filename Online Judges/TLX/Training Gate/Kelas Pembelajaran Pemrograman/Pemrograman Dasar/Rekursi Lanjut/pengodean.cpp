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

bool isAllSama(int b_awal, int b_akhir, int c_awal, int c_akhir) {
	bool found = true;
	int bil = a[b_awal][c_awal];
	for(int i=b_awal;i<=b_akhir;i++){
		for(int j=c_awal;j<=c_akhir;j++){
			if(bil!=a[i][j]){found = false; break;}
		}
		if(!found){break;}
	}
	return found;
}

bool isOne(int b_awal, int c_awal){
	return a[b_awal][c_awal] == 1;
}

bool isZero(int b_awal, int c_awal){
	return a[b_awal][c_awal] == 1;
}

void solve(int b_awal, int b_akhir, int c_awal, int c_akhir, string kata) {
	if(isAllSama(b_awal,b_akhir,c_awal, c_akhir)){
		if(isOne(b_awal,c_awal)){
			ans.push_back(kata);
		}
	}else {
		int tengah_baris = b_awal + ((b_akhir - b_awal)/2);
		int tengah_kolom = c_awal + ((c_akhir - c_awal)/2);
		//bagi jadi 4 matriks
		solve(b_awal,tengah_baris,c_awal,tengah_kolom, kata+'0');
		solve(b_awal,tengah_baris,tengah_kolom+1,c_akhir, kata+'1');
		solve(tengah_baris+1,b_akhir,c_awal,tengah_kolom, kata+'2');
		solve(tengah_baris+1,b_akhir,tengah_kolom+1,c_akhir, kata+'3');
	}
}

int main() {
	int i,j;
	
	scanf("%d %d",&r,&c);
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
	//tampil matriks
	r = minr; c = minc;
	/*printf("r: %d c: %d\n",r,c);
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}*/
	//rekursi
	
	solve(0,r-1,0,c-1,"1");
	sort(ans.begin(), ans.end());
	int ukuran = ans.size();
	printf("%d\n",ukuran);
	for(int i = 0; i < ukuran; i++) {
		cout<<ans[i]<<endl;
	}
	return 0;
}
