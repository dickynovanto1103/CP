#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;

vector<ii> listpair;
int main(){
	int i,j,k,l,m,a[30];
	int tc,n;
	scanf("%d",&tc);
	int test = 1;
	while(tc--){
		//printf("test %d\n",test++);
		scanf("%d",&n);
		int minim = 1000000000;
		int ans[5];
		int r[26],c[26],banyak[26];
		int listbil[26];
		for(i=0;i<n;i++){scanf("%d %d %d",&r[i],&c[i],&banyak[i]) ;}
		for(i=0;i<25;i++){
			for(j=i+1;j<25;j++){
				for(k=j+1;k<25;k++){
					for(l=k+1;l<25;l++){
						for(m=l+1;m<25;m++){
							//proses total jarak
							//printf("i: %d j: %d k: %d l: %d m: %d\n",i,j,k,l,m);
							int sum = 0;
							listpair.clear();
							listpair.push_back(ii(i/5,i%5)); listpair.push_back(ii(j/5,j%5)); listpair.push_back(ii(k/5,k%5)); listpair.push_back(ii(l/5,l%5)); listpair.push_back(ii(m/5,m%5));
							//list semua koordinat office
							for(int t = 0;t<n;t++){
								int x  = r[t]; int y = c[t];//dapetin koordinat tiap node
								
								int minjarak = 1000000000;
								for(int tt=0;tt<5;tt++){//iterasi tiap office...cari jarak antara area tertentu dengan area post..cari minimal
									ii pair = listpair[tt];
									int jarak = abs(pair.first-x) + abs(pair.second-y);
									if(minjarak > jarak){minjarak = jarak;}
									
									//printf("sum menjadi: %d\n",sum);
								}
								//printf("minjarak: %d banyak[%d] = %d\n",minjarak,t,banyak[t]);
								sum= sum+minjarak*banyak[t];

							}
							
							//printf("i: %d j: %d k: %d l: %d m: %d sum: %d\n",i,j,k,l,m,sum);
							if(minim > sum){
								minim = sum;
								//printf("minim: %d ",minim);
								ans[0] = i; ans[1] = j; ans[2] = k; ans[3] = l; ans[4] = m;
							}
							
						}
					}
				}
			}
		}
		for(i=0;i<5;i++){
			if(i>0){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}