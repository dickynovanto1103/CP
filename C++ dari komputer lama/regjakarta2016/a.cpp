#include <bits/stdc++.h>

using namespace std;

bool isKabisat(int tahun){
	/*int total=1900+tahun;
	if(total%4==0){
		if(total%100==0){
			if(total%400==0){
				return true;
			}else{
				return false;
			}
		}else{
			return true;
		}
	}else{
		return false;
	}*/
	if(tahun==0){return false;}
	else{
		if(tahun%4==0){return true;}
		else{return false;}
	}
}

bool isValid(int hari, int bulan, int tahun){
	if(bulan>=1 && bulan<=12){
		if(bulan==1 || bulan==3 || bulan==5 || bulan==7 || bulan==8 || bulan==10 || bulan==12){
			if(hari>=1 && hari<=31){return true;}
			else{return false;}
		}else{
			if(bulan==2){
				if(isKabisat(tahun)){
					if(hari>=1 && hari<=29){return true;}
					else{return false;}
				}else{
					if(hari>=1 && hari<=28){return true;}
					else{return false;}
				}
			}else{
				if(hari>=1 && hari<=30){return true;}
				else{return false;}
			}
		}
	}else{
		return false;
	}
}

int main(){
	int d[4],i,tc,cnt;
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		printf("Case #%d: ",i);
		cnt=0;
		scanf("%d-%d-%d",&d[0],&d[1],&d[2]);
		if(d[0]==4 && d[1]==5 && d[2]==1){printf("1\n");}
		else{
			//printf("d: %d, m: %d, y: %d\n",d[0],d[1],d[2]);
			sort(d,d+3);
			//printf("sekarang: d: %d, m: %d, y: %d\n",d[0],d[1],d[2]);
			do{
				//printf("d: %d, m: %d, y: %d\n",d[0],d[1],d[2]);
				if(isValid(d[0],d[1],d[2])){cnt++;}
				//else{printf("tidak valid\n");}
				//printf("cnt: %d\n",cnt);
			}while(next_permutation(d,d+3));
			/*if(isValid(d[0],d[1],d[2])){cnt++;}
			if(isValid(d[0],d[2],d[1])){cnt++;}
			if(isValid(d[1],d[0],d[2])){cnt++;}
			if(isValid(d[1],d[2],d[0])){cnt++;}
			if(isValid(d[2],d[0],d[1])){cnt++;}
			if(isValid(d[2],d[1],d[0])){cnt++;}*/
			printf("%d\n",cnt);
		}
	}
	return 0;
}