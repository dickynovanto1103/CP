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

ll a[50010];
int left(int n){return (n<<1);}
int right(int n){return (n<<1)+1;}

class SegmentTree{
	private:
		vi st;
		int n;
		int b[31][200010];
	public:
		void build(int p, int l, int r){
			if(l==r){
				st[p] = a[l];
				return;
			}
			int mid = (l+r)/2;
			build(left(p),l,mid);
			build(right(p),mid+1,r);
			st[p] = st[left(p)] + st[right(p)];
		}
		SegmentTree(int n){
			this->n = n;
			st.assign(4*n,0);
			memset(b,0,sizeof b);
			build(1,1,n);
		}
		void update(int p, int l, int r, int i, int j, int bit){
			
		}
		void query()
};

int main() {
	int n,q,i,j;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++){scanf("%lld",&a[i]);}
	SegmentTree st(n);
	while(q--){
		int com,l,r,b;
		scanf("%d",&com);
		if(com==1){scanf("%d %d %d",&l,&r,&b); st.update(1,1,n,l,r,b);}
		else{scanf("%d %d",&l,&r); printf("%lld\n",st.query(1,1,n,l,r));}
	}
	return 0;
}