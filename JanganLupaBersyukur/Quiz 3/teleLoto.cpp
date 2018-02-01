#include <bits/stdc++.h>

using namespace std;
int mat[5][5];
bool found, isUjungMenang, isMidLineMenang, isDiagonalMenang, isTableMenang;
void cari(int kolom,int bil){
	for(int i=0;i<5;i++){
		if(mat[i][kolom]==bil){
			found = true;
			mat[i][kolom] = 0;
		}
	}
}

bool isUjung(){
	return mat[0][0]==0 && mat[4][0]==0 && mat[0][4]==0 && mat[4][4]==0;
}
bool isMidLine(){
	for(int i=0;i<5;i++){
		if(mat[2][i]!=0){return false;}
	}
	return true;
}
bool isDiagonal(){
	//cek turun kanan bawah
	int i;
	for(i=0;i<5;i++){
		if(mat[i][i]!=0){return false;}
	}
	//cek turun kiri bawah
	for(i=0;i<5;i++){
		int j=4-i;
		if(mat[i][j]!=0){return false;}
	}
	return true;
}

bool isTable(){
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if(mat[i][j]!=0){return false;}
		}
	}
	return true;
}

int main(){
	int tc,i,test=1,j,n,m,l, a[4], bola[80];
	scanf("%d",&tc);
	while(tc--){
		if(test>1){printf("\n");}
		printf("Case %d:\n",test++);
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++){scanf("%d",&bola[i]);}
		for(i=0;i<4;i++){scanf("%d",&a[i]);}
		while(m--){
			//baca matrix 5x5
			isUjungMenang = isMidLineMenang = isTableMenang = isDiagonalMenang = false;
			for(i=0;i<5;i++){
				for(j=0;j<5;j++){
					scanf("%d",&mat[i][j]);
				}
			}
			//tentukan banyak menang
			int sum = 0;
			for(i=0;i<n;i++){
				int bil = bola[i];
				if(bil>=1 && bil<=15){cari(0,bil);}
				else if(bil>=16 && bil<=30){cari(1,bil);}
				else if(bil>=31 && bil<=45){cari(2,bil);}
				else if(bil>=46 && bil<=60){cari(3,bil);}
				else if(bil>=61 && bil<=75){cari(4,bil);}

				//membatasi syarat menang
				if(i>=45){isDiagonalMenang=true;}
				else if(i>=40){isMidLineMenang = true;}
				else if(i>=35){isUjungMenang = true;}

				if(!isUjungMenang){
					if(isUjung()){sum+=a[0]; isUjungMenang=true;}
				}
				if(!isMidLineMenang){
					if(isMidLine()){sum+=a[1]; isMidLineMenang=true;}
				}
				if(!isDiagonalMenang){
					if(isDiagonal()){sum+=a[2]; isDiagonalMenang=true;}
				}
				if(isDiagonalMenang && isMidLineMenang && isUjungMenang){
					if(!isTableMenang){
						if(isTable()){sum+=a[3]; isTableMenang=true; break;}//game done
					}	
				}
				
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}