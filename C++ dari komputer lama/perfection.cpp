#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,arr[60000],i,idx,sum;
	printf("PERFECTION OUTPUT\n");
	while(scanf("%d",&a),a){
		sum=0;
		for(i=1;i<=a/2;i++){
				if(a%i==0){sum+=i;}
				//printf("sum sekarang: %d\n",sum);
		}
		if(a>9999){printf("");}//cetak 0 spasi
		else if(a > 999){printf(" ");}//1 spasi
		else if(a > 99){printf("  ");}//2 spasi
		else if(a > 9){printf("   ");}//3 spasi
		else{printf("    ");}//4spasi
		printf("%d  ",a);
		if(sum==a){printf("PERFECT\n");}
		else if(sum>a){printf("ABUNDANT\n");}
		else{printf("DEFICIENT\n");}
	}
	printf("END OF OUTPUT\n");
	return 0;
}