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

bool isBeautiful(string s) {
	for(int i=0;i<s.size() - 1;i++){
		if(s[i] == s[i+1]) return false;
	}

	return true;
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n,m;
		scanf("%d %d",&n,&m);
		string s, t;
		cin>>s>>t;

		bool found = false;
		if(isBeautiful(s) && isBeautiful(t))  {
			found = true;
		}
		//coba dari s ke t
		while(s.size() > 1) {
			char c = s.back(); s.pop_back();
			t += c;

			if(isBeautiful(s) && isBeautiful(t)) {
				found = true;
				break;
			}
		}
		//terus dr t ke s

		while(t.size() > 1) {
			char c = t.back(); t.pop_back();
			s += c;
			if(isBeautiful(s) && isBeautiful(t)) {
				found = true;
				break;
			}
		}

		if(found){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	
	return 0;
};