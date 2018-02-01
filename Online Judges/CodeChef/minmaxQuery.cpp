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
int a[maxn];
int stMax[4*maxn], stMin[4*maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

void build(int node, int l, int r){
	if(l==r){
		stMax[node] = a[l];
		stMin[node] = a[l];
		return;
	}

	int mid = (l+r)/2;
	build(left(node),l,mid);
	build(right(node),mid+1,r);

	stMax[node] = max(stMax[left(node)], stMax[right(node)]);
	stMin[node] = min(stMin[left(node)], stMin[right(node)]);
}

ii query(int node, int l, int r, int i, int j){
	if(i>r || j<l){return ii(-1,-1);}
	if(i<=l && r<=j){return ii(stMin[node], stMax[node]);}

	int mid = (l+r)/2;
	ii ans1 = query(left(node),l,mid,i,j);
	ii ans2 = query(right(node),mid+1,r,i,j);

	if(ans1==ii(-1,-1)){return ans2;}
	if(ans2==ii(-1,-1)){return ans1;}
	int max1 = max(ans1.second, ans2.second);
	int min1 = min(ans1.first, ans2.first);
	ii ans = ii(min1,max1);

	return ans;
}

int main(){
	int n,q,i,j;

	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++){scanf("%d",&a[i]);}
	build(1,1,n);
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		l++;r++;
		ii ans = query(1,1,n,l,r);
		printf("%d\n",ans.second-ans.first);
	}
	return 0;
};