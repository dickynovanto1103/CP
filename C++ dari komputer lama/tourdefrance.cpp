#include <bits/stdc++.h>

using namespace std;

int main(){
	int f,r,i,j,a[110],b[110],cnt;
	double hasilbagi[1000],ans;
	while(scanf("%d %d",&f,&r)==2){
		for(i=0;i<f;i++){scanf("%d",&a[i]);}
		for(i=0;i<r;i++){scanf("%d",&b[i]);}
		cnt=0; ans=-1;
		for(i=0;i<r;i++){
			for(j=0;j<f;j++){
				hasilbagi[cnt] = (double)b[i] / (double) a[j];
				//printf("hasil bagi antara b[%d]: %d dengan a[%d]: %d adalah %.2lf\n",i,b[i],j,a[j],hasilbagi[cnt]);
				cnt++;
			}
		}
		sort(hasilbagi,hasilbagi+cnt);
		//printf("hasil bagi awal hingga akhir:\n");
		//for(i=0;i<cnt;i++){printf("%.2lf\n",hasilbagi[i]);}
		for(i=1;i<cnt;i++){ans=max(ans,hasilbagi[i]/hasilbagi[i-1]);}
		printf("%.2lf\n",ans);
	}
	return 0;
}