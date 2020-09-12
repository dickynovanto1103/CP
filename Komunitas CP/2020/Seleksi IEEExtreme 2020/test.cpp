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
	int n = 8;
	int prime[] = {3,5,7,11, 13, 17, 23, 31, 37};
	srand(time(NULL));
	printf("%d\n",n);
	for(int i=0;i<n;i++){
		int bil = rand()%9;
		printf("%d ",prime[bil]);
	}
	printf("\n");
	
	return 0;
};