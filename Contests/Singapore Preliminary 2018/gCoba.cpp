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
	int prime[] = {2,3,5,7,11,13,17,23};
	int pjg = 8;
	bool grun[1000];
	memset(grun, false, sizeof grun);
	int i,j;
	for(i=0;i<100;i++){
		if(!grun[i]){
			for(j=0;j<pjg;j++){
				int next = i + prime[j] - 1;
				grun[next] = true;
				printf("i: %d diassign true: %d\n",i,next);
			}
		}
	}
	for(i=0;i<100;i++){
		if(!grun[i]){
			printf("%d\n",i);
		}
	}
	return 0;
};