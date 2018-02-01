#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a[110][110],i,j,cntodd,sum,brserror,kolerror;
	while(scanf("%d",&n),n){
		cntodd=0;
		for(i=1;i<=n;i++){
			sum=0;
			for(j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
				sum+=a[i][j];
			}
			if(sum%2==1){cntodd++;brserror=i;}
			sum=0;
		}
		if(cntodd>1){printf("Corrupt\n");}
		else{
			//hitung sum di tiap kolom
			if(cntodd==1){
				cntodd=0;//reset
				for(j=1;j<=n;j++){
					sum=0;
					for(i=1;i<=n;i++){
						sum+=a[i][j];
					}
					if(sum%2==1){cntodd++;kolerror=j;}
					sum=0;//reset
				}
				if(cntodd>1){printf("Corrupt\n");}
				else{//cntoddnya juga 1
					if(cntodd==1){printf("Change bit (%d,%d)\n",brserror,kolerror);}
					else{printf("Corrupt\n");}//karena klo awalnya cntoddnya 1 terus jd 0 waktu dicek per kolom...
				}
			}else{//cntodd = 0
				cntodd=0;//reset
				for(j=1;j<=n;j++){
					sum=0;
					for(i=1;i<=n;i++){
						sum+=a[i][j];
					}
					if(sum%2==1){cntodd++;kolerror=j;}
					sum=0;//reset
				}
				if(cntodd>=1){printf("Corrupt\n");}
				else{//cntoddnya juga 1
					printf("OK\n");
				}
			}
		}
	}
	return 0;
}