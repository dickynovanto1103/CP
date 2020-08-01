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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n = 500;
	printf("%d\n",n);
	srand(time(NULL));
	int cnt = 1,i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			ll randomNum = (ll)rand()*(ll)rand();
			randomNum %= inf;
			printf("%lld ",randomNum+1);
			assert(randomNum+1 <= inf);
		}
		printf("\n");
	}
	
	return 0;
};