#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;

bool bcompare(ii a, ii b){return a.second > b.second;}

int main(){
	int n,m,i,j;
	ii pas[10010];
	int bil;
	//printf("%d\n",-4%2);
	while(scanf("%d %d",&n,&m),(n||m)){
		for(i=0;i<n;i++){
			scanf("%d",&bil);
			pas[i] = ii(bil%m, bil);
		}
		sort(pas,pas+n);
		//pindahin yg ganjil ke atas
		for(i=1;i<n;i++){
			int curMod = pas[i].first;
			bil = pas[i].second;
			if(bil%2==1 || bil%2==-1){
				int j = i;
				int bilBanding = pas[j-1].second;
				while(pas[j-1].second % 2==0 && j>0 && pas[j-1].first==curMod){
					int temp = pas[j].second;
					pas[j].second = pas[j-1].second;
					pas[j-1].second = temp;
					j--;
				}
			}//klo ganjil, geser ke atas sampe atasnya ganjil dan kirinya ttp sama
		}
		
		//urutin naik yg ganjil saja
		int idxAwal = 0, idxAkhir;
		bool isGanjil = true;
		int curMod = pas[0].first;
		for(i=0;i<n;i++){
			if(isGanjil && curMod != pas[i].first){curMod = pas[i].first; isGanjil = true; sort(pas+idxAwal,pas+i, bcompare); idxAwal = i;}//tidak ketemu genap, tp ketemu lgsg beda mod..sort aja
			else if(curMod != pas[i].first && !isGanjil){curMod = pas[i].first; isGanjil = true; idxAwal = i;}// sudah ketemu genap sebelumnya, lalu ketemu ganjil baru karena sudah pasti ganjil diatas
			if(pas[i].second % 2==0 && isGanjil){idxAkhir = i; sort(pas+idxAwal,pas+idxAkhir, bcompare); isGanjil=false;}
		}
		//urutin klo ga nemu ganjil
		if(isGanjil){sort(pas+idxAwal, pas+i, bcompare);}
		/*printf("terurut:\n");
		for(i=0;i<n;i++){
			printf("%d %d\n",pas[i].first,pas[i].second);
		}*/
		printf("%d %d\n",n,m);
		for(i=0;i<n;i++){
			printf("%d\n", pas[i].second);
		}

	}
	printf("0 0\n");
	return 0;
}