#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	if(k==n || k==0){
		printf("0 0\n");
	}else{
		printf("1 ");
		
		/*int tengah = n/2;
		if(n%2==0){
			int maks = n/2;
			int selisih = abs(tengah-k);
			int ans;
			if(k<tengah){
				ans = maks-selisih+1;
			}else{
				ans = maks-selisih;
			}
			printf("%d\n",ans);
		}else{
			int maks = n/2+1;
			int tengah2 = n/2+1;*/
			/*if(k<=tengah){
				int selisih = abs(tengah-k);
				printf("%d\n",maks-selisih);	
			}else{
				int selisih = abs(tengah2-k);
				printf("%d\n",maks-selisih);
			}*/
			/*int selisih = abs(tengah-k);
			printf("%d\n",maks-selisih);
		}*/
		int maks = (n/3)*2;
		int jumlahOrang = n/3;
		if(k<=jumlahOrang){
			printf("%d\n",k*2);
		}else{
			int selisih;
			if(n%3==0){	
				selisih = abs(k-jumlahOrang);
				printf("%d\n",maks-selisih);
			}else if(n%3==1){
				jumlahOrang++;
				selisih = abs(k-jumlahOrang);
				printf("%d\n",maks-selisih);
			}else{
				jumlahOrang++;
				maks++;
				selisih = abs(k-jumlahOrang);
				printf("%d\n",maks-selisih);
			}
		}
		
	}
	return 0;
};