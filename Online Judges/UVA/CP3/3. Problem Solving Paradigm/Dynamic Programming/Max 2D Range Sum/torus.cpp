#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int i,j,k,l,n,tc,a[160][160], b[160][160];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]);
				b[i][j] = a[i][j];
			}
		}
		//copy ke kanan dulu
		for(i=0;i<n;i++){
			for(j=n;j<2*n;j++){
				b[i][j] = a[i][j-n];
			}
		}
		//copy ke bawah
		for(i=n;i<2*n;i++){
			for(j=0;j<n;j++){
				b[i][j] = a[i-n][j];
			}
		}
		//copy ke kanan bawah
		for(i=n;i<2*n;i++){
			for(j=n;j<2*n;j++){
				b[i][j] = a[i-n][j-n];
			}
		}
		/*printf("b: \n");
		for(i=0;i<2*n;i++){
			for(j=0;j<2*n;j++){
				if(j>0){printf(" ");}
				printf("%d",b[i][j]);
			}
			printf("\n");
		}*/

		//proses dp
		for(i=0;i<2*n;i++){
			for(j=0;j<2*n;j++){
				if(i>0){b[i][j]+=b[i-1][j];}
				if(j>0){b[i][j]+=b[i][j-1];}
				if(i>0 && j>0){b[i][j] -= b[i-1][j-1];}
			}
		}
		int maks = -inf;
		
		for(i=0;i<2*n;i++){
			int batasi = i+n;
			if(batasi>=2*n){batasi = 2*n;}
			for(j=0;j<2*n;j++){
				int batasj = j+n;
				if(batasj>=2*n){batasj = 2*n;}
				for(k=i;k<batasi;k++){
					for(l=j;l<batasj;l++){
						int temp = b[k][l];
						if(i>0){temp-=b[i-1][l];}
						if(j>0){temp-=b[k][j-1];}
						if(i>0 && j>0){temp+=b[i-1][j-1];}
						maks = max(maks,temp);
						//printf("dari i: %d ke k: %d j: %d ke l: %d maks: %d\n",i,k,j,l,maks);
					}
				}
			}
		}

		printf("%d\n",maks);
	}
	
	

	return 0;
}