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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,p,i,j;
	scanf("%d %d",&n,&p);
	int ans = inf;
	int temp = n;
	if(p == 0){
		ans = __builtin_popcount(n);
	}else{
		for(i=1;i<=40;i++){
			n = temp;
			int bil = n - i*p;
			int banyak1 = __builtin_popcount(bil);
			printf("n: %d bil: %d i: %d p; %d banyak1: %d\n",n,bil,i,p,banyak1);
			if(n < 0){break;}
			int cnt1 = 0, cnt2 = 0;
			while(n){
				int bil = n - i*p;
				
			}
			if(banyak1 == i){
				ans = min(ans, banyak1);
			}
		}
	}
	if(ans == inf){ans = -1;}
	printf("%d\n",ans);
	return 0;
};