#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int N,i;
	double C[1010],W[1010],avg[1010],tempW,tempAvg,X;
	scanf("%d%lf",&N,&X);
	for(i=1;i<=N;i++){
		scanf("%lf",&W[i]);
	}
	for(i=1;i<=N;i++){
		scanf("%lf",&C[i]);
	}
	for(i=1;i<=N;i++){
		avg[i]=C[i]/W[i];
	}
	//mengurutkan W dan avg
	for(i=1;i<=N-1;i++){
		int idxMax=i;
		for(int j=i+1;j<=N;j++){
			if(avg[idxMax]<avg[j]){idxMax=j;}
		}
		//swap
		tempAvg=avg[idxMax];
		tempW=W[idxMax];
		avg[idxMax]=avg[i];
		W[idxMax]=W[i];
		avg[i]=tempAvg;
		W[i]=tempW;
	}
	/*for(i=1;i<=N;i++){
		printf("avg : %f W: %f\n",avg[i],W[i]);
	}*/
	//mulai pengurangan

	double total=0.0;
	i=1;
	while(i<=N && X>0){
		//printf("ke : %d\n",i);
		if(X>=W[i]){
			//printf("X lebih besar\nyang dibeli: %f\n",W[i]);
			X-=W[i];
			total+=avg[i]*W[i];
			i++;
		}else{
			//printf("X lebih kecil sama dengan W[i]\nyang dibeli: %f\n",X);
			
			total+=X*avg[i];
			X=0;
			i++;
		}
		//printf("sisa X: %f\n",X);
		//printf("total sekarang: %f\n",total);
		
	}
	printf("%.5lf\n",total);
	return 0;
}