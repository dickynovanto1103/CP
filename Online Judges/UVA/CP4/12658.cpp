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
	vector<string> vs(6);

	int n;
	scanf("%d",&n);
	for(int i=0;i<6;i++){
		cin>>vs[i];
	}
	string res = "";

	int colStart = 0;
	for(int i=0;i<n;i++){
		if(vs[1][colStart+1] == '*') {
			res += "1";
		}else if(vs[3][colStart] == '*') {
			res += "2";
		}else if(vs[3][colStart+2] == '*') {
			res += "3";
		}
		colStart += 4;
	}

	cout<<res<<endl;

}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};