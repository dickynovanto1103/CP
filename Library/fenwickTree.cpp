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

const int maxn = 10000;
int tree[maxn], n;

void add(int idx, int val) {
	while(idx<=n) {
		tree[idx]+=val;
		idx+=(idx & -idx);
	}
}

int sum(int idx) {
	int ans = 0;
	while(idx>0) {
		ans+=tree[idx];
		idx -= (idx & -idx);
	}
	return ans;
}

int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		int bil;
		scanf("%d",&bil);
		add(i,bil);

	}

	int q;
	scanf("%d",&q);
	while(q--){
		int idx1, idx2;
		scanf("%d %d",&idx1,&idx2);
		int ans = sum(idx2) - sum(idx1-1);
		printf("jumlah antara %d dan %d adalah %d\n",idx1, idx2, ans);
	}
	return 0;
};