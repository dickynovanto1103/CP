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
	int n,i,a[100010];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	sort(a,a+n);
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
}