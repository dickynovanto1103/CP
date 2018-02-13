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

const int maxn = 2e4 + 4;
int a[maxn];
int st[4*maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}
void build(int node, int l, int r){
	if(l==r){
		st[node] = a[l];
	}else{
		int mid = (l+r)/2;
		build(left(node), l,mid);
		build(right(node), mid+1, r);
		st[node] = st[left(node)] & st[right(node)];
	}
}

int query(int node, int l, int r, int i, int j){
	if(i>r || j<l){return -1;}
	if(i<=l && r<=j){return st[node];}
	int mid = (l+r)/2;
	int ans1 = query(left(node), l, mid, i, j);
	int ans2 = query(right(node), mid+1, r, i, j);
	if(ans1==-1){return ans2;}
	if(ans2==-1){return ans1;}
	return ans1&ans2;
}

int main(){
	int n,i,j,tc,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		for(i=1;i<=n;i++){scanf("%d",&a[i]);}
		build(1,1,n);
		for(i=1;i<=n;i++){
			// printf("i: %d\n",i);
			if(i>1){printf(" ");}
			int ans;
			int idxAwal, idxAkhir;
			if(k>=n/2){
				ans = query(1,1,n,1,n);
			}else{
				idxAwal = i-k;
				idxAkhir = i+k;
				int ans1, ans2;
				if(idxAwal<=0){
					idxAwal+=n; ans1 = query(1,1,n,idxAwal,n);
					ans2 = query(1,1,n,1,idxAkhir);
					// printf("query %d ke %d dan %d ke %d\n",idxAkhir,n,1,idxAkhir);
				}else{
					if(idxAkhir>n){
						idxAkhir%=n; ans1 = query(1,1,n,1,idxAkhir);
						ans2 = query(1,1,n,idxAwal,n);
						//printf("query %d ke %d dan %d ke %d\n",idxAkhir,n,1,idxAkhir);
					}else{
						ans1 = query(1,1,n,idxAwal,i);
						ans2 = query(1,1,n,i,idxAkhir);
					}
				}
				ans = ans1&ans2;

			}
			

			printf("%d",ans);
		}
		printf("\n");
	}
	return 0;
};