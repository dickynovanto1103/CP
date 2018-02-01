#include <bits/stdc++.h>

using namespace std;

int jumlahDigit(int bil){
	int cnt = 0;
	while(bil>0){
		bil/=10; cnt++;
	}
	return cnt;
}

int main(){
	int n,i,j;
	while(scanf("%d",&n)!=EOF){
		//printf("n: %d\n",n);
		if(n==2){
			for(i=0;i<10;i++){
				//printf("i: %d\n",i);
				int bil = i*i;
				int temp = bil;
				int bil1 = temp/10;
				int bil2 = bil - bil1*10;
				int sum = bil1+bil2;
				//printf("ketemu bil: %d\n",bil);
				if(sum*sum==bil){
					//print solution
					int banyakDigit = jumlahDigit(bil);
					//printf("banyak digit: %d\n",banyakDigit);
					//cetak brp banyak 0
					for(j=0;j<n-banyakDigit;j++){
						printf("0");
					}
					if(bil!=0){printf("%d\n",bil);}
					else{printf("\n");}
					
				}
			}
		}else if(n==4){
			for(i=0;i<100;i++){
				int bil = i*i;
				int temp = bil;
				int bil1 = temp/100;
				int bil2 = bil - bil1*100;
				int sum = bil1+bil2;

				if(sum*sum==bil){
					//print solution
					int banyakDigit = jumlahDigit(bil);
					//cetak brp banyak 0
					for(j=0;j<n-banyakDigit;j++){
						printf("0");
					}
					if(bil!=0){printf("%d\n",bil);}
					else{printf("\n");}
				}
			}
		}else if(n==6){
			for(i=0;i<1000;i++){
				int bil = i*i;
				int temp = bil;
				int bil1 = temp/1000;
				int bil2 = bil - bil1*1000;
				int sum = bil1+bil2;

				if(sum*sum==bil){
					//print solution
					int banyakDigit = jumlahDigit(bil);

					//cetak brp banyak 0
					for(j=0;j<n-banyakDigit;j++){
						printf("0");
					}
					if(bil!=0){printf("%d\n",bil);}
					else{printf("\n");}
				}
			}
		}else if(n==8){
			for(i=0;i<10000;i++){
				int bil = i*i;
				int temp = bil;
				int bil1 = temp/10000;
				int bil2 = bil - bil1*10000;
				int sum = bil1+bil2;

				if(sum*sum==bil){
					//print solution
					int banyakDigit = jumlahDigit(bil);
					//cetak brp banyak 0
					for(j=0;j<n-banyakDigit;j++){
						printf("0");
					}
					if(bil!=0){printf("%d\n",bil);}
					else{printf("\n");}
				}
			}
		}

	}
	return 0;
}


