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

bool cmp(ii a, ii b){
	if(a.first == b.first){
		return a.second > b.second;
	}
	return a.first > b.first;
}

int main(){
	int price, n,i,j;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&price, &n);
		int harapanPatungan = ((price + (n-1)) / n);
		int minimal = price / n;
		int beban;
		if(harapanPatungan == minimal){
			beban = harapanPatungan - 1;
		}else{
			beban = minimal-1;
		}
		vii listBil;
		

		int sumbangan = 0;
		int cntNyumbang = 0;
		int tot = 0;
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			tot += bil;
			listBil.pb(ii(bil, i));
			if(bil < harapanPatungan){sumbangan += bil; cntNyumbang++;}
		}
		if(n > price){
			printf("IMPOSSIBLE\n");
			continue;
		}
		if(tot < price){printf("IMPOSSIBLE\n"); continue;}

		sort(listBil.begin(), listBil.end(), cmp);
		// for(i=0;i<listBil.size();i++){
		// 	printf("%d(%d) ", listBil[i].first, listBil[i].second);
		// }
		// printf("\n");
		int butuh = price - sumbangan;
		int orangKaya = n - cntNyumbang;

		int harapanSekarang = (butuh + orangKaya - 1) / (orangKaya);
		// printf("harapanSekarang: %d butuh: %d\n",harapanSekarang,butuh);
		int cur = -1;

		vi listIdx;
		int sumSekarang = 0;
		bool isKenaNotValid = false;
		for(i=0;i<listBil.size();i++){
			if(listBil[i].first < harapanSekarang){listIdx.pb(i); isKenaNotValid = true;break;}
			if(cur != listBil[i].first) {
				cur = listBil[i].first;
				listIdx.pb(i);
				listBil[i].first = harapanSekarang;
				sumSekarang += listBil[i].first;
			}else{
				listBil[i].first = harapanSekarang;
				sumSekarang += listBil[i].first;
			}
		}
		if(!isKenaNotValid){
			listIdx.pb(listBil.size());
		}
		// printf("listIdx\n");
		// for(i=0;i<listIdx.size();i++){
		// 	printf("%d ",listIdx[i]);
		// }
		// printf("\n");
		int totalUangSekarang = 0;
		for(i=0;i<listBil.size();i++){
			totalUangSekarang += listBil[i].first;
		}
		// reverse(listIdx.begin(), listIdx.end());

		int need = totalUangSekarang - price;
		// printf("need: %d sumSekarang: %d butuh: %d\n",need,totalUangSekarang,price);
		// if(need < 0){assert(false);}
		int ukuran = listIdx.size();
		for(i=ukuran-2;i>=0;i--){
			if(need == 0){break;}
			int awal = listIdx[i], akhir = listIdx[i+1];
			// if(listBil[awal].first - 1 == beban){continue;}
			for(j=awal;j<akhir;j++){
				listBil[j].first--;

				if(listBil[j].first == beban){assert(false);}
				need--;
				if(need == 0){break;}
			}
			if(need == 0){break;}
		}

		if(need > 0){assert(false);}


		int ans[101];
		for(i=0;i<listBil.size();i++){
			ans[listBil[i].second] = listBil[i].first;
			// if(listBil[i].first <= 0){assert(false);}
		}

		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}	
		printf("\n");
	}
	
	return 0;
};