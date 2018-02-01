#include <bits/stdc++.h>

using namespace std;

int main(){
	string kata[15];
	int listBelakang[15], listDepan[15];
	int i,j,n;
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){listDepan[i] = listBelakang[i] = 0;}
		cin>>ws;
		for(i=0;i<n;i++){getline(cin,kata[i]);}
		for(i=0;i<n;i++){
			for(j=24;j>=0;j--){
				if(kata[i][j]==' '){listBelakang[i] = j; break;}
			}
			for(j=0;j<25;j++){
				if(kata[i][j]==' '){listDepan[i] = j-1; break;}
			}
		}
		//cari selisih minimum
		int minim = 1000000000;
		for(i=0;i<n;i++){
			minim = min(minim,listBelakang[i]-listDepan[i]);
			//printf("depan: %d belakang: %d\n",listDepan[i],listBelakang[i]);
		}
		//printf("minim: %d\n",minim);
		int total = 0;
		for(i=0;i<n;i++){
			int selisih = listBelakang[i]-listDepan[i];
			total = total+(selisih - minim);
		}
		printf("%d\n",total);
	}
	return 0;
}