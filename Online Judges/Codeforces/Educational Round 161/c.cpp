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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 100010;
int a[maxn];
int pref[maxn], suff[maxn];

void resetPrefSuff(int n) {
	for(int i=0;i<=n;i++){
		pref[i] = suff[i] = 0;
	}
}

void buildPrefSuff(int n) {
	if(n == 1) {
		return;
	}
	pref[1] = a[1] - a[0] - 1;
	suff[n-2] = a[n-1] - a[n-2] - 1;
	for(int i=1;i<n-1;i++){
		int diff1 = a[i] - a[i-1];
		int diff2 = a[i+1] - a[i];
		if(diff2 < diff1) {
			pref[i+1] = diff2 - 1;
		}
	}

	for(int i=1;i<n;i++){
		pref[i] += pref[i-1];
	}

	for(int i=n-2;i>=1;i--){
		int diff1 = a[i] - a[i-1];
		int diff2 = a[i+1] - a[i];
		if(diff1 < diff2) {
			suff[i-1] = diff1 - 1;
		}
	}

	for(int i=n-1;i>=0;i--){
		suff[i] += suff[i+1];
	}
}

int getPengurangan(int x, int y, int n) {
	if(x == y) {
		return 0;
	}
	if(x < y) {
		return pref[y] - pref[x];
	}else{
		return suff[y] - suff[x];
	}
}

void solve(){
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	resetPrefSuff(n);
	buildPrefSuff(n);

	scanf("%d",&m);
	while(m--){
		int x, y;
		scanf("%d %d",&x,&y);
		x--; y--;

		int dist = abs(a[x] - a[y]);
		dist -= getPengurangan(x, y, n);
		printf("%d\n", dist);
	}
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};