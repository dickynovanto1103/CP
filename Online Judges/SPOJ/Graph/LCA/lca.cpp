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

void dfs(int cur, int depth) {
  H[cur] = idx;
  E[idx] = cur;
  L[idx++] = depth;
  for (int i = 0; i < AdjList[cur].size(); i++) {
    dfs(AdjList[cur][i], depth+1);
    E[idx] = cur;                              // backtrack to current node
    L[idx++] = depth;
  }
}

void buildRMQ() {
  idx = 0;
  memset(H, -1, sizeof H);
  dfs(0, 0);                       // we assume that the root is at index 0
}

class SegmentTree {         // the segment tree is stored like a heap array
private: vi st, A;            // recall that vi is: typedef vector<int> vi;
  int n;
  int left (int p) { return p << 1; }     // same as binary heap operations
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {                           // O(n log n)
    if (L == R)                            // as L == R, either one is fine
      st[p] = L;                                         // store the index
    else {                                // recursively compute the values
      build(left(p) , L              , (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R          );
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] <= A[p2]) ? p1 : p2;
  } }

  int rmq(int p, int L, int R, int i, int j) {                  // O(log n)
    if (i >  R || j <  L) return -1; // current segment outside query range
    if (L >= i && R <= j) return st[p];               // inside query range

     // compute the min position in the left and right part of the interval
    int p1 = rmq(left(p) , L              , (L+R) / 2, i, j);
    int p2 = rmq(right(p), (L+R) / 2 + 1, R          , i, j);

    if (p1 == -1) return p2;   // if we try to access segment outside query
    if (p2 == -1) return p1;                               // same as above
    return (A[p1] <= A[p2]) ? p1 : p2; }          // as as in build routine

  int update_point(int p, int L, int R, int idx, int new_value) {
    // this update code is still preliminary, i == j
    // must be able to update range in the future!
    int i = idx, j = idx;

    // if the current interval does not intersect 
    // the update interval, return this st node value!
    if (i > R || j < L)
      return st[p];

    // if the current interval is included in the update range,
    // update that st[node]
    if (L == i && R == j) {
      A[i] = new_value; // update the underlying array
      return st[p] = L; // this index
    }

    // compute the minimum pition in the 
    // left and right part of the interval
    int p1, p2;
    p1 = update_point(left(p) , L              , (L + R) / 2, idx, new_value);
    p2 = update_point(right(p), (L + R) / 2 + 1, R          , idx, new_value);

    // return the pition where the overall minimum is
    return st[p] = (A[p1] <= A[p2]) ? p1 : p2;
  }

public:
  SegmentTree(const vi &_A) {
    A = _A; n = (int)A.size();              // copy content for local usage
    st.assign(4 * n, 0);            // create large enough vector of zeroes
    build(1, 0, n - 1);                                  // recursive build
  }

  int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }   // overloading

  int update_point(int idx, int new_value) {
    return update_point(1, 0, n - 1, idx, new_value); }
};

int main() {
	int n,i,j,a,b, tc;
  scanf("%d",&tc);
  for(int tt=1;tt<=tc;tt++){
    printf("Case %d:\n",tt);
    scanf("%d",&n);
    AdjList.assign(n,vi());
    for(i=0;i<n;i++){
      int counter;
      scanf("%d",&counter);
      while(counter--){scanf("%d",&a); a--; AdjList[i].pb(a);}
      //scanf("%d %d",&a,&b); a--; b--; AdjList[a].pb(b);
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
      /*if(ans==nilaiAcuan){printf("TIDAK\n");}
      else{printf("YA\n");}*/
      printf("%d\n",ans+1);
      //printf("%d\n",E[idx]+1);
    }
  }
	
	return 0;
}