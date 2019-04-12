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

int main(){
	int n,i,j;
	scanf("%d",&n);
	ll a[20010];
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(i=0;i<n-2;i++){
		for(j=i+1;j<n-1;j++){
			if(a[i] + a[j] > a[j+1]){printf("possible\n"); return 0;}
		}
	}
	printf("impossible\n");
	
	
	return 0;
};