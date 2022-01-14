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
		int kali = a * b;
		int ans = kali / 3;
		int x = a % 3;
		int y = b % 3;
		if(x > y) {swap(x,y);}
		if(x == 1 && y == 1) {
			ans++;
		}else if(x == 1 && y == 2){
			ans++;
		}else if(x == 2 && y == 2){
			ans++;
		}
		printf("%d\n", ans);
	}
	
	return 0;
};