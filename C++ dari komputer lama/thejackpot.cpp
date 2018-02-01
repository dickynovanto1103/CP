#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int N,i,ans,sum,arr[10010];
	scanf("%d",&N);
	while(N!=0){
		for(i=1;i<=N;i++){
			scanf("%d",&arr[i]);
		}
		//compute
		sum=0;ans=0;
		for(i=1;i<=N;i++){
			if(sum+arr[i]>=0){
				sum+=arr[i];
				ans=max(ans,sum);
			}else{
				sum=0;
			}
		}
		if(ans>0){printf("The maximum winning streak is %d.\n",ans);}
		else{printf("Losing streak.\n");}
		scanf("%d",&N);
	}
	return 0;
}