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
	int v,a[3];
	char c[3] = {'F', 'M', 'T'};
	while(scanf("%d %d %d %d",&v,&a[0],&a[1],&a[2]) != EOF) {
		// printf("v: %d\n", v);
		int idx = 0;
		while(true){
			if(v < a[idx]) {
				printf("%c\n", c[idx]);
				break;
			}
			v -= a[idx++];
			idx %= 3;
		}
	}
	

	return 0;
};