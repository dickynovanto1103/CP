#include <cstdio>
#include <math.h>
using namespace std;

int main(){
	int m,d,i,ans,hari;
	scanf("%d %d",&m,&d);//m = 1..jan dst...d=1 monday
	if(m==1 || m==3 ||m==5 ||m==7 ||m==8 ||m==10 ||m==12){hari=31;}
	else if((m==4 || m==6 ||m==9 ||m==11)){hari=30;}
	else{hari=28;}
	ans=1;
	int sisa = hari-(7-d+1);
	double tambahan = (double)sisa/7.0;
	ans += (int)ceil(tambahan);
	printf("%d\n",ans);
	return 0;
}