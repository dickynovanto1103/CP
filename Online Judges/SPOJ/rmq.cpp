#include <bits/stdc++.h>

using namespace std;
#define inf 10000000000000LL
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

int sparse[maxn][17];
int a[maxn];
int n,k;

void preprocess(){
	int i,j;
	for(i=0;i<n;i++){
		sparse[i][0] = a[i];
	}
	for(j=1;j<=k;j++){
		for(i=0;i<n;i++){
			int idxSelanjutnya = i+(1<<(j-1));
			printf("i: %d idxSelanjutnya: %d\n",i,idxSelanjutnya);
			if(idxSelanjutnya >= n){break;}
			sparse[i][j] = min(sparse[i][j-1], sparse[idxSelanjutnya][j-1]);
		}
	}
}

void printSparseTable(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<=k;j++){
			if(j){printf(" ");}
			printf("%d",sparse[i][j]);
		}
		printf("\n");
	}
}

ll query(int l, int r){
	int i,j;
	int banyakElemen = r-l + 1;
	int idx = l;
	ll ans = inf;
	// printf("k: %d\n",k);

	double jawab = log(banyakElemen) / log(2);
	printf("jawab: %lf\n",jawab);
	int lebar = (int)jawab;
	printf("lebar: %d\n",lebar);

	for(j=k;j>=0;j--){

		int idxSelanjutnya = idx + (1<<j) - 1;
		// printf("idx: %d idxSelanjutnya: %d j; %d\n",idx,idxSelanjutnya, j);
		if(idxSelanjutnya > r){continue;}
		ans = min(ans, (ll)sparse[idx][j]);
		// printf("ans jd: %lld\n",ans);
		idx += (1<<j);
	}
	return ans;
}

int main(){
	int q,i,j;
	scanf("%d",&n);

	for(i=0;;i++){
		if((1<<i) > n){k--;break;}
		k++;
	}
	printf("k: %d\n",k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	preprocess();
	printSparseTable();

	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		ll ans = query(l,r);
		
		printf("%lld\n",ans);
	}
	return 0;
};