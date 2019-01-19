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
	int tc;
	ll n,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld",&n,&k);

		if(n <= k){printf("YES\n");}
		else if(n%2 == 0 && k == n/2){printf("NO\n");}
		else if(k > n/4){printf("YES\n");}
		else{
			if(n%k != 0){printf("YES\n"); continue;}
			if(n%2 == 1){printf("YES\n"); continue;}
			int bagi2 = n/2;
			if(bagi2 % k != 0){printf("YES\n");}
			else{
				int hasil = bagi2 / k;
				if(hasil % 2 == 1){printf("NO\n");}
				else{printf("YES\n");}
			}
		}
		
	}
	return 0;
};