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
	int tc = 1000;
	printf("%d\n",tc);
	srand(time(NULL));
	while(tc--){
		int n,k;
		n = rand()%100000 + 1; k = rand()%n + 1;
		printf("%d %d\n",n,k);
		for(int i=0;i<n;i++){
			int l = rand()%inf;
			int r = rand()%inf + l;
			if(r > inf){r = inf;}
			printf("%d %d\n",l,r);
		}
		printf("\n");
	}
	
	return 0;
};