#include <stdio.h>

int main(){
	int n,i,j,x;
	scanf("%d %d",&n,&x);
	int ans = 0;
	int maks = 0, minim = 1000000000;
	int bil;
	for(i=0;i<n;i++){

		scanf("%d",&bil);
		if(bil <= x/2){
			ans++;
			maks = (bil > maks ? bil:maks);
		}
		else{
			minim = (bil < minim ? bil: minim);
		}
	}
	
	if(maks + minim <= x){ans++;}
	printf("%d\n",(ans == 0? 1: ans));
	
	
	// sort(a,a+n);
	// int ans = 1;
	// for(i=1;i<n;i++){
	// 	// printf("%d %d %d\n",i,a[i],a[i-1]);
	// 	if((a[i] + a[i-1]) > x){
	// 		break;
	// 	}else{
	// 		ans++;
	// 	}
	// }
	// printf("%d\n",ans);
	return 0;
};