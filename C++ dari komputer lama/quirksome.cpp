#include <bits/stdc++.h>

using namespace std;
typedef vector <int> vi;
int gabung(int i,int j){
	vi a; int idx,bil;
	while(j>0){
		a.push_back(j%10); j/=10;
	}
	for(idx=a.size()-1;idx>=0;idx--){i*=10; i+=a[idx];}
	bil=i;
	a.clear();
	return(bil);
}

int main(){
	int digit,i,j;
	vi dua,empat,enam,delapan;

	for(i=0;i<=9;i++){
		for(j=0;j<=9-i;j++){
			printf("i: %d, j: %d\n",i,j);
			if((i+j)*(i+j)==gabung(i,j)){printf("digit2: %d\n",(i+j)*(i+j));dua.push_back((i+j)*(i+j));}
		}
	}
	for(i=0;i<=99;i++){
		for(j=0;j<=99-i;j++){
			if((i+j)*(i+j)==gabung(i,j)){printf("digit4: %d\n",(i+j)*(i+j));empat.push_back((i+j)*(i+j));}
		}
	}
	for(i=0;i<=999;i++){
		for(j=0;j<=999-i;j++){
			if((i+j)*(i+j)==gabung(i,j)){printf("digit6: %d\n",(i+j)*(i+j));enam.push_back((i+j)*(i+j));}
		}
	}
	for(i=0;i<=9999;i++){
		for(j=0;j<=9999-i;j++){
			printf("mengkaji i %d j %d\n",i,j);
			if((i+j)*(i+j)==gabung(i,j)){printf("digit8: %d\n",(i+j)*(i+j));delapan.push_back((i+j)*(i+j));}
		}
	}
	while(scanf("%d",&digit)!=EOF){
		if(digit==2){
			for(i=0;i<dua.size();i++){printf("%.2d\n",dua[i]);}
		}else if(digit==4){
			for(i=0;i<empat.size();i++){printf("%.2d\n",empat[i]);}
		}else if(digit==6){
			for(i=0;i<enam.size();i++){printf("%.2d\n",enam[i]);}
		}else if(digit==8){
			for(i=0;i<delapan.size();i++){printf("%.2d\n",delapan[i]);}
		}
	}
	return 0;
}