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

bool isEven(char c) {
	return (c - '0') % 2 == 0;
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		string s;
		cin>>s;
		n = s.size();
		if(isEven(s[n-1])) {
			puts("0");
			continue;
		}
		if(isEven(s[0])) {
			puts("1");
			continue;
		}

		bool found = false;
		for(i=0;i<n;i++){
			if(isEven(s[i])){
				found = true;
				break;
			}
		}

		found ? puts("2") : puts("-1");
	}
	
	return 0;
};