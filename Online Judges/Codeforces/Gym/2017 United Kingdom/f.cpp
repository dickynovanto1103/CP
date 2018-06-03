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

	int n,m;
	double dp[405][405];
	double gagal[405][405];
	double sukses[405][405];

	double solve(int jumlahHead, int k){
		if(dp[jumlahHead][k] < 0){
			if(k==0)
				dp[jumlahHead][k] = jumlahHead;
			else{
				if(jumlahHead < n)
					dp[jumlahHead][k] = 0.5*solve(jumlahHead+1, k-1) + 0.5 * solve(jumlahHead,k-1);
				else
					dp[jumlahHead][k] = 0.5 * solve(jumlahHead,k-1);
					
				if(jumlahHead > 0){
					dp[jumlahHead][k] = max(dp[jumlahHead][k], 0.5*solve(jumlahHead-1, k-1) + 0.5*solve(jumlahHead, k-1));
				}
			}
		}
		return dp[jumlahHead][k];
	}

	int main(){
		for(int i=0;i<=400;i++){
			for(int j=0;j<=400;j++){
				dp[i][j] = -1;
			}
		}
		scanf("%d %d", &n, &m);
		printf("%.8lf\n", solve(0, m));
		return 0;
	};