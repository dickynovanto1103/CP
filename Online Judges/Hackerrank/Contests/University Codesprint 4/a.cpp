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
	int n,m,i,j;
	int counter[1010];
	memset(counter,0,sizeof counter);
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		int idx;
		scanf("%d",&idx);
		counter[idx]++;
	}
	for(i=0;i<m;i++){
		if(i){printf(" ");}
		printf("%d",counter[i]);
	}
	printf("\n");
	return 0;
};