#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int sum,ans,idxAwal,idxAkhir,TC,N,curans;
	int i,j;
	int road[20010];

	scanf("%d",&TC);

	while(j=1;j<=TC;j++){
		idxAkhir=idxAwal=1;
		sum=ans=curans=0;
		scanf("%d",&N);
		for(i=1;i<N;i++){
			scanf("%d",&road[i]);
		}
		for(i=1;i<N;i++){
			sum+=road[i];
			ans=max(ans,sum);
			if(curans<ans){curans=ans;idxAkhir=i;}
			if(sum<0){ sum=0; idxAwal=idxAkhir=i+1;}
		}
		if(ans>0){printf("The nicest part of route %d is between stops %d and %d\n",j,idxAwal,idxAkhir+1);}
		else
			printf("Route %d has no nice parts\n",j);
	}

	return 0;
}