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

HqwA5e6$_yTP9D$

void solve(){
	int n;
	scanf("%d",&n);
	int a[101], b[101];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}

	int ans = 0;
	for(int tambah = 0;tambah <= n; tambah++){
		bool ok = true;
		for(int i=0;i<n;i++){
			if(i + tambah < n && a[i] > b[i+tambah]) {
				ok = false;
				break;
			}
		}
		if(ok){
			ans = tambah;
			break;
		}
	}

	printf("%d\n", ans);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};

