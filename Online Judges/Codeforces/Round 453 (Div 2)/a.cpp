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
	scanf("%d %d",&n,&m);
	int a[110],b[110];
	bool isVisited[110];
	memset(isVisited,false,sizeof isVisited);
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
		for(j=a[i];j<b[i];j++){
			isVisited[j] = true;
		}
	}
	for(i=0;i<m;i++){
		if(!isVisited[i]){printf("NO\n"); return 0;}
	}
	printf("YES\n");
	return 0;
};