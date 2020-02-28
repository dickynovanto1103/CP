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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int st[4*maxn][26];
int ans[4*maxn];
string s;

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

int combine(int* hasil, int* a, int* b, int node) {
	int cnt = 0;
	for(int i=0;i<26;i++){
		hasil[i] = a[i] + b[i];
		if(hasil[i]){cnt++;}
	}
	return ans[node] = cnt;
}

void build(int node, int l, int r) {
	if(l == r) {
		st[node][s[l-1]-'a'] = 1;
		ans[node] = 1;
	}else{
		int mid = (l+r)/2;
		build(left(node), l, mid);
		build(right(node), mid+1, r);
		combine(st[node], st[left(node)], st[right(node)], node);
	}
}

void update(int node, int l, int r, int idx, char c, int val) {
	if(l > idx || r < idx){return;}
	if(l == r && l == idx){
		st[node][c-'a'] += val;
		ans[node] += val;
		// printf("update c: %c idx: %d ans[%d] jd: %d st jd: %d\n",c,idx,node,ans[node], st[node][c-'a']);
		return;
	}
	int mid = (l+r)/2;
	update(left(node), l, mid, idx, c, val);
	update(right(node), mid+1, r, idx, c, val);
	combine(st[node], st[left(node)], st[right(node)], node);
	// printf("ans[%d:%d]: %d\n",l,r,ans[node]);
}

vector<int> query(int node, int l, int r, int i, int j) {
	if(r < i || l > j){
		vi a;
		for(int tt=0;tt<26;tt++){a.pb(0);}
		return a;
	}
	if(i <= l && r <= j){
		vi a;
		for(int tt=0;tt<26;tt++){
			a.pb(st[node][tt]);
		}
		return a;
	}
	
	int mid = (l+r)/2;
	vi ans1 = query(left(node), l, mid, i, j);
	vi ans2 = query(right(node), mid+1, r, i, j);
	vi a(26);
	for(int tt=0;tt<26;tt++){
		a[tt] = ans1[tt] + ans2[tt];
	}
	ans1.clear(); ans2.clear();
	return a;
}

int main(){
	int q;
	
	int n,i,j;
	cin>>s;
	n = s.length();
	build(1,1,n);
	scanf("%d",&q);
	while(q--){
		int type;
		scanf("%d",&type);
		if(type == 1) {
			int idx;
			char c;
			cin>>idx>>c;
			char awal = s[idx-1];
			update(1,1,n,idx, awal, -1);
			s[idx-1] = c;
			// printf("idx: %d c: %c\n",idx,c);
			update(1,1,n,idx,c, 1);
		}else{
			int l,r;
			scanf("%d %d",&l,&r);
			vi ans = query(1,1,n,l,r);
			int jawab = 0;
			for(int bil: ans){
				if(bil){
					jawab++;
				}
			}
			printf("%d\n",jawab);
		}
	}
	return 0;
};