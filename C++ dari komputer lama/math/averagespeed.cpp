#include <bits/stdc++.h>

using namespace std;

int main(){
	int jam,menit,detik,s,start,akhir,selisih;
	char c;
	double speed,jarak;
	while(cin>>jam>>c>>menit>>c>>detik){
		if(cin.peek()==' '){
			cin>>s;
			start=jam*3600+menit*60+detik;
			printf("start sekarang: %d\n",start);
			speed=(double)(s*1000)/3600.0;
		}else{
			akhir=jam*3600+menit*60+detik;
			printf("start sekarang: %d\n",start);
			printf("akhir sekarang: %d dan speed: %.2lf\n",akhir,speed);
			selisih=akhir-start;
			printf("selisih: %d\n",selisih);
			jarak=(selisih*speed)/1000.0;
			printf("%.2d:%.2d:%.2d %.2lf km\n",jam,menit,detik,jarak);
		}
		
	}
	return 0;
}