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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e3 + 3;
int arr[10000010];
int main(){
	int a,b,m,i,j;
	scanf("%d %d %d",&a,&b,&m);
	bool vis[maxn];
	memset(vis, false, sizeof vis);
	vis[a] = vis[b] = true;
	
	arr[0] = a; arr[1] = b;
	for(i=2;i<10000000;i++){
		arr[i] = arr[i-1] + arr[i-2];
		arr[i]%=m;
		vis[arr[i]] = true;
	}
	// printf("cnt: %d\n",cnt);
	int cnt = 0;
	for(i=0;i<m;i++){
		if(vis[i]){cnt++;}
	}
	printf("%d\n",cnt);
	return 0;
};