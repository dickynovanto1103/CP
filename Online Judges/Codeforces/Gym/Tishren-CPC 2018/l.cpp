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
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		if(n%2==1){
			printf("%d %d\n",n/2 + 1, n/2);
		}else{
			printf("%d %d\n",n/2, n/2);
		}
	}
	return 0;
};