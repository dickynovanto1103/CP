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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc = 100;
	printf("%d\n",tc);
	srand(time(NULL));
	while(tc--){
		int n,l,r;
		n = rand()%100000 + 1;
		l = rand()%100000 + 1;
		r = rand()%100000 + 1;
		for(int i=0;i<n;i++){
			int bil = rand()%100000 + 1;
			printf("%d ",bil);
		}
		printf("\n");
	}
	return 0;
};