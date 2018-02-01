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
			if(L==R){st[p] = A[L];}
			else{
				build(left(p),L, (L+R)/2);
				build(right(p), (L+R)/2 + 1, R);
				int p1 = st[left(p)], p2 = st[right(p)];
				st[p] = p1 + p2;
			}
		}

		int rsq(int p, int L, int R, int i, int j){
			if(i>R || j<L){return 0;}//outside range
			if(L>=i && R<=j){return st[p];}//inside range

			int p1 = rsq(left(p),L,(L+R)/2, i, j);
			int p2 = rsq(right(p), (L+R)/2 + 1, R, i, j);
			if(p1==0) return p2;
			if(p2==0) return p1;
			return p1+p2;

		}
		int updatePoint(int p, int L, int R, int idx, int newValue){
			int i = idx, j = idx;
			if(j<L || i>R){return st[p];}//keluarin minimal idx di node itu aja
			if(L==i && R==j){
				A[i] = newValue; //update
				return st[p] = A[i]; // pasti jd minimal karena minimal dr 1 node ya node itu sendiri
			}

			int p1 = updatePoint(left(p),L,(L+R)/2,idx, newValue);
			int p2 = updatePoint(right(p),(L+R)/2 + 1, R,idx, newValue);

			return st[p] = p1+p2;
		}
	public:
		SegmentTree(const vi& _A){
			A = _A;
			n = A.size();
			st.assign(4*n, 0);
			build(1,0,n-1);
		}
		int rsq(int i, int j){return rsq(1,0,n-1,i,j);}
		int updatePoint(int idx, int newValue){return updatePoint(1,0,n-1,idx,newValue);}
};

int main(){
	int n,i, test=1;
	while(scanf("%d",&n),n){
		if(test>1){printf("\n");}
		printf("Case %d:\n",test++);
		vi A;
		int bil;
		for(i=0;i<n;i++){scanf("%d",&bil); A.push_back(bil);}

		SegmentTree f(A);
		//cin>>ws;
		string command;
		while(cin>>command && command!="END"){
			//cout<<"command: "<<command<<", n: "<<n<<endl;
			if(command=="M"){
				//printf("test M\n");
				int a,b;
				scanf("%d %d",&a,&b); a--; b--;
				
				printf("%d\n",f.rsq(a,b));
				
			}else{//command R
				//printf("test S\n");
				int idx, val;
				scanf("%d %d",&idx,&val);
				idx--;
				
				f.updatePoint(idx,val);
				//printf("A[%d] = %d\n",idx,val);
			}
		}
	}
	

	return 0;
}