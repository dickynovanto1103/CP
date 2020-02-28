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
unordered_map<int,int> mapper;

int a[maxn], temp[maxn];
int bit[maxn];
int n;

int query(int idx) {
	int ans = 0;
	for(int i=idx;i>=1;i-=(i&-i)){
		ans += bit[i];
	}
	return ans;
}

void update(int idx, int val) {
	for(int i=idx;i<=n;i+=(i&-i)){
		bit[i] += val;
	}
}

int main(){
	int i,j;
	while(scanf("%d",&n), n) {

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			temp[i] = a[i];
		}
		sort(temp, temp+n);
		int cnt = 1;
		for(i=0;i<n;i++){
			if(mapper.find(temp[i]) == mapper.end()) {
				mapper[temp[i]] = cnt++;
			}
		}
		for(i=0;i<n;i++){
			update(mapper[a[i]], 1);
		}
		ll ans = 0;
		for(i=0;i<n;i++){
			int val = mapper[a[i]];
			int hasil = query(val-1);
			update(val, -1);
			ans += hasil;
		}
		printf("%lld\n",ans );
		mapper.clear();
	}
	return 0;
};