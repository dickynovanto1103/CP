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
	string s,t;
	cin>>s>>t;
	if(s.size() > t.size()) {
		puts("No");
		return 0;
	}

	for(int i=0;i<s.size();i++){
		if(s[i] != t[i]) {
			puts("No");
			return 0;
		}
	}

	puts("Yes");
	
	return 0;
};