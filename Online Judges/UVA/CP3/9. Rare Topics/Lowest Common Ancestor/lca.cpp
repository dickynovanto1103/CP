#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 100010;

vector<vi> AdjList;
int L[2*maxn], H[2*maxn], E[2*maxn], idx;

void dfs(int cur, int parent, int depth) {
  H[cur] = idx;
  E[idx] = cur;
  L[idx++] = depth;
  for (int i = 0; i < AdjList[cur].size(); i++) {
  	int v = AdjList[cur][i];
  	if(v!=parent){
  		dfs(v, cur, depth+1);
	    E[idx] = cur;                              // backtrack to current node
	    L[idx++] = depth;	
  	}
    
  }
}

void buildRMQ() {
  idx = 0;
  memset(H, -1, sizeof H);
  dfs(0, -1, 0);                       // we assume that the root is at index 0
}

class SegmentTree {
	private:
		vi st,A;
		int n;
		int left(int p){return p<<1;}
		int right(int p){return (p<<1) + 1;}

		void build(int p, int L, int R){
			if(L==R){st[p] = L;}
			else{
				build(left(p),L, (L+R)/2);
				build(right(p), (L+R)/2 + 1, R);
				int p1 = st[left(p)], p2 = st[right(p)];
				st[p] = (A[p1]<=A[p2]) ? p1:p2;
			}
		}

		int rmq(int p, int L, int R, int i, int j){
			if(i>R || j<L){return -1;}//outside range
			if(L>=i && R<=j){return st[p];}//inside range

			int p1 = rmq(left(p),L,(L+R)/2, i, j);
			int p2 = rmq(right(p), (L+R)/2 + 1, R, i, j);
			if(p1==-1) return p2;
			if(p2==-1) return p1;
			return (A[p1] <= A[p2]) ? p1 : p2;

		}
		int updatePoint(int p, int L, int R, int idx, int newValue){
			int i = idx, j = idx;
			if(j<L || i>R){return st[p];}//keluarin minimal idx di node itu aja
			if(L==i && R==j){
				A[i] = newValue; //update
				return st[p] = L; // pasti jd minimal karena minimal dr 1 node ya node itu sendiri
			}

			int p1 = updatePoint(left(p),L,(L+R)/2,idx, newValue);
			int p2 = updatePoint(right(p),(L+R)/2 + 1, R,idx, newValue);

			return st[p] = (A[p1]<=A[p2]) ? p1:p2;
		}
	public:
		SegmentTree(const vi& _A){
			A = _A;
			n = A.size();
			st.assign(4*n, 0);
			build(1,0,n-1);
		}
		int rmq(int i, int j){return rmq(1,0,n-1,i,j);}
		int updatePoint(int idx, int newValue){return updatePoint(1,0,n-1,idx,newValue);}
};

int main() {
	int n,i,j,a,b;
	scanf("%d",&n);
	AdjList.assign(n,vi());
	for(i=0;i<n-1;i++){
		scanf("%d %d",&a,&b); a--; b--;
		AdjList[a].pb(b); AdjList[b].pb(a);
	}
	
	buildRMQ();
	//printf("test\n");
	
	vi A;
	for(i=0;i<2*n;i++){A.pb(L[i]);}
	SegmentTree s(A);
	/*printf("H:");
	for(i=0;i<2*n;i++){printf(" %d",H[i]);}
	printf("\n");
	printf("E:");
	for(i=0;i<2*n;i++){printf(" %d",E[i]);}
	printf("\n");
	printf("L:");
	for(i=0;i<2*n;i++){printf(" %d",L[i]);}
	printf("\n");*/

	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&a,&b);
		a--; b--;
		if(a==b){printf("TIDAK\n"); continue;}
		//printf("awal a: %d b: %d\n",a,b);
		int nilaiAcuan = a;
		if(H[a] > H[b]){
			swap(a,b);
			nilaiAcuan = b;
			//printf("a: %d b: %d\n",a,b);
		}

		//printf("a: %d b: %d\n",a,b);
		int idx1 = H[a], idx2 = H[b];
		//printf("idx1: %d idx2: %d\n",idx1,idx2);
		int idx = s.rmq(idx1,idx2);
		//printf("idx: %d\n",idx);
		int ans = E[idx];
		/*printf("nilai acuan: %d\n",nilaiAcuan);
		printf("ans: %d\n",ans);*/
		if(ans==nilaiAcuan){printf("TIDAK\n");}
		else{printf("YA\n");}
		//printf("%d\n",E[idx]+1);
	}
	return 0;
}