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

vector<vi> AdjList;

int main(){
	int n,m,k,a[100010],i,j;
	scanf("%d %d %d",&n,&k,&m);
	AdjList.assign(m,vi());
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		AdjList[a[i]%m].pb(a[i]);
	}
	bool found = false;
	for(i=0;i<m;i++){
		if(AdjList[i].size()>=k){
			found = true;
			printf("Yes\n");
			for(j=0;j<k;j++){
				if(j){printf(" ");}
				printf("%d",AdjList[i][j]);
			}
			printf("\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
};