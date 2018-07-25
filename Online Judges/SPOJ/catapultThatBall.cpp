#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000LL
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

const int maxn = 5e4 + 4;
const int maxk = 18;

int table[maxn][maxk+10];
int n,m,k;
int a[maxn];

void preprocess(){
	int i,j;
	for(i=0;i<n;i++){
		table[i][0] = a[i];
	}
	// printf("k: %d\n",k);
	// printf("n: %d\n",n);
	for(j=1;j<=k;j++){
		for(i=0;i<n;i++){
			int idxSelanjutnya = i + (1<<(j-1));
			// printf("i: %d j: %d\n",i,j);

			if(idxSelanjutnya >= n){break;}
			// printf("i: %d j: %d idxSelanjutnya: %d\n",i,j,idxSelanjutnya);
			// if(j==k){
			// 	printf("halo\n");
			// }
			// printf("idxSelanjutnya: %d\n",idxSelanjutnya);
			table[i][j] = max(table[i][j-1], table[idxSelanjutnya][j-1]);
			// printf("table[%d][%d]: %d\n",i,j,table[i][j]);
		}
	}

}

void printSparseTable(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<=k;j++){
			if(j){printf(" ");}
			printf("%d",table[i][j]);
		}
		printf("\n");
	}
}

int query(int l, int r){
	int i,j;
	int idx = l;
	
	// printf("l: %d r: %d\n",l,r);
	int banyak = r-l+1;
	int hasilLog = (int)((double)log(banyak) / (double)log(2));
	// printf("l: %d r: %d\n",l,r);
	// printf("banyak: %d hasilLog: %d\n",banyak,hasilLog);
	
	int idxSelanjutnya = r - (1<<hasilLog) + 1;
	int ans = max(table[l][hasilLog],table[idxSelanjutnya][hasilLog]);
	
	return ans;
}

int main(){
	scanf("%d %d",&n,&m);
	int i,j;

	k = maxk;

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	preprocess();

	// printSparseTable();

	int cnt = 0;
	while(m--){
		int l,r;
		scanf("%d %d",&l,&r);
		// printf("l awal: %d r awal: %d\n",l,r);

		if((r-l) <= 1){
			cnt++;
			continue;
		}


		l--;
		r--;
		// printf("l: %d r: %d\n",l,r);

		int maks = query(l,r-1);
		// printf("maks: %d\n",maks);
		if(maks <= a[l]){cnt++;}
	}
	printf("%d\n",cnt);
	return 0;
};