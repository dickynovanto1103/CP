#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> ii;
int a[300010],idx[300010];
ii gab[300010];

bool acompare(ii a, ii b){return a.first < b.first;}
bool bcompare(ii a, ii b){return a.second < b.second;}

int main(){
	int i,j,n,m,c,d,idxc,idxd;
	bool selesai = false;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){scanf("%d",&a[i]); idx[a[i]]=i;}
	for(i=0;i<m;i++){
		scanf("%d %d",&c,&d); idxc = idx[c]; idxd = idx[d];
		if(idxc>=idxd){gab[i]=ii(idxd,idxc);}
		else{gab[i]=ii(idxc,idxd);}
	}
	//pengurutan pasangan indeks
	sort(gab,gab+m,acompare);
	/*printf("pertama:\n");
	for(i=0;i<m;i++){
		printf("%d %d\n",gab[i].first, gab[i].second);
	}*/

	int curidx=0,awal=gab[0].first;
	for(i=1;i<m;i++){
		if(gab[i].first!=awal){sort(gab+curidx,gab+i,bcompare); curidx=i; awal=gab[i].first;}
	}
	sort(gab+curidx,gab+m,bcompare);
	printf("akhir:\n");
	for(i=0;i<m;i++){
		printf("%d %d\n",gab[i].first, gab[i].second);
	}
	//pengurutan selesai
	curidx=0; // untuk indeks gabungan
	//iterasi pada array a
	long long ans=n;
	int selisih;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			printf("i: %d,j: %d\n",i,j);
			while(idx[a[i]] > gab[curidx].first && curidx<m){curidx++;}//cari curidx sampe yg nilainya lbh besar atau sama dengan dengan idx skrg
			printf("curidx: %d\n",curidx);
			//sudah dpt idx foe pair baru
			if(i<=gab[curidx].first && j>=gab[curidx].second){//dalam range ga boleh
				//hitung kombinasi
				if(i==gab[curidx].first && j==gab[curidx].second){
					selisih = j-i+1;
					ans = ans+((selisih)*(selisih-1))/2;
					ans--;
				}
				else{
					selisih = j-i;
					ans = ans+((selisih)*(selisih-1))/2;
				}
				i=j=gab[curidx].first;
				printf("penambahan: %d\n",((selisih)*(selisih-1))/2);
				i++;
				//ans--;
				//printf("benar\n");
				break;
			}
			printf("i: %d, j: %d,curans: %lld\n",i,j,ans);
		}
		if(j==n){
			j=n;
			selisih = j-i;
			ans = ans+((selisih)*(selisih-1))/2;
			//ans--;
			break;
		}
		i--;
	}
	printf("%lld\n",ans);
	return 0;
}