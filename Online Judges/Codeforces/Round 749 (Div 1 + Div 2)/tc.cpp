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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n = 1000, m = 1000;
	printf("%d %d\n",n,m );
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf(".");
		}
		puts("");
	}
	int q = 200000;
	printf("%d\n", q);
	srand(time(NULL));
	while(q--){
		int a = rand() % m + 1;
		int b = a + 1 > m ? a : a + 1;
		printf("%d %d\n", a, b);
	}
	
	return 0;
};