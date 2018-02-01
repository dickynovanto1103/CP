#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int binarySearch(ii a[], int bil, int n, int idxTerpakai){
	int kiri = 0, kanan = n-1, mid;
	while(kiri<=kanan){
		mid = (kiri+kanan)/2;
		if(a[mid].first>bil){
			kanan = mid-1;
		}else if(a[mid].first<bil){
			kiri = mid+1;
		}else{
			if(mid==idxTerpakai){
				if(a[mid+1].first==a[mid].first){return a[mid+1].second+1;} //sudah ditambah 1
			}
			return a[mid].second+1;
		}//karena 0 based..yg diminta 1 based
	}
	return -1;
}

int main(){
	int tc,n,m,i,j;
	ii a[10010];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&m,&n);
		int angka;
		for(i=0;i<n;i++){scanf("%d",&angka); a[i].first = angka; a[i].second = i;}
		
		sort(a,a+n);
		/*printf("terurut\n");
		for(i=0;i<n;i++){
			printf("%d %d\n",a[i].first, a[i].second);
		}*/
		//printf("jawaban:\n");
		for(i=0;i<n;i++){
			if(m>a[i].first){
				int bil = m-a[i].first;
				//cari bil di sana

				int idx = binarySearch(a,bil,n,i);
				//printf("idx: %d\n",idx);
				//printf("di i: %d bil: %d idx: %d\n",i,bil,idx);
				int bil1 = a[i].second+1, bil2= idx;

				if(idx!=-1){
					if(bil1>bil2){printf("%d %d\n",bil2,bil1);}
					else{printf("%d %d\n",bil1,bil2);}
					break;
				}
			}
		}
	}
	return 0;
}