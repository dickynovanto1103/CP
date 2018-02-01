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

int a[50010];
int left(int n){return (n<<1);}
int right(int n){return (n<<1) + 1;}

struct Node{
	int bestLeftSum, bestRightSum, sum, bestSum;
	void set(int v){
		bestLeftSum = bestRightSum = sum = bestSum = v;
	}
	Node combine(Node n1, Node n2){
		Node temp;
		temp.bestLeftSum = max(n1.bestLeftSum,n1.sum + n2.bestLeftSum);
		temp.sum = n1.sum + n2.sum;
		temp.bestRightSum = max(n2.bestRightSum, n2.sum + n1.bestRightSum);
		temp.bestSum = max(max(n1.bestSum,n2.bestSum),n1.bestRightSum + n2.bestLeftSum);
		return temp;
	}
};

Node listTitik[200010];

class SegmentTree{
	private:
		int n;
		
	public:
		void build(int p, int l, int r){
			if(l==r){
				listTitik[p].set(a[l]);
				return;
			}
			int mid = (l+r)/2;
			build(left(p),l,mid);
			build(right(p),mid+1,r);
			
			listTitik[p] = listTitik[p].combine(listTitik[left(p)],listTitik[right(p)]);
			
			/*printf("l: %d r: %d mid: %d\n",l,r,mid);
			printf("st[%d]: %d\n",p,st[p]);
			printf("maksSum[%d]: %d\n",p,maksSum[p]);*/
		}
		SegmentTree(int n){
			this->n = n;
			
			build(1,1,n);
		}
		
		Node query(int p,int l, int r, int i, int j){
			
			if(i<=l && r<=j){return listTitik[p];}
			int mid = (l+r)/2;
			if(j<=mid){
				Node ans1 = query(left(p),l,mid,i,j); return ans1;
			}else if(i>mid){
				Node ans2 = query(right(p),mid+1,r,i,j); return ans2;
			}else{
				Node ans1 = query(left(p),l,mid,i,j);
				Node ans2 = query(right(p),mid+1,r,i,j);
				Node ans = ans.combine(ans1,ans2);
				return ans;	
			}
			
		}
		int query(int l, int r){
			return query(1,1,n,l,r).bestSum;
		}

};

int main() {
	int n,i,q,b,c;
	scanf("%d",&n);

	for(i=1;i<=n;i++){scanf("%d",&a[i]);}
	
	SegmentTree st(n);
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&b,&c);
		printf("%d\n",st.query(b,c));
	}
	return 0;
}