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
	int n,h,a,b,q;
	scanf("%d %d %d %d %d",&n,&h,&a,&b,&q);
	while(q--){
		int t1,f1,t2,f2;
		scanf("%d %d %d %d",&t1,&f1,&t2,&f2);
		ll ans = 0;
		if(t1 == t2){
			printf("%d\n",abs(f1-f2));
			continue;
		}
		int floorSekarang;
		if(f1 > b){
			ans += (f1-b);
			f1 = b;
		}else if(f1 < a){
			ans += (a-f1);
			f1 = a;
		}
		if(f2 > b){
			ans += (f2 - b);
			f2 = b;
		}else if(f2 < a){
			ans += (a-f2);
			f2 = a;
		}
		ans += abs(t1-t2) + abs(f1-f2);
		
		printf("%lld\n",ans);
	}
	return 0;
};