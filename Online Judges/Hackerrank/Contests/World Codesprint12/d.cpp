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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;
int a[maxn];
ll factorial[maxn];

const ll mod = 1000000000LL;


// class SegmentTree {
// 	private: 
// 		vi st;
// 		int n;

// 		int left(int n){return n<<1;}
// 		int right(int n){return (n<<1) + 1;}
// 		void build(int p, int l, int r) {
// 			//printf("p: %d\n",p);
// 			if(l==r){st[p] = fac(a[l]); return;}

// 			build(left(p),l,(l+r)>>1);
// 			build(right(p),((l+r)>>1)+1, r);
// 			ll bil1 = st[left(p)], bil2 = st[right(p)];
// 			st[p] = bil1+bil2;
// 		}
// 		ll rsq(int p, int l, int r, int i, int j) {
// 			//printf("l: %d r: %d i: %d j: %d\n",l,r,i,j);
// 			if(i>r || j<l){return -1;}
// 			if(l>=i && r<=j){return st[p];}
			
// 			ll bil1 = rsq(left(p), l, (l+r)>>1, i,j);
// 			ll bil2 = rsq(right(p), ((l+r)>>1) + 1, r, i,j);
// 			if(bil1==-1){return bil2;}
// 			if(bil2==-1){return bil1;}
// 			//printf("bil1: %lld bil2: %lld l: %d r: %d\n",bil1,bil2,l,r);
// 			return (bil1%mod+bil2%mod)%mod;
// 		}
// 		ll update(int p, int l, int r, int idx, ll newValue){
// 			int i = idx, j = idx;
// 			if(i>r || j<l){return st[p];}
// 			if(l==i && r==j){
// 				return st[p] = newValue;
// 			}

// 			ll bil1 = update(left(p), l, (l+r)>>1, idx, newValue);
// 			ll bil2 = update(right(p), ((l+r)>>1)+1,r , idx, newValue);
// 			return st[p] = (bil1%mod+bil2%mod)%mod;
// 		}
// 		ll updateOnlyIncrement(int p, int l, int r, int idx, ll newValue) {
// 			int i = idx, j = idx;
// 			if(i>r || j<l){return st[p];}
// 			if(l==i && r==j){
// 				st[p]*=newValue;
// 				st[p]%=mod;
// 				//printf("st[%d] dikali: %lld jd: %lld\n",p,newValue,st[p]);
// 				return st[p];
// 			}
// 			ll bil1 = updateOnlyIncrement(left(p), l, (l+r)>>1, idx, newValue);
// 			ll bil2 = updateOnlyIncrement(right(p), ((l+r)>>1)+1,r , idx, newValue);
// 			return st[p] = (bil1%mod+bil2%mod)%mod;
// 		}
// 	public:
// 		SegmentTree(int _n){
// 			n = _n;
// 			st.assign(4*n,0);

// 			build(1,0,n-1);
// 			//printf("halo\n");
// 		}
// 		ll rsq(int i, int j){return rsq(1,0,n-1,i,j);}
// 		ll update(int idx, ll newValue){return update(1,0,n-1,idx,newValue);}
// 		ll updateOnlyIncrement(int idx, ll newValue){return updateOnlyIncrement(1,0,n-1, idx, newValue);}
// };		

int main(){
	int n,m,i;
	factorial[0] = 1;
	for(i=1;i<=50;i++){
		factorial[i] = factorial[i-1]*i;
		factorial[i]%=mod;
		printf("i: %d fac: %lld\n",i,factorial[i]);
	}
	return 0;
};