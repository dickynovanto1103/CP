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

const int maxn = 1e5;

int main(){
	printf("%d %d 100 100\n",maxn,maxn);
	srand(time(NULL));
	int i;
	for(i=0;i<maxn;i++){
		if(i){printf(" ");}
		printf("%d",rand()%100 + 1);
	}
	printf("\n");
	for(i=0;i<maxn;i++){
		int a = rand()%maxn + 1,b = rand()%maxn + 1;
		if(a==b){i--; continue;}
		printf("%d %d\n",a,b);
	}
	return 0;
};