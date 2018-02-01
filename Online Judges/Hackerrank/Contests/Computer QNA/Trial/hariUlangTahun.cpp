#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

char nol[5][3] = {' ','-',' ',
				  '|',' ','|',
				  ' ',' ',' ',
				  '|',' ','|',
				  ' ','-',' '};
char satu[5][3] = {	' ',' ',' ',
				   	' ',' ','|',
					' ',' ',' ',
					' ',' ','|',
					' ',' ',' '};
char dua[5][3] = {	' ','-',' ',
					' ',' ','|',
					' ','-',' ',
					'|',' ',' ',
					' ','-',' '};
char tiga[5][3] = {	' ','-',' ',
					' ',' ','|',
					' ','-',' ',
					' ',' ','|',
					' ','-',' '};
char empat[5][3] = {' ',' ',' ',
					'|',' ','|',
					' ','-',' ',
					' ',' ','|',
					' ',' ',' '};
char lima[5][3] = { ' ','-',' ',
					'|',' ',' ',
					' ','-',' ',
					' ',' ','|',
					' ','-',' '};
char enam[5][3] = { ' ','-',' ',
					'|',' ',' ',
					' ','-',' ',
					'|',' ','|',
					' ','-',' '};
char tujuh[5][3] = {' ','-',' ',
					' ',' ','|',
					' ',' ',' ',
					' ',' ','|',
					' ',' ',' '};
char delapan[5][3] = {	' ','-',' ',
						'|',' ','|',
						' ','-',' ',
						'|',' ','|',
						' ','-',' '};
char sembilan[5][3] ={	' ','-',' ',
						'|',' ','|',
						' ','-',' ',
						' ',' ','|',
						' ','-',' '};

int main() {
	char mat[10][40];
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<40;j++){
			if(i==0 || j==0 || j==34 || i==6){
				mat[i][j] = '#';
			}else{
				mat[i][j] = ' ';
			}
		}
	}
	mat[3][9] = '~'; mat[3][17] = '~';
	int iawal = 1, cawal = 2;
	string kata;
	cin>>kata;
	int k,l,m;
	for(k=0;k<kata.length();k++){
		int baris = 0, kolom = 0;
		char kar = kata[k];
		int bil = kar-48;
		if(bil==0){
			for(i=iawal;i<iawal+5;i++){
				for(j=cawal;j<cawal+3;j++){
					mat[i][j] = nol[baris][kolom]; kolom++;
				}
				baris++; kolom=0;
			}	
		}else if(bil==1){
			for(i=iawal;i<iawal+5;i++){
				for(j=cawal;j<cawal+3;j++){
					mat[i][j] = satu[baris][kolom]; kolom++;
				}
				baris++; kolom=0;
			}
		}else if(bil==2){
			for(i=iawal;i<iawal+5;i++){
				for(j=cawal;j<cawal+3;j++){
					mat[i][j] = dua[baris][kolom]; kolom++;
				}
				baris++; kolom=0;
			}
		}else if(bil==3){
			for(i=iawal;i<iawal+5;i++){
				for(j=cawal;j<cawal+3;j++){
					mat[i][j] = tiga[baris][kolom]; kolom++;
				}
				baris++; kolom=0;
			}
		}else if(bil==4){
			for(i=iawal;i<iawal+5;i++){
				for(j=cawal;j<cawal+3;j++){
					mat[i][j] = empat[baris][kolom]; kolom++;
				}
				baris++; kolom=0;
			}
		}else if(bil==5){
			for(i=iawal;i<iawal+5;i++){
				for(j=cawal;j<cawal+3;j++){
					mat[i][j] = lima[baris][kolom]; kolom++;
				}
				baris++; kolom=0;
			}
		}else if(bil==6){
			for(i=iawal;i<iawal+5;i++){
				for(j=cawal;j<cawal+3;j++){
					mat[i][j] = enam[baris][kolom]; kolom++;
				}
				baris++; kolom=0;
			}
		}else if(bil==7){
			for(i=iawal;i<iawal+5;i++){
				for(j=cawal;j<cawal+3;j++){
					mat[i][j] = tujuh[baris][kolom]; kolom++;
				}
				baris++; kolom=0;
			}
		}else if(bil==8){
			for(i=iawal;i<iawal+5;i++){
				for(j=cawal;j<cawal+3;j++){
					mat[i][j] = delapan[baris][kolom]; kolom++;
				}
				baris++; kolom=0;
			}
		}else if(bil==9){
			for(i=iawal;i<iawal+5;i++){
				for(j=cawal;j<cawal+3;j++){
					mat[i][j] = sembilan[baris][kolom]; kolom++;
				}
				baris++; kolom=0;
			}
		}
		cawal = cawal+3;
		/*printf("cawal: %d\n",cawal);
		printf("bil: %d\n",bil);
		printf("jadi:\n");*/
		
		cawal+=1;
	}
	
	for(i=0;i<=6;i++){
		for(j=0;j<=34;j++){
			printf("%c",mat[i][j]);
		}
		printf("\n");
	}

	return 0;
}