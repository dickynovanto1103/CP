#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int a,b;
	scanf("%d %d",&a,&b);
	int minim = min(a,b);
	int sum = 1;
	for(int i=2;i<=minim;i++){
		sum*=i;
	}
	printf("%d\n",sum);
	return 0;
}