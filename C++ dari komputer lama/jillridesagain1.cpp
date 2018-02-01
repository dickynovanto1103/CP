#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

int main(){
	ll sum,ans;
	int i,j,TC,N,idxAwal,idxAkhir;
	ll road[20010];
	bool state;

	scanf("%d",&TC);

	for(j=1;j<=TC;j++){
		idxAwal=1;
		sum=ans=0;
		state=true;
		scanf("%d",&N);
		for(i=1;i<N;i++){
			scanf("%lld",&road[i]);
			//printf("test ke %d\n",i);
		}

		for(i=1;i<N;i++){
			if(sum+road[i]>=0){
				sum+=road[i];
				if(sum>ans){
					ans=sum;
				}
				if(!state){
					idxAwal=i;
					state=true;
				}
			}else{
				sum=0; 
				state=false;
			}
			/*printf("jumlah sekarang adalah : %d\n",ans);
			printf("idxAwal sekarang adalah : %d\n",idxAwal);*/

		}
		//mencari indeks akhir
		sum=0;
		for(i=idxAwal;i<N;i++){
			sum+=road[i];
			if(sum==ans){
				idxAkhir=i;
			}
			//printf("idxAkhir adalah : %d\n",idxAkhir);
		}
		if(ans>0){
			printf("The nicest part of route %d is between stops %d and %d\n",j,idxAwal,idxAkhir+1);
		}else{
			printf("Route %d has no nice parts\n",j);
		}
	}

	return 0;
}