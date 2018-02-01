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
	int n,i,bil;
	scanf("%d",&n);
	int maks = -inf;
	while(n--){
		scanf("%d",&bil);
		maks = max(maks,bil);
	}
	printf("%d\n",maks);
	return 0;
}