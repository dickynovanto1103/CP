#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	bool state;
	int N,i,idxAwal,idxAkhir;
	int a[20010];
	//penentuan indeks memakai bool state..kalau false:
													// nanti begitu true lagi, yg diperbaharui nilai idxawal dan akhir
											//kalau true: yg diperbaharui nilai idxAkhir aja
	printf("masukkan banyak elemen array:\n");
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&a[i]);
	}
	int sum,ans;
	sum=ans=0;
	
	for(i=1;i<=N;i++){
		if(sum+a[i]>=0){
			sum+=a[i];
			ans=max(ans,sum);
		}else{
			sum=0;
		}
	}
	printf("range maksimumnya adalah: %d\n",ans);
	return 0;
}