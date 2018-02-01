#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i,a[10010],sum,ans;
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		sum=ans=0;
		for(i=0;i<n;i++){
			sum+=a[i];
			ans=max(ans,sum);
			if(sum<0){sum=0;}//resetting from 0 again...kadane's algo
		}
		if(ans==0){printf("Losing streak.\n");}
		else{printf("The maximum winning streak is %d.\n",ans);}
	}
	return 0;
}