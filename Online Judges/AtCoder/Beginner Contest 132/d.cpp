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

const ll mod = 1e9 + 7;

ll dp[2001][2001];

ll solve(int keluar, int step) {
	// if(keluar < )
}

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	// dp[i][j] = banyak cara supaya ada i buah bola biru dan banyak consecutive = j
	for(i=1;i<=n;i++) {

		for(j=1;j<=n;j++){
			dp[1][j] = 1;
		}
		for(j=2;j<=n;j++){
			dp[i][j]
		}
	}
	return 0;
};