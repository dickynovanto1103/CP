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
	int n,i,m;
	n = 10;
	m = 30;
	printf("%d %d\n",n,m);
	srand(time(NULL));
	int a, b;
	for(i=0;i<n;i++){
		a = rand()%50 + 1;
		b = rand()%20 + a;
		printf("%d %d\n",a,b);
	}
	return 0;
}