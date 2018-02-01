#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,a,b,maksx=-1,maksy=-1,minx=1000000,miny=1000000;
	scanf("%d",&n);
	for(int i=0;i<n;i++){

		scanf("%d %d",&a,&b);
		maksx = max(maksx,a);
		maksy = max(maksy,b);
		minx = min(minx,a);
		miny = min(miny,b);
	}
	printf("%d\n",abs(maksx-minx) * abs(maksy - miny));
	return 0;
}