#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,q,a[50010],i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	/*for(i=0;i<n;i++){
		if(i>0){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");*/
	scanf("%d",&q);
	while(q--){
		int bil;
		scanf("%d",&bil);
		int idxawal = lower_bound(a,a+n,bil) - a;
		int idxakhir = upper_bound(a,a+n,bil) - a;
		if(idxakhir==n){idxakhir = -1;}//klo udah di luar batas atas array
		if(idxawal==n){idxawal--;}
		while(a[idxawal]>=bil && idxawal>0){idxawal--;}
		if(a[idxawal]>=bil){idxawal = -1;}//klo misal batas bawah array pun masih lebih besar dari bilangan
		//printf("idxawal: %d idxakhir: %d\n",idxawal,idxakhir);
		//printf("bil: %d idxawal: %d idxakhir: %d\n",bil,idxawal,idxakhir);
		if(idxawal==-1){printf("X ");}
		else{printf("%d ",a[idxawal]);}

		if(idxakhir==-1){printf("X");}
		else{printf("%d",a[idxakhir]);}		
		printf("\n");
	}
	return 0;
}