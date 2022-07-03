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
	int n;
	ll x;
	while(scanf("%d %lld",&n,&x) != EOF) {
		string s;
		cin>>s;
		string newS;
		int i,j;
		for(i=0;i<n;i++){
			if(s[i] == 'U') {
				if(newS.size() == 0) {
					x /= 2LL;
					continue;
				}
				newS.pop_back();
			}else{
				newS.pb(s[i]);
			}
		}

		for(i=0;i<newS.size();i++){
			char c = newS[i];
			if(c == 'L') {
				x *= 2LL;
			}else if (c == 'R'){
				x *= 2LL;
				x++;
			}else{
				// printf("s")
				assert(false);
			}
		}
		printf("%lld\n", x);
	}
	

	
	return 0;
};