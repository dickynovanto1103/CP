#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,i,j;
	ll m,a[25];
	scanf("%d %lld",&n,&m);
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	bool found = false;
	for(i=0;i<(1<<n);i++){
		ll sum = 0;
		for(j=0;j<n;j++){
			if((1<<j) & i){sum+=a[j];}
		}
		if(sum==m){found = true; break;}
	}
	if(found){printf("bisa\n");}
	else{printf("tidak bisa\n");}
	return 0;
}