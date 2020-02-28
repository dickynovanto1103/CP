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

int bit[3*maxn];

void update(int idx, int val, int n){
	for(int i=idx;i<=n;i+=(i&-i)){
		bit[i] = max(bit[i],val);
	}
}

int query(int idx){
	int ans = 0;
	for(int i=idx;i>=1;i-=(i&-i)){
		ans = max(ans, bit[i]);
	}
	return ans;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	set<int> s;
	set<int>::iterator it;
	int a[maxn], b[maxn];
	int pref[3*maxn];
	memset(pref, 0, sizeof pref);
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
		s.insert(a[i]-b[i]); s.insert(a[i]); s.insert(a[i]+b[i]);
	}
	map<int,int> mapper;
	int cnt = 1;
	
	for(it=s.begin();it!=s.end();it++){
		int bil = *it;
		if(binary_search(a,a+n, bil)){
			pref[cnt] = 1;
		}
		pref[cnt] += pref[cnt-1];
		mapper[bil] = cnt++;
		
	}

	int dp[3*maxn];
	memset(dp, 0, sizeof dp);
	int ans = 0;
	for(i=0;i<n;i++){

		int idxTambah = mapper[a[i] + b[i]];
		int idxSekarang = mapper[a[i]];
		int banyakKanan = pref[idxTambah] - pref[idxSekarang];
		if(!banyakKanan){
			dp[idxTambah] = max(dp[idxTambah], 1 + query(idxSekarang-1));	
			update(idxTambah, dp[idxTambah], cnt);
		}
		
		dp[idxSekarang] = max(dp[idxSekarang], query(idxSekarang-1));
		int idxBel = mapper[a[i] - b[i]];
		int banyakKiri = pref[idxSekarang-1]-pref[idxBel-1];
		if(!banyakKiri){
			dp[idxSekarang] = max(dp[idxSekarang], 1 + query(idxBel - 1));	
		}
		update(idxSekarang, dp[idxSekarang],cnt);
		
		
		ans = max(ans, dp[idxTambah]);
		ans = max(ans, dp[idxSekarang]);
		ans = max(ans, dp[idxBel]);
	}
	printf("%d\n",ans);

	return 0;
};