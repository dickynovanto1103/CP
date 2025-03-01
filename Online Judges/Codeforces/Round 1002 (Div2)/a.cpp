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

int a[51], b[51];

void solve(){
	int n;
	scanf("%d",&n);
	set<int> sa, sb;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		sa.insert(a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
		sb.insert(b[i]);
	}

	int uniqueNumB = sb.size();
	int uniqueNumA = sa.size();

	if(uniqueNumB == 1) {
		if (uniqueNumA <= 2) {
			puts("NO");
		}else {
			puts("YES");
		}
	} else {
		if(uniqueNumA == 1) {
			puts("NO");
		}else{
			puts("YES");
		}
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