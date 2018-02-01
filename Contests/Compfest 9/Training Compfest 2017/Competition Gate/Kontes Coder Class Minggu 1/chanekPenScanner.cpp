#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

string kata[15];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool isSpasi(int barisAwal, int barisAkhir, int kolomAwal, int kolomAkhir){
	int i,j;
	for(i=barisAwal;i<=barisAkhir;i++){
		for(j=kolomAwal;j<=kolomAkhir;j++){
			if(kata[i][j]=='0'){return false;}
		}
	}
	return true;
}
bool isA(int barisAwal, int barisAkhir, int kolomAwal, int kolomAkhir){//cek baris terkahir aja
	char kar1 = kata[barisAkhir][kolomAwal], kar2 = kata[barisAkhir][kolomAkhir], kar3 = kata[barisAkhir][kolomAwal+1];
	return kar1=='0' && kar2=='0' && kar3=='1';
}
bool isB(int barisAwal, int barisAkhir, int kolomAwal, int kolomAkhir){//cek baris terakhir sama kolom terakhir..harus full semua
	int i,j;
	for(j=kolomAwal;j<=kolomAkhir;j++){
		if(kata[barisAkhir][j]=='1'){return false;}
	}
	for(i=barisAwal;i<=barisAkhir;i++){
		if(kata[i][kolomAkhir]=='1'){return false;}
	}
	//printf("lolos\n");
	return true;
}
int isC(int barisAwal, int barisAkhir, int kolomAwal, int kolomAkhir){
	int i,j;
	for(j=kolomAwal;j<=kolomAkhir;j++){
		if(kata[barisAkhir][j]=='1'){return false;}
	}
	if(kata[barisAwal+1][kolomAkhir]=='0'){return false;}
	else{return true;}
}

int main() {
	int r,c,i,j;
	r = 0;
	for(i=0;i<9;i++){
		cin>>kata[i];
	}
	c = kata[0].length();
	i=1;
	
	for(j=1;j<c;j++){
		int barisAwal = 1, barisAkhir = 7, kolomAwal = j, kolomAkhir = j+3;
		//printf("kolomawal: %d kolomAkhir: %d\n",kolomAwal, kolomAkhir);
		if(isSpasi(barisAwal,barisAkhir,kolomAwal,kolomAkhir)){printf(" ");}
		else{
			if(isA(barisAwal,barisAkhir,kolomAwal,kolomAkhir)){printf("A");}
			else if(isB(barisAwal,barisAkhir,kolomAwal,kolomAkhir)){printf("B");}
			else if(isC(barisAwal,barisAkhir,kolomAwal,kolomAkhir)){printf("C");}
		}
		j+=4;
	}
	printf("\n");
	
	return 0;
}