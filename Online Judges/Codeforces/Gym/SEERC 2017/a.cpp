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

const ll mod = 1e9 + 7;

int h[30],n,k;
string concert, day;

ll dp[100010][301];

ll solve(int idxDay, int idxConcert){

	if(idxDay > n){return 0;}//kehabisan hari
	if(idxConcert > k){return 0;}
	if(idxDay == n && idxConcert == k){return 1;}
	if(idxConcert == k){return 1;} //concert udah ditonton semua

	if(dp[idxDay][idxConcert]!=-1){return dp[idxDay][idxConcert];}
	ll ans = 0;
	// printf("idxDay: %d idxConcert: %d concert: %c day: %c\n",idxDay, idxConcert, concert[idxConcert], day[idxDay]);
	if(concert[idxConcert] == day[idxDay]){
		//antara mau skip atau ambil
		int idxKar = concert[idxConcert] - 'A';
		// printf("h[%d]: %d\n",idxKar, h[idxKar]);
		ll ans1 = solve(idxDay+h[idxKar] + 1, idxConcert+1);
		ll ans2 = solve(idxDay+1, idxConcert);
		ans += ans1;
		ans%=mod;
		ans += ans2;
		ans%=mod;
		// printf("ans1: %lld ans2: %lld ans jd: %lld\n",ans1,ans2,ans);
	}else{
		ll ans2 = solve(idxDay+1, idxConcert);
		ans += ans2;
		ans%=mod;
		// printf("ans2: %lld ans jd: %lld\n",ans2,ans);
	}
	return dp[idxDay][idxConcert] = ans;
}

int main(){
	int i,j;
	scanf("%d %d",&k,&n);
	for(i=0;i<26;i++){
		scanf("%d",&h[i]);
	}
	cin>>concert>>day;

	memset(dp, -1, sizeof dp);
	ll ans = solve(0,0);
	printf("%lld\n",ans);
	return 0;
};