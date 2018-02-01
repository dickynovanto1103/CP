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
	int n,i;
	double bil;
	scanf("%d",&n);
	while(n--){
		scanf("%lf",&bil);
		if(bil==0){printf("inf\n");}
		else{
			printf("%lf\n",1.0/bil);
		}
	}
	return 0;
}