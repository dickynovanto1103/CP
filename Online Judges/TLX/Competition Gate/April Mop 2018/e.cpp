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

const ll mod = 1e9 + 7;

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int ans = (a%mod * b%mod) %mod;
	// ans = a*b;
	printf("%d\n",ans);
	return 0;
};