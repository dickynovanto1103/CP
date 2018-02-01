#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i,j,maxorg,cnt,jumlahambil;
	bool found,foundjaw;
	while(scanf("%d",&n),(n>=0)){
		maxorg=-1;
		cnt=n;
		found=foundjaw=false;
		found=true;
		printf("%d coconuts, ",n);
		//cek kasus n=0 nanti klo masalah..siapa tau bermasalah
		for(i=1;i<=n;i++){//i= jumlah org
			found=true; cnt = n;
			for(j=1;j<=i && found;j++){
				jumlahambil = cnt/5;
				cnt-=jumlahambil;
				cnt--;
				if(cnt<0){found=false;}
			}
			if(found){
				if(cnt%i==0){maxorg=max(maxorg,i); foundjaw=true; break;}
			}
		}
		if(!foundjaw){printf("no solution\n");}
		else{printf("%d people and 1 monkey\n",maxorg);}
		
	}
	return 0;
}