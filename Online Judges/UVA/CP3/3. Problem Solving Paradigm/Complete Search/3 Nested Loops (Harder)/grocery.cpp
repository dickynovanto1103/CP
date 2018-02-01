#include <bits/stdc++.h>

using namespace std;
#define eps 1e-9
int main(){
	double i,j,k,l,a,b,c;
	for(i=0.01;i<=20.00;i+=0.01){

		for(j=i;j<=(20.00-i);j+=0.01){
			//if(fabs(i- 1.10)<=eps){printf("j: %.2lf\n",j);}
			double hasilKali = i*j;
			if(hasilKali>20.00){break;}
			else{
				for(k=j;k<=(20.00-i-j);k+=0.01){
					//if(fabs(i- 1.10)<=eps && fabs(j- 1.50)<=eps){printf("k: %.2lf\n",k);}
					double b = hasilKali*k;
					if(b>20.00){break;}
					else{
						double a = i+j+k;
						
						//printf("a: %lf b: %lf\n",a,b);
						double z = a/(b-1.0);
						double temp = (double)round(z*100) / 100.0;//rounding to 2 nearest digit
						//if(fabs(i- 1.10)<=eps && fabs(j- 1.50)<=eps && fabs(k- 2.00)<=eps){printf("z: %.10lf temp: %.10lf\n",z,temp);}
						//printf("z: %lf dibulatkan jadi %lf\n",z,temp);
						//if(z==2.00 && i==1.10 && j==1.50 && k==2.00){printf("masuk sini\n");}
						if(fabs(z-temp)> eps){continue;}
						//if(fabs(i- 1.10)<=eps && fabs(j- 1.50)<=eps && fabs(k- 2.00)<=eps){printf("z: %.10lf temp: %.10lf\n",z,temp);}
						double jumlah = a+temp;
						double kali = b*temp;
						/*if(fabs(i- 1.10)<=eps && fabs(j- 1.50)<=eps && fabs(k- 2.00)<=eps){
							printf("temp: %lf k: %lf\n",temp,k);
							if(temp>k || fabs(temp-k)<=eps){printf("jumlah: %.10lf kali: %.10lf\n",jumlah,kali);}
							
						}*/
						//if(fabs(jumlah-kali)>eps){continue;}
						//if(z>=k){printf("masuk sini\n");}
						//printf("tambah: %.9lf kali: %.9lf\n",tambahAkhir,kaliAkhir);
						if((temp>k || fabs(temp-k)<=eps) && jumlah<=20.00 && kali<=20.00){
							//if(fabs(i- 1.10)<=eps && fabs(j- 1.50)<=eps && fabs(k- 2.00)<=eps){printf("khusus %.2lf %.2lf %.2lf %.2lf\n",i,j,k,temp);}
							printf("%.2lf %.2lf %.2lf %.2lf\n",i,j,k,temp);
							//printf("tambah: %.9lf kali: %.9lf a: %.9lf b: %.9lf z: %.9lf\n",tambahAkhir,kaliAkhir,a,b,z);
							//printf("masuk sini dengan selisih: %.10lf\n",fabs(tambahAkhir - kaliAkhir));
						}
					}
				}
			}
		}
	}
	return 0;
}