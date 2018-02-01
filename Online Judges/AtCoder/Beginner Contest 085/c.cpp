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

int main(){
	int n,y,i,j, sisa;
	scanf("%d %d",&n,&y);
	//1 komponen
	if(y%10000==0){
		int banyak = y/10000;
		if(banyak==n){
			printf("%d 0 0\n",banyak); return 0;
		}
	}
	if(y%5000==0){
		int banyak = y/5000;
		if(banyak==n){
			printf("0 %d 0\n",banyak); return 0;
		}
	}
	if(y%1000==0){
		int banyak = y/1000;
		if(banyak==n){
			printf("0 0 %d\n",banyak); return 0;
		}
	}

	//2 komponen
	//10 rb dan 5 rb sekalian sama 1 rb
	int banyak = y/10000;
	for(i=banyak;i>=0;i--){
		sisa = y-(i*10000);
		if(sisa%5000==0){
			int banyak2 = sisa/5000;
			if((banyak2+i)==n){
				printf("%d %d 0\n",i,banyak2); return 0;	
			}
		}
		if(sisa%1000==0){
			int banyak2 = sisa/1000;
			if((banyak2+i)==n){
				printf("%d 0 %d\n",i,banyak2); return 0;		
			}
		}
	}
	//5 rb dan 1 rb
	banyak = y/5000;
	for(i=banyak;i>=0;i--){
		sisa = y-(i*5000);
		if(sisa%1000==0){
			int banyak2 = sisa/1000;
			if((banyak2+i)==n){
				printf("0 %d %d\n",i,banyak2); return 0;
			}
		}
	}

	//3 komponen
	banyak = y/10000;
	for(i=banyak;i>=0;i--){
		sisa = y-(i*10000);

		if(sisa%1000==0){
			int banyak2 = sisa/1000;
			for(j=banyak2;j>=0;j--){
				int sisa2 = sisa-(j*1000);
				if(sisa2%5000==0){
					int banyak3 = sisa2/5000;
					if((i+j+banyak3)==n){
						printf("%d %d %d\n",i,banyak3,j); return 0;
					}
				}
				
			}
			
		}
	}
	printf("-1 -1 -1\n");
	return 0;
};