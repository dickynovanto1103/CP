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
	int n,m,i,j,k;
	string kata[25];
	int mat[25][25],test=1;
	while(scanf("%d %d",&n,&m),n){
		for(i=0;i<n;i++){cin>>kata[i];}
		int a,b,w;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i==j){mat[i][j] = 0;}
				else{mat[i][j] = inf;}
			}
		}
		for(i=0;i<m;i++){scanf("%d %d %d",&a,&b,&w); a--; b--; mat[a][b] = mat[b][a] = w;}
		for(k=0;k<n;k++){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					mat[i][j] = min(mat[i][j],mat[i][k] + mat[k][j]);
				}
			}
		}
		int jawab = inf;
		string orang;
		for(i=0;i<n;i++){
			int ans = 0;
			for(j=0;j<n;j++){
				ans+=mat[i][j];
			}
			if(jawab > ans){jawab = ans; orang = kata[i];}
		}
		printf("Case #%d : ",test++);
		cout<<orang<<endl;
	}
	return 0;
}