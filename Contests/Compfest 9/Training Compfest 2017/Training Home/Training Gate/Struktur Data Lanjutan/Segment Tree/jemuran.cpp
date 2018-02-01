#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int a[100010];
int left(int n){return (n<<1);}
int right(int n){return (n<<1) + 1;}
class SegmentTree{
	private:
		vi st;
		int n;
	public:
		void build(int p, int l, int r){
			if(l==r){
				st[p] = a[l];
				return;
			}
			int mid = (l+r)/2;
			build(left(p),l,mid);
			build(right(p),mid+1,r);
			st[p] = max(st[left(p)],st[right(p)]);
		}
		SegmentTree(int n){
			this->n = n;
			st.assign(4*n,0);
			build(1,1,n);
		}
		int query(int p, int l, int r, int i, int j){
			if(i > r || j < l){return -inf;}
			if(l>=i && r<=j){return st[p];}
			int mid = (l+r)/2;
			int a = query(left(p),l,mid,i,j);
			int b = query(right(p),mid+1,r,i,j);
			return max(a,b);
		}

};

int main() {
	int n,q,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%d",&a[i]);}
	SegmentTree st(n);
	scanf("%d",&q);
	while(q--){
		int b,c;
		scanf("%d %d",&b,&c);
		if(a[b]!=a[c]){printf("TIDAK\n");}
		else{
			int ans = st.query(1,1,n,b,c);
			//printf("ans: %d\n",ans);
			if(ans==a[b] && a[b]==a[c]){printf("YA\n");}
			else{printf("TIDAK\n");}
		}
	}
	return 0;
}