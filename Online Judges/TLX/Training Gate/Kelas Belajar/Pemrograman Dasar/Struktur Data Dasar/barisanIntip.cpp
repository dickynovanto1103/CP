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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int bit[maxn];

void update(int idx, int val){
	for(int i=idx;i<maxn;i+=(i&-i)){
		bit[i] += val;
	}
}

int query(int idx) {
	int sum = 0;
	for(int i=idx;i>=1;i-=(i&-i)){
		sum += bit[i];
	}
	return sum;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int ans = 0;
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		update(bil, 1);
		ans += query(bil);
	}
	printf("%d\n",ans);
	return 0;
};