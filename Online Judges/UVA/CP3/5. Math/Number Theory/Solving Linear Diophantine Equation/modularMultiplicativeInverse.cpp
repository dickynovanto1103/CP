#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int gcdExtended(int a, int b, int *x, int *y) {
	if(a==0){
		*x = 0; *y = 1;
		return b;
	}
	int x1,y1;
	int gcd = gcdExtended(b%a,a,&x1,&y1);
	*x = y1 - (b/a)*x1;
	*y = x1;
	return gcd;
}

int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int a,m;
		scanf("%d %d",&a,&m);
		int x,y;
		int ans = gcdExtended(a,m,&x,&y);
		if(ans!=1){printf("-1\n");}
		else{
			int res = (x%m + m)%m; //in case negatif
			//printf("x: %d y: %d\n",x,y);
			printf("%d\n",res);
		}	
	}
	
	return 0;
}