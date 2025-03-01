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

int squareLength(int n) {
	for(int i=1;i*i<=n;i++){
		if(i * i == n) {
			return i;
		}
	}

	return -1;
}

bool isEdge(int i, int j, int r) {
	return (i == 0 || i == (r-1) || j == 0 || j == (r-1));
}

bool isBeautiful(vector<string> v, int r) {
	for(int i=0;i<r;i++){
		for(int j=0;j<r;j++){
			if(isEdge(i, j, r)) {
				if(v[i][j] == '0') {
					return false;
				}
			}else{
				// printf("i: %d j: %d, val: %v")
				if(v[i][j] == '1') {
					return false;
				}
			}
		}
	}

	return true;
}

void solve(){
	int n;
	scanf("%d",&n);
	string s;
	cin>>s;

	int r = squareLength(n);
	if(r == -1) {puts("No"); return;}

	vector<string> v;
	int idx = 0;
	for(int i=0;i<r;i++){
		string newS;
		for(int j=0;j<r;j++){
			newS += s[idx++];
		}
		v.pb(newS);
	}

	if(isBeautiful(v, r)) {
		puts("Yes");
	}else{
		puts("No");
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