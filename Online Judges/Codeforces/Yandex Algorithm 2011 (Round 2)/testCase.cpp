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

const int maxn = 2e5;
const int maxbil = 1e6;
int main(){
	int n = maxn,t = maxn;
	int i,j;
	printf("%d %d\n",n,t);
	srand(time(NULL));
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		int bil = 
		printf("%d",(((rand()<<14) + rand())%maxbil)+1);
	}
	printf("\n");
	for(i=0;i<t;i++){
		int idx1 = (((rand()<<14) + rand())%maxn)+1;
		int banyakSisa = n-idx1-2;
		int idx2 = min(200000,idx1 + (((rand()<<14) + rand())%banyakSisa)+1);
		printf("%d %d\n",idx1,idx2);
	}
	return 0;
};