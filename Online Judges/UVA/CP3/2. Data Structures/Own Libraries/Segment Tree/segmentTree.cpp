                                                   #include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
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

int main(){
	int n, a[100];
	scanf("%d",&n);
	for(int i=0;i<n;i++){scanf("%d",&a[i]);}
	vi A(a,a+n);
	
	SegmentTree S(A);
	int q;
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("RMQ(%d,%d) = A[%d] = %d\n",a,b,S.rmq(a,b),A[S.rmq(a,b)]);
	}

	S.updatePoint(5,100);
	printf("setelah terupdate\n");
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("RMQ(%d,%d) = A[%d] = %d\n",a,b,S.rmq(a,b),A[S.rmq(a,b)]);
	}
	return 0;
}