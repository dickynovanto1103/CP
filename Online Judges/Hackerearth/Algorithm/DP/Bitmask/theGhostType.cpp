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

int n;
ll dp[21][1<<20];

ll solve(int idx, int bit){
	if(bit == ((1<<n) - 1)){return 1;}
	if(dp[idx][bit] != -1){return dp[idx][bit];}

	ll ans = 0;
	for(int i=0;i<n;i++){
		if(!((1<<i) & bit)){
			for(int j=0;j<n;j++){
				if((1<<j) | bit){
					if((i+1) & (j+1) == (i+1)){
						ans += solve(idx+1, )
					}
				}
				
			}
			
		}
	}
}

int main(){
	int i,j;
	scanf("%d",&n);
	ll ans = 0;
	for(i=1;i<=n;i++){
		ans+=solve(0, 1<<i);
	}
	return 0;
};