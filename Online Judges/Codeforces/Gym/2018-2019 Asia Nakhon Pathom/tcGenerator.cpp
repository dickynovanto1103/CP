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
	int tc = 20;
	printf("%d\n",tc);
	srand(time(NULL));
	int i,j;
	for(int tt=1;tt<=tc;tt++){
		int r,c;
		r = rand()%1000 + 1;
		c = rand()%1000 + 1;

		printf("%d %d\n",r,c);
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(j < c-1){
					printf("%d ",rand()%2);
				}
				else{
					printf("%d",rand()%2);
				}
			}
			printf("\n");
		}
	}
	return 0;
};