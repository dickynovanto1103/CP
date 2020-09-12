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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e2 + 2;

struct pas {
	int w, h,v;
};

pas a[maxn];

int dp[maxn][2001];

int n;

//ternyata ordernya ngaruh
int solve(int idx, int waktu) {
	if(idx == n){return 0;}
	if(a[idx].h < (a[idx].w + waktu)){return solve(idx+1, waktu);}
	
	if(dp[idx][waktu] != -1){return dp[idx][waktu];}
	return dp[idx][waktu] = max(solve(idx+1, waktu), a[idx].v + solve(idx+1, waktu + a[idx].w));
}

bool cmp(pas a, pas b){
	return (a.h - a.w) < (b.h - b.w);
}

int main(){
	int i,j;
	scanf("%d",&n);
	memset(dp, -1, sizeof dp);
	for(i=0;i<n;i++){
		scanf("%d %d %d",&a[i].w,&a[i].h,&a[i].v);
	}
	sort(a, a+n, cmp);
	int ans = solve(0, 0);
	printf("%d\n",ans);
	
	return 0;
};