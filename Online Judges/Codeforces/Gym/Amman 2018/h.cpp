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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,n;
	int a[2010];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		int maks = -inf;
		for(i=1;i<=2*n;i++){
			maks = max(maks, a[i] + a[2*n - i + 1]);
		}
		printf("%d\n",maks);
	}
	return 0;
};