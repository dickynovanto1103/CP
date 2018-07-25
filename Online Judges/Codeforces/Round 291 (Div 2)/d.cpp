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
const int maxk = 17;
int a[maxn][6];
int n,m,k;
int sparse[6][maxn][maxk];
int tempAns[6];
void preprocess(){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			sparse[i][j][0] = a[j][i];
		}
	}

	for(i=0;i<m;i++){
		for(j=1;j<maxk;j++){
			for(int l = 0;l<n;l++){
				int idx = l;
				int idxSelanjutnya = idx + (1<<(j-1));
				sparse[i][idx][j] = max(sparse[i][idx][j-1], sparse[i][idxSelanjutnya][j-1]);
			}
		}
	}
}

int query(int idxKolom, int l, int r){
	int banyak = (r-l+1);
	int hasilLog = (int)((double)log(banyak) / (double)log(2));
	int idx = l;
	int idxSelanjutnya = r-(1<<hasilLog) + 1;
	int ans = max(sparse[idxKolom][idx][hasilLog], sparse[idxKolom][idxSelanjutnya][hasilLog]);
	return ans;
}

bool can(int banyak){
	int i,j;
	// printf("banyak: %d\n",banyak);
	for(i=0;i<n;i++){
		int idx = i;
		int idxSelanjutnya = idx + banyak - 1;
		if(idxSelanjutnya >= n){break;}
		int total = 0;
		// printf("idx: %d idxSelanjutnya: %d\n",idx,idxSelanjutnya);
		for(j=0;j<m;j++){
			tempAns[j] = query(j, idx, idxSelanjutnya);
			// printf("tempAns[%d]: %d\n",j,tempAns[j]);
			total += tempAns[j];
			// printf("total jadi: %d\n",total);
		}
		if(total<=k){
			return true;
		}
	}
	return false;
	
}

int main(){	
	int i,j;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}

	preprocess();

	//lakukan binser
	int ans[] = {0,0,0,0,0};
	int kiri = 1, kanan = n, mid;
	while(kiri<=kanan){
		mid = (kiri+kanan)/2;
		if(can(mid)){
			for(i=0;i<m;i++){
				ans[i] = tempAns[i];
			}

			kiri = mid+1;
		}else{
			kanan = mid-1;
		}
	}

	for(i=0;i<m;i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
};