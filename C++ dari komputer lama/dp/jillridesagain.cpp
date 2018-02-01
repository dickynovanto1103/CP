#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc,n,i,a[20010],j,ans,sum,akhir1,awal1,awal2,akhir2,awalfinal,akhirfinal;
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		//tiap kasus 2 kali traversal saja
		ans=sum=0;
		scanf("%d",&n);
		for(j=1;j<n;j++){scanf("%d",&a[j]);}
		for(j=1;j<n;j++){
			sum+=a[j];
			//printf("untuk j: %d sum: %d\n",j,sum,ans);
			if(sum>ans){akhir1=j+1; ans=sum;}
			if(sum<0){sum=0;}//reset
		}
		//printf("ans: %d\n",ans);
		//sudah tahu batas akhir
		sum=0;
		//awal=akhir-1;
		//mencari batas bawah
		for(j=akhir1-1;j>=1;j--){
			sum+=a[j];
			if(sum==ans){awal1=j;}
			//if(sum<0){sum=0;}//reset
		}
		if(ans==0){printf("Route %d has no nice parts\n",i);}
		else{
			ans=sum=0;
			for(j=1;j<n;j++){
				sum+=a[j];
				//printf("untuk j: %d sum: %d\n",j,sum,ans);
				if(sum>=max(ans,sum)){akhir2=j+1; ans=max(ans,sum);}
				if(sum<0){sum=0;}//reset
			}
			//printf("ans: %d\n",ans);
			//sudah tahu batas akhir
			sum=0;
			//awal=akhir-1;
			//mencari batas bawah
			for(j=akhir2-1;j>=1;j--){
				sum+=a[j];
				if(sum==ans){awal2=j;}
				//if(sum<0){sum=0;}//reset
			}
			if((akhir1-awal1) > (akhir2-awal2)){awalfinal=awal1; akhirfinal=akhir1;}
			else if((akhir1-awal1) < (akhir2-awal2)){awalfinal=awal2; akhirfinal=akhir2;}
			else{
				if(awal1>awal2){awalfinal=awal2;akhirfinal=akhir2;}
				else if(awal1<awal2){awalfinal=awal1;akhirfinal=akhir1;}
				else{awalfinal=awal1;akhirfinal=akhir1;}//bebas mau make awal dan akhir 1 atau 2
			}
			printf("The nicest part of route %d is between stops %d and %d\n",i,awalfinal,akhirfinal);
		}

	}
	return 0;
}