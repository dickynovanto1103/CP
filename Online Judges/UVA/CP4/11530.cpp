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

map<char, int> times = {
	{'a', 1},
	{'b', 2},
	{'c', 3},
	{'d', 1},
	{'e', 2},
	{'f', 3},
	{'g', 1},
	{'h', 2},
	{'i', 3},
	{'j', 1},
	{'k', 2},
	{'l', 3},
	{'m', 1},
	{'n', 2},
	{'o', 3},
	{'p', 1},
	{'q', 2},
	{'r', 3},
	{'s', 4},
	{'t', 1},
	{'u', 2},
	{'v', 3},
	{'w', 1},
	{'x', 2},
	{'y', 3},
	{'z', 4},
	{' ', 1},
};

void solve(){
	string s;
	getline(cin, s);
	int ans = 0;
	for(char c: s) {
		ans += times[c];
	}
	printf("%d\n", ans);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(getchar() != '\n');
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		solve();
	}

	return 0;
};

