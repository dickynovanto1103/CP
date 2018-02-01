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
	int n,i,a[1010];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	sort(a,a+n);
	int maks = -inf;
	for(i=0;i<n;i++){
		//printf("a[%d]: %d\n",i,a[i]);
		int bil = a[i]*(n-i);
		//printf("bil: %d\n",bil);
		maks = max(maks,bil);
	}
	printf("%d\n",maks);
	return 0;
}