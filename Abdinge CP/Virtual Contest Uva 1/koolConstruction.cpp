#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int left(int n){return (n<<1);}
int right(int n){return (n<<1) + 1;}
//ll a[100010];


class SegmentTree{
	private:
		vi st,lazy;
		int n;
	public:
		void build(int p, int l, int r){
			if(l==r){
				st[p] = 0;
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
			lazy.assign(4*n,0);
			build(1,1,n);
		}

		void update(int p, int l, int r, int i, int j,ll v){
			if(lazy[p]!=0){//harus diupdate
				st[p]+=(r-l+1)*lazy[p];
				if(l!=r){//turun ke anak"nya
					lazy[left(p)]+=lazy[p]; lazy[right(p)]+=lazy[p];
				}
				lazy[p] = 0;
			}
			if(i>r || j < l){return;}
			if(l>=i && r<=j){
				st[p] += (r-l+1)*v;
				if(l!=r){
					lazy[left(p)]+=v;
					lazy[right(p)]+=v;
				}
				return;
			}
			int mid = (l+r)/2;
			update(left(p),l,mid,i,j,v);
			update(right(p),mid+1,r,i,j,v);
			st[p] = st[left(p)] + st[right(p)];

		}
		ll query(int p, int l, int r, int i, int j){
			if(i>r || j<l){return 0;}
			if(lazy[p]!=0){
				st[p]+=(r-l+1)*lazy[p];
				//printf("sini mungkin\n");
				if(l!=r){//turun ke anak"nya
					lazy[left(p)]+=lazy[p]; lazy[right(p)]+=lazy[p];
				}
				lazy[p] = 0;
			}
			if(l>=i && r<=j){return st[p];}
			//printf("bukannya sini\n");
			int mid = (l+r)/2;
			ll a = query(left(p),l,mid,i,j);
			ll b = query(right(p),mid+1,r,i,j);
			return (a+b);
		}
};

int main() {
	int n,i;
	while(scanf("%d",&n),n){
		char kar;
		int a,b;
		SegmentTree st(100010);
		for(i=0;i<n;i++){
			scanf("\n%c ",&kar);
			//printf("kar: %c\n",kar);
			int plus;

			if(kar=='B'){scanf("%d %d %d",&a,&b,&plus); st.update(1,1,100000,a,b,plus);}
			else{scanf("%d",&a); printf("%lld\n",st.query(1,1,100000,a,a));}

		}
	}
	return 0;
}