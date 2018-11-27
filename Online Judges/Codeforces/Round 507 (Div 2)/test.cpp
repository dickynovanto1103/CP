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

const int maxn = 25;

int main(){
	int n,i,j,a[2];
	int arr[maxn];
	scanf("%d %d %d",&n,&a[0],&a[1]);
	for(i=1;i<=n;i++){scanf("%d",&arr[i]);}
	int minim = min(a[0],a[1]);
	int ans = 0;
	// printf("minim: %d\n",minim);
	for(i=1;i<=n/2;i++){
		int j = n+1 - i;
		if(arr[i] == 2 && arr[j] == 2){ans += 2*minim;}
	}
	if(n%2 == 1 && arr[n/2+1] == 2){ans += minim;}
	printf("%d\n",ans);
	return 0;
};