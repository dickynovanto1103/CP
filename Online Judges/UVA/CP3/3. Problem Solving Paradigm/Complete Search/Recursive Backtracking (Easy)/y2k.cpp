#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	int s,d,i,j;
	while(scanf("%d %d",&s,&d)!=EOF){
		//generate all subset
		int a[12];
		ll ans = -1000000000;
		for(i=0;i<(1<<12);i++){
			bool isValid = true;
			int listbil[5];
			for(j=0;j<5;j++){listbil[j] = -1000000000;}
			
			for(j=0;j<12;j++){
				if(i & (1<<j)){a[j] = s;}
				else{a[j] = -d;}
			}
			/*for(j=0;j<12;j++){
				if(j>0){printf(" ");}
				printf("%d",a[j]);
			}
			printf("\n");*/
			ll sum = 0, total = 0;
			for(j=0;j<12;j++){
				int idx = j%5;
				if(listbil[idx]==-1000000000){
					listbil[idx] = a[j]; sum+=listbil[idx];
					//printf("sum: %d\n",sum);
					if(j==4){if(sum>=0){isValid = false; break;}}
				}else{
					sum-=listbil[idx]; listbil[idx] = a[j]; sum+=listbil[idx];
					//printf("sum sekarang: %d\n",sum);
					if(sum>=0){isValid = false;break;}//harus cari kombinasi yang lain
				}
				total+=a[j];
			}
			if(isValid){ans = max(ans, total);}

		}
		//printf("ans: %d\n",ans);
		if(ans<0){printf("Deficit\n");}
		else{printf("%d\n",ans);}
	}
	return 0;
}