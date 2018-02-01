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

ll a[1200010];
ll left(ll n){return (n<<1LL);}
ll right(ll n){return (n<<1LL) + 1LL;}
class SegmentTree{
	private:
		vi st;
		int n;
	public:
		void build(ll p, int l, int r){
			if(l==r){st[p]=a[l]; return;}
			int mid = (l+r)/2;
			build(left(p),l,mid);
			build(right(p),mid+1,r);
			st[p] = st[left(p)] + st[right(p)];
			/*printf("p: %d l: %d r: %d mid: %d\n",p,l,r,mid);
			printf("st[%d] = %lld dari st[%d]: %lld + st[%d]: %lld\n",p,st[p],left(p),st[left(p)],right(p),st[right(p)]);*/
		}
		SegmentTree(int n){
			this->n = n;
			st.assign(4*n,0);
			build(1,1,n);
		}
		void update(ll p, int l, int r, int idx, ll v){
			int i = idx, j = idx;
			if(i>r || j<l){return;}//out of range
			if(l==idx && r==idx){
				a[idx] = v;
				st[p] = a[idx];
				return;
			}
			
			int mid = (l+r)/2;
			update(left(p),l,mid,idx,v);
			update(right(p),mid+1,r,idx,v);
			st[p] = st[left(p)] + st[right(p)];

		}
		void update(int idx, ll v){update(1,1,n,idx,v);}

		ll query(ll p, int l, int r, int i, int j){
			//printf("l: %d r: %d i: %d j: %d p: %d\n",l,r,i,j,p);
			if(i>r || j<l){ return 0;}
			if(l>=i && r<=j){
				//printf("mengembalikan: p: %d -> %lld\n",p,st[p]);
				return st[p];
			}
			int mid = (l+r)/2;
			ll ans1 = query(left(p),l,mid,i,j);
			ll ans2 = query(right(p),mid+1,r,i,j);
			/*printf("mid: %d\n",l,r,mid);
			printf("ans1: %lld ans2: %lld total: %lld\n",ans1,ans2,ans1+ans2);*/
			return (ans1+ans2);
		}
		ll query(int i, int j){
			return query(1,1,n,i,j);
		}
		vi getVector(){return st;}
};

int main() {
	int n,i,j,q;
	scanf("%d",&n);
	for(i=n;i>=1;i--){
		scanf("%lld",&a[i]);
		//printf("i: %d cnt jd: %d\n",i,cnt);
	}
	SegmentTree st(1200010);
	//printf("i: %d\n",i);
	int idx = n;
	scanf("%d",&q);
	while(q--){
		int com, l,r;
		scanf("%d",&com);
		//printf("idx: %d\n",idx);
		if(com==1){
			scanf("%d %d",&l,&r);
			int selisih = r-l;
			int idxAkhir = idx-l+1, idxAwal = idx-r+1;
			//if(idxAwal<1){idxAwal = 1;}
			/*printf("l: %d r: %d\n",l,r);
			printf("idxAwal: %d idxAkhir: %d\n",idxAwal,idxAkhir);*/

			printf("%lld\n",st.query(idxAwal,idxAkhir));
		}
		else{
			ll v;
			scanf("%lld",&v); idx++; st.update(idx,v);
			//printf("ditambahkan: %lld idx jd: %d\n",v,idx);
		}
	}
	//printf("cnt: %d\n",cnt);
	return 0;
}