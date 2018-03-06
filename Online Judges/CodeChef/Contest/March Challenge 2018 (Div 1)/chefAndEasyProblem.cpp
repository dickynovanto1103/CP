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
int a[maxn];

struct Node {
	int mat[32];
};

Node titik[4*maxn], hasil, ans1, ans2, ans, answer;

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

void build(int node, int l, int r) {
	int i,j;
	if(l==r){
		int bil = a[l];
		for(j=0;j<31;j++){
			titik[node].mat[j] = 0;
		}
		for(j=0;j<31;j++){
			if(bil & (1<<j)) {
				titik[node].mat[j]++;
			}
		}
		// printf("bil: %d\n", bil);
		// for(j=30;j>=0;j--){
		// 	printf("%d",titik[node].mat[j]);
		// }
		// printf("\n");
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);
		// printf("l: %d mid: %d r: %d\n",l,mid,r);
		for(i=0;i<31;i++){
			titik[node].mat[i] = titik[left(node)].mat[i] + titik[right(node)].mat[i];
		}
		// printf("hasil gabung\n");
		// for(j=30;j>=0;j--){
		// 	printf("%d",titik[node].mat[j]);
		// }
		// printf("\n");
	}
}

Node query(int node, int l, int r, int i, int j) {
	
	if(l > j || r < i){return hasil;}
	if(i<=l && r<=j){return titik[node];}
	int mid = (l+r)/2;
	ans1 = query(left(node), l, mid, i, j);

	ans2 = query(right(node), mid+1, r, i, j);
	
	for(int t=0;t<31;t++){
		ans.mat[t] = ans1.mat[t] + ans2.mat[t];
	}
	return ans;
}


int main(){
	int i,j;
	int n,q;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	while(q--){
		
		int l, r;
		scanf("%d %d",&l, &r);
		
		
		answer = query(1,1,n,l,r);
		// printf("hasil query l: %d r: %d\n",l,r);
		// for(i=0;i<31;i++){
		// 	printf("ans.mat[%d]: %d\n",i,answer.mat[i]);
		// }

		int nilai = 0;
		int maks = r-l + 1;
		int batas;
		if(maks%2==0){
			batas = maks/2;
		}else{
			batas = maks/2 + 1;
		}
		for(j=0;j<31;j++){

			if(answer.mat[j]<batas){
				nilai+=(1<<j);
			}
		}
		printf("%d\n",nilai);
	}
	// a[0] = 11;
	// a[1] = 18;
	// a[2] = 2;
	// int banyakSatu[33];
	// memset(banyakSatu,0,sizeof banyakSatu);
	// for(i=0;i<3;i++){
	// 	int bil = a[i];
	// 	printf("bil: %d\n",bil);
	// 	for(j=0;j<31;j++){
	// 		if(a[i] & (1<<j)) {
	// 			printf("kena %d\n",(1<<j));
	// 			banyakSatu[j]++;
	// 		}
	// 	}
	// }
	// int nilai = 0;
	// for(j=0;j<31;j++){
	// 	printf("banyakSatu[%d]: %d\n",j,banyakSatu[j]);
	// 	int maks = 3;
	// 	int batas = maks/2;
	// 	if(banyakSatu[j]<=batas){
	// 		nilai+=(1<<j);
	// 		printf("nilai kena j: %d jd: %d\n",j,nilai);
	// 	}
	// }
	// printf("%d\n",nilai);

	return 0;
};