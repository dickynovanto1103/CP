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
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(n+1,vi());
	for(int tt=1;tt<=n;tt++){
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				int bil;
				scanf("%d",&bil);
				AdjList[tt].pb(bil);
			}
		}
		sort(AdjList[tt].begin(), AdjList[tt].end());
	}

	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			for(int k=0;k<25;k++){
				if(binary_search(AdjList[j].begin(), AdjList[j].end(), AdjList[i][k])) {
					printf("%d %d\n",i,j);
					return 0;
				}
			}
		}
	}
	printf("no ties\n");
	return 0;
};