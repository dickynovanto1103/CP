#include <cstdio>
#include <vector>
#include <math.h>
#include <cmath>

using namespace std;

vector <int> jumlah;

int main(){
	int n,i,j,q,angka,minim,ans,tc;
	int a[1010];
	tc=1;
	while(scanf("%d",&n),n){
		for(i=1;i<=n;i++){scanf("%d",&a[i]);}
		//proses masukkan ke vektor jumlah
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				jumlah.push_back(a[i]+a[j]);
			}
		}
		//for(i=0;i<jumlah.size();i++){printf("%d ",jumlah[i]);}
		//printf("\n");
		scanf("%d",&q);
		printf("Case %d:\n",tc);
		while(q--){
			scanf("%d",&angka);
			minim=abs(angka-jumlah[0]);
			ans=jumlah[0];
			for(i=1;i<jumlah.size();i++){
				if(abs(angka-jumlah[i])<minim){minim=abs(angka-jumlah[i]);ans=jumlah[i];}
			}
			printf("Closest sum to %d is %d.\n",angka,ans);
		}
		tc++;
		jumlah.clear();
	}
	return 0;
}