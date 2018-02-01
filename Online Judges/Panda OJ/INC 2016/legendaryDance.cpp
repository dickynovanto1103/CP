#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int a[1010][1010];

int main() {
	int tc,test=1,i,j,n,m,arr1[1010],arr2[1010];
	scanf("%d",&tc);
	while(tc--){
		printf("Case #%d: ",test++);
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++){scanf("%d",arr1+i);}
		for(i=0;i<m;i++){scanf("%d",arr2+i);}
		//inisialisasi
		for(i=0;i<n;i++){a[i][0] = 0;}
		for(i=0;i<m;i++){a[0][i] = 0;}
		//dp
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				
				if(arr1[i-1]==arr2[j-1]){
					a[i][j] = a[i-1][j-1] + 1;
				}else{
					a[i][j] = max(a[i-1][j], a[i][j-1]);
				}
				
			}
		}
		int sama = a[n][m];
		printf("%d\n",n+m-sama);
	}
	return 0;
}