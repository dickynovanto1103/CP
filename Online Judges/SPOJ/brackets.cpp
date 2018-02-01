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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 3e4 + 5;

struct Node{
	int nLeft, nRight;
	void init(int x, int y){
		nLeft = x; nRight = y;
	}
	void merge(Node &a, Node& b){
		int minim = min(a.nLeft, b.nRight);
		nLeft = a.nLeft + b.nLeft - minim;
		nRight = a.nRight + b.nRight - minim;
	}
};

int a[maxn];
Node st[4*maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

void build(int node, int l, int r){
	if(l==r){
		if(a[l]==1){
			st[node].init(1,0);	
		}else{
			st[node].init(0,1);
		}
	}else{
		int mid = (l+r)/2;
		build(left(node),l,mid);
		build(right(node),mid+1,r);

		st[node].merge(st[left(node)], st[right(node)]);
	}
}

void update(int node, int l, int r, int idx, int val){
	if(idx>r || idx<l){return;}

	if(l==r && idx==l){
		if(a[idx]==1){
			st[node].init(1,0);	
		}else{
			st[node].init(0,1);
		}
		return;
	}

	int mid = (l+r)/2;
	update(left(node),l,mid,idx,val);
	update(right(node),mid+1,r,idx,val);

	st[node].merge(st[left(node)], st[right(node)]);
}

int main(){
	int n,i,j,k,idx;
	string kata;
	int test = 1;
	
	while(scanf("%d",&n)!=EOF){
		printf("Test %d:\n",test++);
		scanf("%d",&n);
		cin>>kata;
		for(i=0;i<n;i++){
			if(kata[i]=='('){a[i+1] = 1;}
			else{a[i+1] = -1;}
		}
		int banyakIdx;
		build(1,1,n);
		//printf("awal: %d %d\n",st[1].nLeft, st[1].nRight);
		scanf("%d",&banyakIdx);
		for(i=0;i<banyakIdx;i++){
			scanf("%d",&idx);
			//printf("idx: %d ans: %d\n",idx,ans);

			if(idx==0){
				//printf("%d %d\n",st[1].nLeft, st[1].nRight);
				if(st[1].nLeft == 0 && st[1].nRight==0){printf("YES\n");}
				else{printf("NO\n");}
				
			}else{
				int val;
				if(a[idx]==-1){
					val = 1;
					
				}else{
					val = -1;

				}
				a[idx] = val;
				// printf("val jd %d\n",val);
				update(1,1,n,idx,val);
			}
		}
	}
	
	return 0;
};