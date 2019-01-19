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
	int n = 10,i,j;
	srand(time(NULL));
	int a[129];
	for(i=1;i<=n;i++){
		a[i] = rand()%20 + 1;
		printf("%d ",a[i]);
	}
	printf("\n");
	for(i=1;i<=n-2;i++){
		printf("%d\n",a[i]^a[i+1]^a[i+2]);
	}
	printf("%d\n",a[n-1]^a[n]^a[1]);
	printf("%d\n",a[n]^a[1]^a[2]);
	return 0;
};