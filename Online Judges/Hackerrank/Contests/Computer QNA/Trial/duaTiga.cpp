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
	int tc,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		if(n%2==0 && n%3==0){printf("Habis dibagi 6\n");}
		else if(n%2==0 && n%3!=0){printf("Habis dibagi 2\n");}
		else if(n%2!=0 && n%3==0){printf("Habis dibagi 3\n");}
		else{printf(":(\n");}
	}
	return 0;
}