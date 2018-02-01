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
	int tc,i,a[3];
	//printf("%d\n",'A');
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d%d", &a, &b, &c);
		if (a > b^c) printf("A %d\n", a - b^c);
		else if (b > a^c) printf("A %d\n", b - a^c);
		else printf("C %d\n", c - a^b);
		//printf("hasilxor: %d\n",hasilxor);
	}
	return 0;
}