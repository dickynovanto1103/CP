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

const int maxn = 1e5 + 5;
vector<vi> AdjList;

int main(){
	int n,m,i,j;
	int f[maxn], b[maxn],a[maxn];
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1,vi());
	for(i=0;i<n;i++){
		scanf("%d",&f[i]);
		AdjList[f[i]].pb(i+1);
	}
	for(i=0;i<m;i++){
		scanf("%d",&b[i]);
		// if(AdjList[b[i]].size()>1){printf("Ambiguity\n"); return 0;}
		// else if(AdjList[b[i]].size()==0){printf("Impossible\n"); return 0;}
		// else{
		// 	int bil = AdjList[b[i]][0];
		// 	a[i] = bil;
		// }
	}
	for(i=0;i<m;i++){
		if(AdjList[b[i]].size()==0){printf("Impossible\n"); return 0;}
	}
	for(i=0;i<m;i++){
		if(AdjList[b[i]].size()>1){printf("Ambiguity\n"); return 0;}
	}
	for(i=0;i<m;i++){
		int bil = AdjList[b[i]][0];
		a[i] = bil;
	}
	printf("Possible\n");
	for(i=0;i<m;i++){
		if(i){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");

	return 0;
};