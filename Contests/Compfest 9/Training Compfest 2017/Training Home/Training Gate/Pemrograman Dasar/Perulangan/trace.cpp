#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,i,j,a[510][510];
	scanf("%d",&n);
	int sum = 0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			if(i==j){sum+=a[i][j];}
		}
	}
	printf("%d\n",sum);
	
	return 0;
}