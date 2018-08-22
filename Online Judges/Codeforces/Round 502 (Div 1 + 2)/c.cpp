#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];
	// for(i=0;i<n;i++){
	// 	a[i] = i+1;
	// }
	// do{
	// 	for(i=0;i<n;i++){
	// 		printf("%d ",a[i]);
	// 	}
	// 	printf("\n");
	// }while(next_permutation(a,a+n));
	if(n == 1){printf("1\n");}
	else if(n==2){printf("2 1\n");}
	else if(n==3){
		printf("2 3 1\n");
	}else if(n==4){
		printf("3 4 1 2\n");
	}else{
		vi listBil;
		int naik, turun, sumMin = inf;
		int naikMin, turunMin;
		for(i=1;i<=n;i++){
			turun = n/i;
			if(n%i != 0){
				turun++;
			}
			naik = i;
			int sum = naik + turun;
			if(sumMin > sum){
				sumMin = sum;
				naikMin = naik;
				turunMin = turun;

			}
		}
		// printf("naikMin: %d\n",naikMin);
		// printf("sumMin: %d\n",sumMin);
		int bil = n - naikMin + 1;
		int batasAkhir = n;
		
		while(true){	
			if(bil <=0){
				bil = 1;
				// printf("masuk sini\n");
				// printf("bil: %d batasAkhir: %d\n",bil,batasAkhir);
				for(i=bil;i<=batasAkhir;i++){
					listBil.pb(i);

					// printf("yang dipush: %d\n",i);
					
				}
				break;
			}else{
				for(i=0;i<naikMin;i++){
					listBil.pb(bil + i);
					// printf("halo\n");
					// printf("yang dipush: %d\n",bil + i);
				}
			}
			batasAkhir = bil-1;
			bil-=naikMin;
			
		}

		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d",listBil[i]);
		}
		printf("\n");	
	}
	
	return 0;
};