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

int a, b;

int f(int x) {
	return abs(a * x + b);
}

int main(){
	int k, x;
	scanf("%d %d %d %d",&a,&b,&k,&x);
	int ans = f(x);
	for(int i=1;i<k;i++){
		ans = f(ans);
	}

	printf("%d\n", ans);
	
	return 0;
};