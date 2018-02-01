#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int n,m,a[50],b[520][50],i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	/*printf("list ada:\n");
	for(i=0;i<n;i++){printf("%d ",a[i]);}
	printf("\n");*/
	scanf("%d",&m);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&b[i][j]);
		}
	}
	/*printf("list kebutuhan:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(j>0){printf(" ");}
			printf("%d",b[i][j]);
		}
		printf("\n");
	}*/
	ll lo,mid,hi;
	ll maks = -1;
	for(i=0;i<m;i++){
		for(j=i+1;j<m;j++){
			//cari jumlah makanan maks yang pas
			lo = 0; hi = 2147483647;
			ll ans;
			//printf("i: %d j: %d\n",i,j);
			while(lo<=hi){
				mid = (lo+hi)/2;
				//cek dengan mid cukup atau ngga makanannya
				ll total;
				for(k=0;k<n;k++){
					total = mid*(ll)b[i][k] + mid*(ll)b[j][k];
					//printf("total: %lld\n",total);
					if(total>(ll)a[k]){break;}
				}
				if(k==n){
					ans = mid; lo = mid+1;
				}//cukup..batas mid ditinggikan
				else{hi = mid-1;}//ga cukup
			}
			//printf("ans: %lld\n",ans);
			maks = max(maks,ans);
		}
	}
	printf("%lld\n",maks);
	return 0;
}