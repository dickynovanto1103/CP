#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,a[100010],i,j,q;
	scanf("%d",&n);
	int bil;
	scanf("%d",&bil); a[0] = bil;
	for(i=1;i<n;i++){
		scanf("%d",&bil); a[i] = a[i-1]+bil;
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d",&bil);
		int idx = lower_bound(a,a+n,bil) - a;
		printf("%d\n",idx+1);
	}
	return 0;
}