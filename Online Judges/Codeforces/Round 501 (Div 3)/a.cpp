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

const int maxn = 1e2 + 2;

int main(){
	int n,m,i,j;
	bool vis[maxn];
	scanf("%d %d",&n,&m);
	memset(vis, false, sizeof vis);
	for(i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		for(j=a;j<=b;j++){
			vis[j] = true;
		}
	}
	int cnt = 0;
	vi ans;
	for(i=1;i<=m;i++){
		if(!vis[i]){cnt++; ans.pb(i);}
	}
	printf("%d\n",cnt);
	for(i=0;i<cnt;i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
};