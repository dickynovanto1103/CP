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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e7 + 7;

bool vis[maxn];

int main(){
	ll p;
	ll n;
	scanf("%lld %lld",&p,&n);
	ll maksIterasi = min(2*p, n);
	memset(vis, false, sizeof vis);
	vis[0] = true;
	int pos = 0;
	int i,j;
	for(i=1;i<=maksIterasi;i++){
		pos += i;
		pos %= p;
		vis[pos] = true;
	}
	int cnt = 0;
	for(i=0;i<p;i++){
		if(vis[i]){cnt++;}
	}
	printf("%d\n",cnt);
	return 0;
};