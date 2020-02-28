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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	scanf("%d",&n);
	ll a[maxn], b[maxn];
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%lld",&b[i]);
	}
	ll minim = 1e17;
	for(i=1;i<n-1;i++){
		minim = min(minim, b[0]*a[i] + b[i]*a[n-1]);
	}
	minim = min(minim, b[0]*a[n-1]);
	printf("%lld\n",minim);
	return 0;
};