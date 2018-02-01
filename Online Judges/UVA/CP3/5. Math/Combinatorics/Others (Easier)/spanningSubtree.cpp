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

int main(){
	int n;
	int test = 1;
	while(scanf("%d",&n),n){
		printf("Case %d: ",test++);
		int bil1 = n*(n-1)/2;
		int bil2 = n-1;
		printf("%d\n",bil1/bil2);		
	}

	return 0;
};