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

const int maxn = 100010;
ll a[maxn],b[maxn];

int main(){
	int n,i;
	scanf("%d",&n);
	ll total = 0;
	for(i=0;i<n;i++){scanf("%lld",&a[i]); total+=a[i];}
	for(i=0;i<n;i++){scanf("%lld",&b[i]);}
	sort(b,b+n);
	ll capacityCan = b[n-1] + b[n-2];
	if(capacityCan>=total){printf("YES\n");}
	else{printf("NO\n");}
	return 0;
};