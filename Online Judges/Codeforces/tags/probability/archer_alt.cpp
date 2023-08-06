//https://codeforces.com/problemset/problem/312/B
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
	int a, b, c, d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	//we will use geometric progression formula = first num / (1 - r)
	// first num = a / b
	// ratio = (1 - a / b) * (1 - c / d);
	double firstNum = (double) a / b;
	double ratio = (1.0 - (double)a/b) * (1.0 - (double)c/d);

	printf("%.9lf\n", firstNum / (1.0 - ratio));
	
	return 0;
};