#include <cstdio>
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int A[130][130];
int cnt;
bool isHomogen(int brsawal, int brsakhir, int clmawal, int clmakhir){
	bool found=true;
	int a,i,j;
	
	a=A[brsawal][clmawal];
	i=brsawal;
	while(i<=brsakhir && found){
		j=clmawal;
		while(j<=clmakhir && found){
			if(A[i][j]!=a){found=false;}
			else{j++;}
		}
		if(found){i++;}
	}
	return(found);
}

void rek(int R, int C, int s){
	
}


int main(){
	int R,C,i,j;
	
	scanf("%d %d",&R,&C);
	for(i=1;i<=R;i++){
		for(j=1;j<=C;j++){
			scanf("%d",&A[i][j]);
		}
	}
	//menambahkan ke 2^n terdekat dengan elemen 0;
	if(R>C){
		for(i=1;i<=7;i++){//karena 2^7 = 128..batas maksnya
			if(pow(2,i)>=R){
				break;
			}
		}
	}else{
		for(i=1;i<=7;i++){//karena 2^7 = 128..batas maksnya
			if(pow(2,i)>=C){
				break;
			}
		}
	}
	for(j=R;j)
	return 0;
}