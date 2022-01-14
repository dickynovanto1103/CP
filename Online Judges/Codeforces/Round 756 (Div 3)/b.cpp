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
	int tc,i,j,a,b;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&a,&b);
		if(a > b){swap(a,b);}
		if((ll)a*3 <= (ll)b) {
			printf("%d\n",a);
			continue;
		}
		int x = (b - a) / 2;
		int sisa1 = a - x;
		int sisa2 = b - 3*x;
		printf("%d\n", x + min(sisa1 / 2, sisa2 / 2));
	}
	
	return 0;
};