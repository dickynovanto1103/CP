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

const int maxn = 1e4 + 4;
int bit[maxn];
int n;

void update(int idx, int val) {
	for(int i=idx;i<=n;i+=(i&-i)) {
		bit[i]+=val;
	}
}

int query(int idx) {
	int sum = 0;
	for(int i=idx;i>=1;i-=(i&-i)) {
		sum+=bit[i];
	}
	return sum;
}


int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		memset(bit,0,sizeof bit);
		int u,q;
		scanf("%d %d",&n,&u);
		
		for(i=0;i<u;i++){
			int l,r,val;
			scanf("%d %d %d",&l,&r,&val);
			l++; r++;
			update(l, val);
			update(r+1,-val);
		}

		scanf("%d",&q);
		while(q--){
			int idx;
			scanf("%d",&idx);
			idx++;
			printf("%d\n",query(idx));
		}
	}
	return 0;
};