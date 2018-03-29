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
	int tc,n,i,j;
	scanf("%d",&tc);
	int idxJabatTangan[20000];

	for(i=2;;i++){
		int banyakJabat = (i*(i-1))/2;
		if(banyakJabat>10000){break;}
		idxJabatTangan[banyakJabat] = i;
		// printf("i: %d\n",i);
	}
	while(tc--){
		scanf("%d",&n);
		printf("%d\n",idxJabatTangan[n]);
	}
	return 0;
};