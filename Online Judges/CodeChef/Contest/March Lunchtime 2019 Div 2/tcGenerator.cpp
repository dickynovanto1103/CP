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
	int n = 1;
	int tc = 8*10;
	int i,j;
	printf("%d\n",tc);

	for(i=0;i<10;i++){
		for(j=0;j<=7;j++){
			printf("1\n");
			printf("%d %d\n",i,j);
		}
	}
	return 0;
};