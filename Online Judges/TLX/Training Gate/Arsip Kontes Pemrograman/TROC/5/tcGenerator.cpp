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
	int n,q,i,j;
	n = 5, q = 5;
	printf("%d %d\n",n,q);
	srand(time(NULL));
	for(i=0;i<n;i++){
		printf("%d ",rand()%10 + 1);
	}
	printf("\n");
	for(i=0;i<q;i++){
		int bil = rand()%2 + 1;
		if(bil == 1){printf("%d %d %d\n",bil, rand()%n+1, rand()%10 + 1);}
		else{printf("%d\n",bil);}
	}
	return 0;
};