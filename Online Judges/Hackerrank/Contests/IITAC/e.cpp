#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main(){
	int n,i,j,q,banyak[1010],beli_di,f[1010];
	ll banyak_beli;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&banyak[i]);
		int bil;
		int curgcd = 0;
		for(j=0;j<banyak[i];j++){scanf("%lld",&bil); curgcd = __gcd(curgcd,bil);}
		f[i] = curgcd;
	}
	/*for(i=0;i<n;i++){
		for(j=0;j<banyak[i];j++){
			if(j>0)printf(" ");
			printf("%lld",e[i][j]);
		}
		printf("\n");
	}*/
	scanf("%d",&q);

	//printf("q: %d\n",q);
	while(q--){
		bool found = false;
		scanf("%lld %d",&banyak_beli,&beli_di);
		beli_di--;
		int i = beli_di;
		if(banyak_beli%f[i]==0){printf("Ya\n");}
		else{printf("Tidak\n");}
	}
	return 0;
}