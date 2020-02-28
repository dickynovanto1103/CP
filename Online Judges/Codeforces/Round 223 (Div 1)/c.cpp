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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e6 + 6;

ii st[4*maxn];
int minim[4*maxn];
int ending[maxn];
int sum[maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

void build(int node, int l, int r) {
	if(l == r) {
		st[node] = ii(ending[l], sum[l]);
		minim[node] = (ending[l] == -1 ? inf: ending[l]);
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);
		int maksEnd = max(st[left(node)].first, st[right(node)].first);
		int jumlah = st[left(node)].second + st[right(node)].second;
		st[node] = ii(maksEnd, jumlah);
		minim[node] = min(minim[left(node)], minim[right(node)]);
	}
}

int query(int node, int l, int r, int i, int j) {
	int maks = st[node].first;
	int mini = minim[node];
	if(maks == -1){return 0;}
	if(r < i || l > j){return 0;}
	if(i <= l && r <= j) {
		int maksEnd = st[node].first;
		if(minim[node] > j){return 0;}

		if(maksEnd > j){
			if(l == r){return 0;}
			int mid = (l+r)/2;
			int ans1 = query(left(node), l, mid, i, j);
			int ans2 = query(right(node), mid+1, r, i, j);
			return ans1 + ans2;
		}else{
			return st[node].second;
		}
	}
	int mid = (l+r)/2;
	int ans1 = query(left(node), l, mid, i, j);
	int ans2 = query(right(node), mid+1, r, i ,j);
	return ans1 + ans2;

}

int main(){
	string kata;
	int i,j;
	cin>>kata;
	int n = kata.length();
	memset(sum, 0, sizeof sum);
	memset(ending, -1, sizeof ending);
	stack<int> s;
	for(i=0;i<n;i++){
		if(kata[i] == '(') {
			s.push(i+1);
		}else{
			if(s.empty()){continue;}
			int front = s.top(); s.pop();
			ending[front] = i+1;
			sum[front] = 2;
		}
	}
	build(1,1,n);

	int q;
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",query(1,1,n,a,b));
	}

	return 0;
};