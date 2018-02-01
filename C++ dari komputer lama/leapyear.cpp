#include <cstdio>

using namespace std;

bool isLeap(long long tahun){
	if(tahun%4==0){
		if(tahun%100 ==0){
			if(tahun%400==0){return true;}
			else{return false;}
		}else{return true;}
	}else{return false;}
}

int main(){
	long long bil,tc=1;
	bool found;
	while(scanf("%lld",&bil)!=EOF){
		if(tc>1){printf("\n");}
		found=false;
		if(isLeap(bil)){printf("This is leap year.\n"); found=true;}
		if(bil%15==0){printf("This is huluculu festival year.\n"); found=true;}
		if(isLeap(bil) && bil%55==0){printf("This is bulukulu festival year.\n"); found=true;}

		if(!found){printf("This is an ordinary year.\n");}
		tc=2;
	}
	return 0;
}