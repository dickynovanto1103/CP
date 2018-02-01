#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i,j;
	int a[80][80],b[80][80],c[80][80];
	scanf("%d %d",&n,&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d %d",&n,&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&b[i][j]);
		}
	}
	//cek sama
	bool found=true;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){	
			if(a[i][j]!=b[i][j]){found=false;break;}
		}
	}
	int temp;
	if(found){printf("identik\n");}
	else{//cek refleksional
		//cek vertikal
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				c[i][j]=a[i][n-j+1];
			}
		}
		/*for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				printf("%d ",c[i][j]);
			}
			printf("\n");
		}*/
		found=true;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(c[i][j]!=b[i][j]){found=false;break;}
			}
		}
		if(found){printf("vertikal\n");}
		else{
			//cek horisontal
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					c[i][j]=a[n-i+1][j];
				}
			}
			found=true;
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if(c[i][j]!=b[i][j]){found=false;break;}
				}
			}
			if(found){printf("horisontal\n");}
			else{
				for(i=1;i<=n;i++){
					for(j=1;j<=n;j++){
						c[i][j]=a[j][i];
					}
				}
				found=true;
				for(i=1;i<=n;i++){
					for(j=1;j<=n;j++){
						if(c[i][j]!=b[i][j]){found=false;break;}
					}
				}
				if(found){printf("diagonal kanan bawah\n");}
				else{
					for(i=1;i<=n;i++){
						for(j=1;j<=n;j++){
							c[i][j]=a[n-j+1][n-i+1];
						}
					}
					found=true;
					for(i=1;i<=n;i++){
						for(j=1;j<=n;j++){
							if(c[i][j]!=b[i][j]){found=false;break;}
						}
					}
					if(found){printf("diagonal kiri bawah\n");}
					else{printf("tidak identik\n");}
				}
			}
		}
	}
	return 0;
}