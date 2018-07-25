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
	int tc = 50;
	srand(time(NULL));
	printf("%d\n",tc);
	while(tc--){
		int n, m, k;
		n = rand()%10000 + 1;
		m = rand()%10000 + 1;
		k = rand()%100 + 1;
		printf("%d %d %d\n",n,m,k);
		
		for(int i=0;i<m;i++){
			int a,b,w;
			a = rand() % n + 1;
			b = rand() % n + 1;
			w = rand() % 1000000 + 1;
			printf("%d %d %d\n",a,b,w);
		}
		int s,e;
		s = rand()%10000 + 1;
		e = rand()%10000 + 1;
		printf("%d %d\n",s,e);
	}
	
	return 0;
};