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

int n,t;
int a[3030], b[3030];

int dp[3001][3001];

int solve(int idx, int time) {
	if(idx == n){return 0;}
	if(time >= t){return 0;}
	if(dp[idx][time] != -1){return dp[idx][time];}
	return dp[idx][time] = max(solve(idx+1, time), b[idx] + solve(idx+1, time+a[idx]));
}

int main(){
	memset(dp, -1, sizeof dp);
	scanf("%d %d",&n,&t);
	int i,j;
	ii temp[3030];
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
		temp[i].first = a[i], temp[i].second = b[i];
	}
	sort(temp, temp+n);
	for(i=0;i<n;i++){
		a[i] = temp[i].first, b[i] = temp[i].second;
	}
	printf("%d\n",solve(0,0));

	return 0;
};