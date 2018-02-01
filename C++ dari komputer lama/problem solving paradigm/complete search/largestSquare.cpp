#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int m,n,i,j,q,tc,a,b,ans,k;
	bool found;
	string kata[110];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&m,&n,&q);
		printf("%d %d %d\n",m,n,q);
		for(i=0;i<m;i++){cin>>kata[i];}

		for(i=0;i<q;i++){
			int lebar = 1,x_awal, x_akhir, y_awal, y_akhir;
			scanf("%d %d",&a,&b);
			found = true;
			ans = 1;
			while(found){
				x_awal = a-lebar; x_akhir = a+lebar; y_awal = b-lebar; y_akhir = b+lebar;
				if(x_awal >=0 && x_akhir <m && y_awal >=0 && y_akhir <n){
					char karakter = kata[a][b];
					//cek dari node awal sampe akhir
					for(j=x_awal;j<=x_akhir && found;j++){
						for(k=y_awal;k<=y_akhir && found;k++){
							if(kata[j][k]!=karakter){found=false;}
						}
					}
					if(found){ans+=2; lebar++;}//ans dr 1 jd 3..jd 5..jd 7..dst
				}else{found=false;}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}