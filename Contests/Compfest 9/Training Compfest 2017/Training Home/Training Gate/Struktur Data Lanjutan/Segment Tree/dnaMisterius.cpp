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
		vi sip,sum,minisum;
		int n;
	public:
		void build(int p, int l, int r){
			if(l==r){
				sip[p] = 0;
				sum[p]=a[l]; minisum[p]=a[l];
				return;
			}
			int mid = (l+r)/2;
			build(left(p),l,mid);
			build(right(p),mid+1,r);
			sum[p] = sum[left(p)] + sum[right(p)];
			minisum[p] = min(minisum[left(p)],sum[left(p)] + minisum[right(p)]);
			sip[p] = (sip[left(p)] & sip[right(p)]);
			//printf("l: %d r: %d mid: %d sum: %d minisum: %d\n",l,r,mid,sum[p],minisum[p]);
			if(sip[left(p)]==0 && sip[right(p)]==0){
				if(sum[p]==0 && minisum[p]==0){sip[p]=1;}
			}
			//printf("sip[%d]: %d\n",p,sip[p]);
		}
		SegmentTree(int n){
			sip.assign(4*n,0); minisum.assign(4*n,0); sum.assign(4*n,0);
			this->n = n;
			build(1,1,n);
		}
		int update(int p, int l, int r, int idx){
			int i = idx,j = idx;
			if(r<i || l>j){return sip[p];}//out of ranve
			if(l==idx && r==idx){
				a[idx] = -a[idx];//inverse
				//printf("a[%d] = %d p: %d\n",idx,a[idx],p);
				sum[p] = a[idx]; minisum[p] = a[idx];
				return sip[p]=0;
			}

			int mid = (l+r)/2;
			
			update(left(p),l,mid,idx);
			update(right(p),mid+1,r,idx);
			sum[p] = sum[left(p)] + sum[right(p)];
			minisum[p] = min(minisum[left(p)],sum[left(p)] + minisum[right(p)]);
			sip[p] = (sip[left(p)] & sip[right(p)]);
			/*printf("update\n");
			printf("l: %d r: %d mid: %d sum: %d minisum: %d\n",l,r,mid,sum[p],minisum[p]);*/
			if(sip[left(p)]==0 && sip[right(p)]==0){
				if(sum[p]==0 && minisum[p]==0){sip[p]=1;}
			}
			//printf("sip[%d]: %d\n",p,sip[p]);
		}
		int query(int p, int l, int r, int i, int j){
			return sip[p];
		}
};

int main() {
	int tc,n,i,j;
	string kata;
	scanf("%d",&tc);
	while(tc--){
		cin>>kata;
		n = kata.length();
		for(i=1;i<=n;i++){
			if(kata[i-1]=='('){a[i] = 1;}
			else{a[i] = -1;}
		}
		SegmentTree st(n);
		int com;
		string ans = "";
		while(scanf("%d",&com),(com!=-1)){
			int k;
			if(com==0){
				int jawab = st.query(1,1,n,1,n);
				if(jawab==0){ans+="T";}
				else{ans+="Y";}
			}
			else{scanf("%d",&k); st.update(1,1,n,k+1);}
		}
		cout<<ans<<endl;
	}
	return 0;
}