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

const int maxn = 1e3 + 2;

int main(){
	int n,i,j;
	int p[maxn];
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%d",&p[i]);}
	bool isVisited[maxn];
	int node;
	for(i=1;i<=n;i++){
		memset(isVisited, false, sizeof isVisited);
		isVisited[i] = true;
		node = p[i];
		while(!isVisited[node]){
			isVisited[node] = true;
			node = p[node];
		}
		if(i>1){printf(" ");}
		printf("%d",node);
	}
	printf("\n");
	return 0;
};