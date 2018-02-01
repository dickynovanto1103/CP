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
typedef vector<char> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1024002;
int a[maxn], st[4*maxn];
int lazy[4*maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

void build(int node, int l, int r){
	if(l==r){
		st[node] = a[l];
	}else{
		int mid = (l+r)/2;
		build(left(node),l,mid);
		build(right(node),mid+1,r);

		st[node] = st[left(node)] + st[right(node)];
	}
}

int query(int node, int l, int r, int i, int j){
	if(i>r || j<l){return 0;}
	// printf("awal l: %d r: %d i: %d j: %d\n",l,r,i,j);
	if(lazy[node]<inf){
		if(lazy[node]==1){
			st[node] = (r-l+1);
		}else{
			st[node] = 0;
		}
		if(l!=r){
			lazy[left(node)] = lazy[node];
			lazy[right(node)] = lazy[node];
		}
		lazy[node] = inf;
	}else if(lazy[node]>inf){
		if(lazy[node]%2==1){
			st[node] = (r-l+1) - st[node];
			if(l!=r){
				if(lazy[left(node)]==1 || lazy[left(node)]==0){
					lazy[left(node)] = 1-lazy[left(node)];
				}else{
					lazy[left(node)]++;
				}
				if(lazy[right(node)]==1 || lazy[right(node)]==0){
					lazy[right(node)] = 1-lazy[right(node)];
				}else{
					lazy[right(node)]++;
				}
			}
			lazy[node] = inf;
		}
		
		
	}
	// printf("l: %d r: %d i: %d j: %d\n",l,r,i,j);
	
	if(i<=l && r<=j){
		// printf("direturn st[%d]: %d\n",node,st[node]);
		return st[node];
	}

	int mid = (l+r)/2;
	int ans1 = query(left(node),l,mid,i,j);
	int ans2 = query(right(node),mid+1,r,i,j);
	// printf("l: %d r: %d mid: %d i: %d j: %d\n",l,r,mid,i,j);
	// printf("ans1: %d ans2: %d total: %d\n",ans1,ans2,ans1+ans2);
	return ans1+ans2;
}

void update(int node, int l, int r, int i, int j, char com){
	// printf("awal l: %d r: %d i: %d j: %d\n",l,r,i,j);
	if(lazy[node]<inf){
		if(lazy[node]==1){
			st[node] = (r-l+1);
		}else{
			st[node] = 0;
		}
		if(l!=r){
			lazy[left(node)] = lazy[node];
			lazy[right(node)] = lazy[node];
		}
		lazy[node] = inf;
	}else if(lazy[node]>inf){
		if(lazy[node]%2==1){
			st[node] = (r-l+1) - st[node];
			if(l!=r){
				if(lazy[left(node)]==1 || lazy[left(node)]==0){
					lazy[left(node)] = 1-lazy[left(node)];
				}else{
					lazy[left(node)]++;
				}
				if(lazy[right(node)]==1 || lazy[right(node)]==0){
					lazy[right(node)] = 1-lazy[right(node)];
				}else{
					lazy[right(node)]++;
				}
			}
			lazy[node] = inf;
		}
		
		
	}

	if(i>r || j<l){return;}
	if(i<=l && r<=j){
		if(com=='F'){
			st[node] = (r-l+1);
			if(l!=r){
				lazy[left(node)] = 1;
				lazy[right(node)] = 1;
			}
		}else if(com=='E'){
			st[node] = 0;
			if(l!=r){
				lazy[left(node)] = 0;
				lazy[right(node)] = 0;
			}
		}else if(com=='I'){
			st[node] = (r-l+1)-st[node];
			if(l!=r){
				if(lazy[left(node)]==1 || lazy[left(node)]==0){
					lazy[left(node)] = 1-lazy[left(node)];
				}else{
					lazy[left(node)]++;
				}
				if(lazy[right(node)]==1 || lazy[right(node)]==0){
					lazy[right(node)] = 1-lazy[right(node)];
				}else{
					lazy[right(node)]++;
				}
			}
		}
		return;
	}

	int mid =(l+r)/2;
	update(left(node),l,mid,i,j,com);
	update(right(node),mid+1,r,i,j,com);

	st[node] = st[left(node)] + st[right(node)];
}

int main(){
	
	int i,j,n,q,tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		for(i=0;i<4*maxn;i++){lazy[i] = inf;}

		string kata = "";
		printf("Case %d:\n",tt);
		int pair;
		scanf("%d",&pair);
		while(pair--){
			int ulang;
			string kata1;
			scanf("%d",&ulang);
			cin>>kata1;
			while(ulang--){kata+=kata1;}
		}
		
		int pjg = kata.length();
		for(i=0;i<pjg;i++){a[i+1] = kata[i]-'0';}
		
		int n = pjg;
		build(1,1,n);
		
		scanf("%d",&q);
		int jumlahHasil = 1;
		while(q--){
			char com;
			int l, r;
			scanf("\n%c %d %d",&com,&l,&r);
			l++; r++;
			//printf("input: %c %d %d\n",com,l,r);
			if(com=='F' || com=='E' || com=='I'){
				// printf("com: %c update l:%d r: %d\n",com,l,r);
				update(1,1,n,l,r,com);
			}else{
				// printf("\n\nmulai query\n");
				printf("Q%d: %d\n",jumlahHasil++,query(1,1,n,l,r));
			}
		}
		
	}
	return 0;
};