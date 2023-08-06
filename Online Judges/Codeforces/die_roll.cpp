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
	int a, b;
	scanf("%d %d",&a,&b);
	int maks = max(a, b);
	int cnt = 0;
	for(int i=maks;i<=6;i++){
		cnt++;
	}

	int denominator = 6;
	int gcd = __gcd(cnt, denominator);
	cnt /= gcd;
	denominator /= gcd;
	printf("%d/%d\n", cnt, denominator);
	
	return 0;
};