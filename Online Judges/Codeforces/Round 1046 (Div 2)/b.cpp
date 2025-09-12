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

void solve(){
	int n,k;
	scanf("%d %d",&n,&k);
	string s;
	cin>>s;
	//find if there is any consecutive k with 1;
	int cnt = 0;
	for(int i=0;i<k;i++){
		if(s[i] == '1') {
			cnt++;
		}
	}
	int l = 0, r = k-1;
	while(cnt < k && r < (n-1)) {
		if(s[l++] == '1') {
			cnt--;
		}
		if(s[++r] == '1') {
			cnt++;
		}
	}
	if(cnt >= k) {
		puts("NO");
		return;
	}
	int big = n, small = 1;
	puts("YES");
	for(int i=0;i<n;i++){
		if(s[i] == '1'){
			printf("%d ", small++);
		}else{
			printf("%d ", big--);
		}
	}
	puts("");
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};