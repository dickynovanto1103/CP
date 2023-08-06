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
	double ans = (double)a / b;
	for(int i=1;i<=100000;i++){
		ans += pow(((double)(b-a)/b) * ((double)(d-c)/d), i) * ((double)a/b);
	}

	printf("%.9lf\n", ans);
	
	return 0;
};