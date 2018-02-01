#include <bits/stdc++.h>

using namespace std;

int main(){
	int i,j,cnt=0,k,l;
	char a[5][5];
	bool found=false;
	for(i=0;i<4;i++){
		scanf("%s",a[i]);
		//printf("kata ke %d adalah %s\n",i,a[i]);
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(a[i][j]=='.'){
				a[i][j]='x';
				/*printf("menjadi:\n");
				for(i=0;i<4;i++){
					for(j=0;j<4;j++){
						printf("%c",a[i][j]);
					}
					printf("\n");
				}*/
				for(k=0;k<4;k++){
					for(l=0;l<4;l++){
						if(l>=0 && l<=1){
							if(a[k][l]=='x' && a[k][l+1]=='x' && a[k][l+2]=='x'){printf("YES\n");found=true;}//cek horisontal
						}
						if(!found){
							if(k>=0 && k<=1){
								if(a[k][l]=='x' && a[k+1][l]=='x' && a[k+2][l]=='x'){printf("YES\n");found=true;}//cek vertikal
							}
						}
						if(!found){	
							if(k>=0 && k<=1){
								if(l<=1){
									if(a[k][l]=='x' && a[k+1][l+1]=='x' && a[k+2][l+2]=='x'){printf("YES\n");found=true;}//cek diagonal kanan bawah
								}else{
									if(a[k][l]=='x' && a[k+1][l-1]=='x' && a[k+2][l-2]=='x'){printf("YES\n");found=true;}//cek diagonal kiri bawah
								}
							}
						}
						
					}
					if(found){break;}
				}
				a[i][j]='.';//reset
			}
			if(found){break;}
		}
		if(found){break;}
	}
	if(!found){printf("NO\n");}
	return 0;
}