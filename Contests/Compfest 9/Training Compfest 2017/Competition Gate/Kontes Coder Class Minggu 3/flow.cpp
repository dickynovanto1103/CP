#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int a[5][5],i,j;
	bool isVisited[5][5];
	int tc;

	scanf("%d",&tc);

	while(tc--){
		memset(isVisited,false,sizeof isVisited);
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]){isVisited[i][j] = true;}
			}
		}

		

	}
	return 0;
}