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
	int h;
	string path;
	cin>>h>>path;
	ll num = (1LL<<(h+1)) - 1;
	char cur = '\0';
	int kurang = 0;
	for(int i=0;i<path.size();i++){
		char c = path[i];
		if(cur == '\0') {
			if (c == 'L') {
				kurang = 1;	
			}else{
				kurang = 2;
			}
		}else if(cur == 'L') {
			if(c == 'L') {
				kurang *= 2;
			}else{
				kurang = kurang * 2 + 1;
			}
		}else{
			if(c == 'L') {
				kurang = kurang * 2 - 1;
			}else{
				kurang *= 2;
			}
		}
		cur = c;
		num -= kurang;
	}

	printf("%lld\n", num);
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};