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

const int maxn = 1010;

bool isVisited[maxn][maxn];
string kata[1010];

bool isValid(int x, int y){
	int i,j;
	for(i=x;i<=(x+2);i++){
		for(j=y;j<=(y+2);j++){
			if(i == (x+1) && j == (y+1)){continue;}
			if(kata[i][j] == '#'){
				isVisited[i][j] = true;
			}else{
				return false;
			}
		}
	}
	return true;
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);

	memset(isVisited, false, sizeof isVisited);
	for(i=0;i<n;i++){cin>>kata[i];}
	for(i=0;i<=(n-3);i++){
		for(j=0;j<=(m-3);j++){
			if(kata[i][j] == '#'){
				int k,l;
				if(isValid(i,j)){

				}else{
					if(!isVisited[i][j]){
						printf("NO\n"); return 0;
					}
				}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(kata[i][j] == '#' && !isVisited[i][j]){
				printf("NO\n");return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
};