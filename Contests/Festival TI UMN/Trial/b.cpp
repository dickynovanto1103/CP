#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,tt;
	int a,b;
	scanf("%d",&tc);
	for(tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		int mod;
		scanf("%d %d %d",&a,&b,&mod);		
		
		printf("%d\n",((b / mod) - (a / mod)) + (a % mod == 0 ? 1 : 0));
	}
	return 0;
}