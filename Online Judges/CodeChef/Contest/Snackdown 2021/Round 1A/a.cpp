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
	int tc,a,b;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&a,&b);
		if(a == b){puts("0"); continue;}
		if(a > b) {
			printf("%d\n", a-b);
		}else{
			int selisih = b - a;
			int step2 = (selisih + 1) / 2;
			int posNow = a + step2 *2;
			posNow > b ? printf("%d\n", step2 + 1) : printf("%d\n", step2);
		}
	}
	
	return 0;
};