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

int main() {
	int tc,i,x,y;
	int x1,y1,x2,y2;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		int n;
		scanf("%d",&n);
		x1 = inf; y1 = inf; x2 = -inf; y2 = -inf;
		while(n--){scanf("%d %d",&x,&y); x1 = min(x1,x); y1 = min(y1,y); x2 = max(x2,x); y2 = max(y2,y);}
		int bil = max(x2-x1,y2-y1);
		printf("%d\n",bil*bil);
	}
	return 0;
}