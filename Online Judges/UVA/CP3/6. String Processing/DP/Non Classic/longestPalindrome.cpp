#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

string kata;

int memo[1005][1005];

int solve(int l, int r){
	//if(l>r){return 0;}
	if(l==r){return 1;}
	if(l+1==r){
		if(kata[l]==kata[r]){return 2;}
		else{return 1;}
	}
	if(memo[l][r]!=-1){return memo[l][r];}
	if(kata[l]==kata[r]){return memo[l][r] = 2 + solve(l+1,r-1);}
	return memo[l][r] = max(solve(l,r-1),solve(l+1,r));
}

int main() {
	int tc;
	
	scanf("%d\n",&tc);
	//getc(stdin);
	//cin>>ws;
	while(tc--){
		getline(cin,kata);
		memset(memo,-1,sizeof memo);
		//printf("kata: "); cout<<kata<<endl;
		if(kata.length()==0){printf("0\n");}
		else{
			int ans = solve(0,kata.length()-1);
			printf("%d\n",ans);	
		}
		
	}
	return 0;
}

/*#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int memo[1005][1005];
char s[1005];

int longestPalin(int l, int r) {
	if (l == r)
		return 1;
	if (l + 1 == r) {
		if (s[l] == s[r])
			return 2;
		else
			return 1;
	}
	if (memo[l][r] != -1)
		return memo[l][r];

	if (s[l] == s[r])
		return memo[l][r] = 2 + longestPalin(l + 1, r - 1);
	else
		return memo[l][r] = max(longestPalin(l, r - 1), longestPalin(l + 1, r));
}

int main() {
	int tc;
	scanf("%d", &tc);
	getc(stdin);

	while (tc--) {
		gets(s);

		if (strlen(s) == 0) {
			printf("0\n");
			continue;
		}

		memset(memo, -1, sizeof(memo));
		int ans = longestPalin(0, strlen(s) - 1);

		printf("%d\n", ans);
	}

	return 0;
}*/