#include <bits/stdc++.h>

using namespace std;

int a[1000010];

int main(){
	int i,j,k,l,m;
	map<int,int> mapper;
	map<int,int>::iterator it, it2;
	int tc;
	scanf("%d",&tc);
	int test=0;
	while(tc--){
		test++;
		int n;
		int ans = -1;
		scanf("%d",&n);
		int bil;
		for(i=0;i<n;i++){
			scanf("%d",&bil); a[i] = bil;
		}
		int cnt = 0;
		//mapper buat ngemap idx ke elemen array
		//mapper2 buat ngemap elemen array ke idx
		int depan = 0;
		//cara penghapusan: satu"cari iterator a[depan] sampe a[belakang]...hapus satu"
		for(i=0;i<n;i++){
			//printf("depan: %d belakang: %d\n",depan,belakang);
			it = mapper.find(a[i]);
			if(it==mapper.end()){mapper[a[i]] = i;}
			else{
				ans = max(ans,(int)mapper.size());
				int belakang = it->second;//idx ditemukannya a[i]
				/*printf("ans sekarang: %d\n",ans);
				printf("sebelum dihapus:\n");
				for(it=mapper.begin(); it!=mapper.end();it++){printf("%d->%d\n",it->first,it->second);}	*/
				
				//printf("depan: %d belakang: %d\n",depan,belakang);
				for(j=depan;j<=belakang;j++){
					it = mapper.find(a[j]);
					mapper.erase(it);
				}
				/*printf("setelah dihapus:\n");
				for(it=mapper.begin(); it!=mapper.end();it++){printf("%d->%d\n",it->first,it->second);}	*/
				depan = belakang+1;
				mapper[a[i]] = i;
				//dptin iterator mapper yg idxnya
				
				/*printf("sesudah ditambahkan:\n");
				for(it=mapper.begin(); it!=mapper.end();it++){printf("%d->%d\n",it->first,it->second);}	*/
								
				//depan = idx;
			}//ketemu ga sama
		}
		/*printf("mapper akhir:\n");
		for(it=mapper.begin(); it!=mapper.end();it++){printf("%d->%d\n",it->first,it->second);}*/
		ans = max(ans,(int)mapper.size());
		/*printf("isi map akhir: \n");
		for(it=mapper.begin(); it!=mapper.end();it++){printf("%d->%d\n",it->first,it->second);}
		printf("ans = %d\n",ans);*/

		printf("%d\n",ans);
		mapper.clear();
	}
	
	return 0;
}	