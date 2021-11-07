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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,x,y;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&x,&y);
		if(x == y) {printf("%d\n", x);}
		else if(x > y){//n % x == y % n, bs assign n = (x + y) sehingga (x + y) % x == y == y % (x + y) == y
			printf("%d\n", x + y);
		}else{
			//let n % x == r, sehingga x * a + r = n
			// so y % n == r, sehingga n * b + r = y
			//substitusi n, (xa + r) * b + r = y, 
			// xab + br + r = y
			//xab + r (b+1) = y
			//r = (y - xab) / (b+1)
			//since x and y is event, then if we go with b = 1, then (y - xa) / 2 will be able to result in integer
			// y - xa = y % x, r = y % x / 2
			//another observation, if x and y is even, then x % y will always result in even num, so does y % x
			int r = (y % x) / 2;
			int n = y - r;
			printf("%d\n", n);
		}
	}
	
	return 0;
};