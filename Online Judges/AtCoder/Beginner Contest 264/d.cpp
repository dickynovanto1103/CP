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

int main(){
	string res = "atcoder";
	string s;
	int n = res.size();
	while(cin>>s) {

		int ans = 0;
		for(int i=0;i<n;i++){
			char expected = res[i];
			int idx = -1;
			for(int j=i;j<n;j++){
				//where is char expected?
				if(expected == s[j]) {
					idx = j;
					break;
				}
			}

			assert(idx >= i);
			for(int j=idx;j>i;j--) {
				ans++;
				swap(s[j], s[j-1]);
			}


		}

		printf("%d\n", ans);
	}
	
	return 0;
};