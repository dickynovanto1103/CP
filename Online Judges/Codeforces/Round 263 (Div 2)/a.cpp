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

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){
	int n,i,j,k;
	string kata[110];
	scanf("%d",&n);
	for(i=0;i<n;i++){cin>>kata[i];}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			int cnt = 0;
			for(k=0;k<4;k++){
				int x = i+dx[k], y = j+dy[k];
				if(x>=0 && x<n && y>=0 && y<n){
					if(kata[x][y]=='o'){cnt++;}
				}
			}
			if(cnt%2==1){printf("NO\n"); return 0;}
			
		}
	}
	printf("YES\n");
	return 0;
};