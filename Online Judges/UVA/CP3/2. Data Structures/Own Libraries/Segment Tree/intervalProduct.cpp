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

const int maxn = 1e5 + 5;
int stNegatif[4*maxn], stNol[4*maxn];
char ans[4*maxn];
int a[maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

void build(int node, int l, int r){
	if(l==r){
		if(a[l]==0){stNol[node] = 1; ans[node]='0';}
		else if(a[l]<0){stNegatif[node] = 1; ans[node]='-';}
		else{ans[node] = '+';}
	}else{
		int mid = (l+r)/2;
		build(left(node),l,mid);
		build(right(node),mid+1,r);

		stNol[node] = stNol[left(node)] + stNol[right(node)];
		stNegatif[node] = stNegatif[left(node)] + stNegatif[right(node)];
		if(stNol[node]>0){ans[node] = '0'; return;}

		if(stNegatif[node]%2==0){ans[node] = '+';}
		else{ans[node] = '-';}
	}
}

char query(int node, int l, int r, int i, int j){
	if(l>j || r<i){return '?';}
	if(i<=l && r<=j){return ans[node];}
	int mid = (l+r)/2;
	char ans1 = query(left(node),l,mid,i,j);
	char ans2 = query(right(node),mid+1,r,i,j);
	if(ans1=='?'){return ans2;}
	if(ans2=='?'){return ans1;}

	char ans;
	if(ans1=='-' && ans2=='-'){ans = '+';}
	else if(ans1=='-' && ans2=='+'){ans = '-';}
	else if(ans1=='+' && ans2=='-'){ans = '-';}
	else if(ans1=='+' && ans2=='+'){ans = '+';}
	else if(ans1=='0' || ans2=='0'){ans = '0';}

	return ans;
}

void update(int node, int l, int r, int idx, int val){
	if(l>idx || r<idx){return;}
	if(l==r && l==idx){
		if(a[idx]==0){stNol[node]--;}
		else if(a[idx]<0){stNegatif[node]--;}

		a[idx] = val;
		if(a[idx]==0){stNol[node]++; ans[node]='0';}
		else if(a[idx]<0){stNegatif[node]++; ans[node]='-';}
		else{ans[node]='+';}

		return;
	}

	int mid = (l+r)/2;
	update(left(node),l,mid,idx,val);
	update(right(node),mid+1,r,idx,val);

	stNol[node] = stNol[left(node)] + stNol[right(node)];
	stNegatif[node] = stNegatif[left(node)] + stNegatif[right(node)];
	if(stNol[node]>0){ans[node] = '0'; return;}

	if(stNegatif[node]%2==0){ans[node] = '+';}
	else{ans[node] = '-';}
}

int main(){
	int n,k,i,j;
	
	while(scanf("%d %d",&n,&k)!=EOF){
		memset(stNegatif,0,sizeof stNegatif); 
		memset(stNol,0,sizeof stNol); 
		for(i=1;i<=n;i++){scanf("%d",&a[i]);}
		build(1,1,n);
		while(k--){
			char com;
			int l, r;
			scanf("\n%c %d %d",&com,&l,&r);
			if(com=='C'){
				update(1,1,n,l,r);
			}else{
				printf("%c",query(1,1,n,l,r));
			}
		}
		printf("\n");
	}
	return 0;
};