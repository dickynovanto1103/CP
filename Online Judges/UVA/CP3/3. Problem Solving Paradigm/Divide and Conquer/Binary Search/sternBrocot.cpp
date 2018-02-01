#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;

int main(){
	int a,b;
	ii kiri,kanan,tengah;
	while(scanf("%d %d",&a,&b), (a!=1 || b!=1)){
		kiri = ii(0,1); kanan = ii(1,0); tengah = ii(1,1);
		double tujuan1 = (double)a, tujuan2 = (double) b;
		double hasilakhir = tujuan1/tujuan2;
		//printf("%lf\n",hasil);
		//double hasiltengah = (double)tengah.first / (double)tengah.second;
		string kata = "";
		//printf("awal:\n");
		//printf("tengah first: %d tengah second: %d\n",tengah.first,tengah.second);
		while(tengah.first!=a || tengah.second!=b){
			double hasiltengah = (double)tengah.first / (double)tengah.second;	
			//printf("tengah first: %d tengah second: %d\n",tengah.first,tengah.second);
			if(hasiltengah > hasilakhir){//ke kiri
				kata+='L';
				kanan = ii(tengah.first,tengah.second);
				tengah = ii(kanan.first+kiri.first, kanan.second + kiri.second);
			}else if(hasiltengah < hasilakhir){//ke kanan
				kata+='R';
				kiri = ii(tengah.first,tengah.second);
				tengah = ii(kanan.first+kiri.first, kanan.second + kiri.second);
			}
		}
		cout<<kata<<endl;

	}
	return 0;
}