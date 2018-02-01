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

const int maxn = 1e5 +5;

int main(){
	int n,i,j,k;
	int a[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}

	int prefmax[maxn], suffmin[maxn];
	prefmax[0] = a[0]; suffmin[n-1] = a[n-1];
	for(i=1;i<n;i++){
		prefmax[i] = max(prefmax[i-1],a[i]);
	}
	for(i=n-2;i>=0;i--){
		suffmin[i] = min(suffmin[i+1],a[i]);
	}
	int ans = 1;
	for(i=0;i<n-1;i++){
		if(prefmax[i]<=suffmin[i+1]){ans++;}
	}
	printf("%d\n",ans);
	return 0;
};