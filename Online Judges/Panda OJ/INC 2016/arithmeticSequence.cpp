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

const int maxn = 5e4 + 5;

int a[maxn];
int left(int n){return (n<<1);}
int right(int n){return (n<<1)+1;}
class SegmentTree{
	private:
		int n;
		vi d,sip;

	public:
		void combine(int p, int l, int r){
			int mid = (l+r)/2;
			int diff = a[mid+1] - a[mid];
			if(d[left(p)]==inf && d[right(p)]==inf){
				sip[p] = 1;
			}else if(d[left(p)]==inf){
				sip[p] = (d[right(p)]==diff && sip[right(p)]);
			}else if(d[right(p)]==inf){
				sip[p] = (d[left(p)]==diff && sip[left(p)]);
			}else{
				sip[p] = (d[left(p)]==d[right(p)] && d[left(p)]==diff && sip[left(p)] && sip[left(p)]==sip[right(p)]);
			}
			d[p] = diff;
		}

		void build(int p, int l, int r){
			if(l==r){
				d[p] = inf;
				sip[p] = 1;
				return;
			}
			int mid = (l+r)/2;
			build(left(p),l,mid);
			build(right(p),mid+1,r);
			combine(p,l,r);
		}
		SegmentTree(int n){
			this->n = n;
			d.assign(4*n,0); sip.assign(4*n,0);
			build(1,1,n);
		}
		ii find(int p, int kiri, int kanan, int l, int r){
			if(kiri>=l && kanan<=r){
				//printf("masuk sini\n");
				return ii(sip[p],d[p]);
			}
			//printf("berarti sini\n");
			int mid = (kiri+kanan)/2;
			if(r<=mid){
				return find(left(p),kiri,mid,l,r);	
			}else if(l>mid){
				return find(right(p),mid+1,kanan,l,r);	
			}else{
				ii ans1 = find(left(p),kiri,mid,l,r);
				ii ans2 = find(right(p),mid+1,kanan,l,r);
				int sip1 = ans1.first ,sip2 = ans2.first, d1 = ans1.second, d2 = ans2.second;
				//printf("sip1: %d\n",sip1);
				int diff = a[mid+1] - a[mid];
				if(sip1==0 || sip2==0){return ii(0,d[p]);}
				if(d1==inf && d2==inf){
					return ii(1,d[p]);
				}else if(d1==inf){
					int pas1 = (d2==diff && sip2);
					return ii(pas1,d[p]);
				}else if(d2==inf){
					int pas1 = (d1==diff && sip1);
					return ii(pas1,d[p]);
				}else{
					int pas1 = (d2==diff && d1==d2 && sip1 && sip1==sip2);
					return ii(pas1,d[p]);
				}	
			}

			
			
			
		}
		int find(int l, int r){
			//printf("pasti sini\n");
			return find(1, 1,n,l,r).first;
		}
		
		void update(int p, int l, int r, int idx, int v){
			if(l==r){
				a[idx] = v;
				d[p] = inf; sip[p] = 1;
				return;
			}
			int mid = (l+r)/2;
			if(idx<=mid){
				update(left(p),l,mid,idx,v);	
			}else{
				update(right(p),mid+1,r,idx,v);
			}
			combine(p,l,r);		
		}

};

int main() {
	int i,j,tc,n,q;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d:\n",tt);
		scanf("%d %d",&n,&q);
		for(i=1;i<=n;i++){scanf("%d",&a[i]);}
		SegmentTree st(n);
		while(q--){
			int com, l,r,idx,v;
			scanf("%d",&com);
			if(com==1){
				scanf("%d %d",&idx,&v); st.update(1,1,n,idx,v);
			}
			else{
				scanf("%d %d",&l,&r); 
				int found = st.find(l,r);
				
				if(found){printf("YES\n");}
				else{printf("NO\n");}
			}
		}
	}
	
	return 0;
}