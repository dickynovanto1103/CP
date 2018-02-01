#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll mat[410][410];
int p[410][410];
vi ans;
void CatatPath(int i, int j){
	if(i!=j){CatatPath(i,p[i][j]);}
	//printf("yang dipush: %d\n",j);
	ans.pb(j);
}

int main() {
	int n,m,q,i,j,a,b;
	ll w;
	scanf("%d %d %d",&n,&m,&q);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){mat[i][j] = 0;}
			else{mat[i][j] = inf;}
			p[i][j] = i;
		}
	}
	for(i=0;i<m;i++){scanf("%d %d %d",&a,&b,&w); mat[a][b] = mat[b][a] = w;}

	for(int k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(mat[i][j] > mat[i][k] + mat[k][j]){
					mat[i][j] = mat[i][k] + mat[k][j];
					p[i][j] = p[k][j];
				}
			}
		}
	}
	while(q--){
		scanf("%d %d",&a,&b);
		CatatPath(a,b);
		int ukuran = ans.size();
		//printf("ukuran: %d\n",ukuran);
		for(i=0;i<ukuran;i++){
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");
		ans.clear();
	}
	return 0;
}