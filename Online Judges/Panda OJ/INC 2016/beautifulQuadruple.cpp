#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int tc,i,j,k,l,r,c;
	scanf("%d",&tc);
	int test=1;
	int a[155][155];
	while(tc--){
		printf("Case #%d: ",test++);
		scanf("%d %d",&r,&c);
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				scanf("%d",&a[i][j]);
			}
		}
		int cnt = 0;
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				for(k=j+1;k<c;k++){
					if(a[i][j] == a[i][k]){
						for(l=i+1;l<r;l++){
							if(a[i][j] == a[l][j] && a[i][j] == a[l][k]){cnt++;}
						}
					}
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}