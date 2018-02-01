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
	int n,m;
	scanf("%d %d",&n,&m);
	printf("%d ",min(n,m));
	int minim = min(n,m);
	n-=minim; m-=minim;
	// printf("n: %d m: %d\n",n,m);
	int ans = n/2 + m/2;
	printf("%d\n",ans);
	return 0;
};