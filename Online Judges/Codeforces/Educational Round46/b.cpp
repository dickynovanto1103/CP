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

const int maxn = 1e5 + 5;

int main(){
	int n,i,j,m;
	scanf("%d %d",&n,&m);
	int a[maxn];
	a[0] = 0;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	a[i] = m;

	ll prefSumGanjil[maxn], prefSumGenap[maxn];
	ll suffSumGanjil[maxn], suffSumGenap[maxn];
	memset(prefSumGenap, 0, sizeof prefSumGenap);
	memset(prefSumGanjil, 0, sizeof prefSumGanjil);
	int idxTerakhirGenap, idxTerakhirGanjil;
	for(i=0;i<=n;i++){
		if(i%2==0){
			if(i==0){
				prefSumGenap[i] = a[i+1] - a[i];
			}else{
				prefSumGenap[i] = prefSumGenap[i-2] + (a[i+1] - a[i]);
			}
			// printf("a[%d]: %d - a[%d]: %d\n",i+1,a[i+1], i,a[i]);
			// printf("prefSumGenap[%d]: %lld\n",i,prefSumGenap[i]);
			idxTerakhirGenap = i;
		}else{
			if(i==1){
				prefSumGanjil[i] = a[i+1] - a[i];
			}else{
				prefSumGanjil[i] = prefSumGanjil[i-2] + (a[i+1] - a[i]);	
			}
			// printf("a[%d]: %d - a[%d]: %d\n",i+1,a[i+1], i,a[i]);
			// printf("prefSumGanjil[%d]: %lld\n",i,prefSumGanjil[i]);
			idxTerakhirGanjil = i;
		}
	}
	ll maks = 0;
	ll sum = 0;
	for(i=n;i>=0;i--){
		if(prefSumGenap[i]!=0){
			maks = prefSumGenap[i];
			break;
		}
	}

	for(i=0;i<=n;i++){
		//mau taruh dimana di antara a[i] sampe a[i+1]
		if((a[i+1] - a[i]) == 1){continue;}
		// printf("i: %d\n",i);
		if(i%2==0){
			//taruh di idx a[i+1] - 1
			// printf("diletakkan di: %d\n",a[i+1]-1);
			ll selisih = (a[i+1] - 1) - a[i];
			// printf("selisih: %lld\n",selisih);
			ll jumlahKanan = (i==0? prefSumGanjil[idxTerakhirGanjil] : prefSumGanjil[idxTerakhirGenap] - prefSumGanjil[i-1]);
			ll jumlahKiri = (i==0? 0: prefSumGenap[i-2]);

			// printf("jumlahKiri: %lld\n",jumlahKiri);
			// printf("jumlahKanan: %lld\n",jumlahKanan);

			ll total = selisih + jumlahKiri + jumlahKanan;
			if(total > maks){
				maks = total;
			}
		}else{
			ll selisih = a[i+1] - (a[i] + 1);

			ll jumlahKanan = (prefSumGanjil[idxTerakhirGanjil] - prefSumGanjil[i]);
			ll jumlahKiri = prefSumGenap[i-1];
			// printf("diletakkan di: %d\n", a[i] + 1);
			// printf("selisih: %lld\n",selisih);
			// printf("jumlahKiri: %lld\n",jumlahKiri);
			// printf("jumlahKanan: %lld\n",jumlahKanan);

			ll total = selisih + jumlahKiri + jumlahKanan;
			if(total > maks){
				maks = total;
			}
		}
	}

	printf("%lld\n",maks);
	return 0;
};