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
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		n--;
		ll sum1 = 0, sum2 = 0, sumTengah = 0, ans = 0;
		if(n<=2){sum1 = 0; printf("%lld\n",sum1); continue;}
		ll banyak3 = (n/3LL);
		sum1 = (3LL + (3LL*(n/3LL)))*banyak3 / 2LL;
		if(n<=4){sum2 = 0; printf("%lld\n",sum1); continue;}
		ll banyak5 = n/5LL;
		sum2 = (5LL + (5LL*(n/5LL)))*banyak5 / 2LL;


		// printf("sum1: %lld sum2: %lld banyak3: %lld banyak5: %lld\n",sum1,sum2,banyak3, banyak5);
		if(n<=14){sumTengah = 0; printf("%lld\n",sum1+sum2); continue;}
		ll banyakTengah = n/15LL;
		sumTengah = (15LL + (15LL * (n/15LL)))*banyakTengah / 2LL;
		printf("%lld\n",sum1+sum2 - sumTengah);

		
	}
	return 0;
};