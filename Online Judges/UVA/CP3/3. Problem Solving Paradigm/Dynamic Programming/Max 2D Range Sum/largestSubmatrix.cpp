#include <bits/stdc++.h>

using namespace std;
#define inf 10000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int tc,i,j,k,l,n,a[30][30], test=1;
	string kata[30];
	scanf("%d",&tc);
	
	while(tc--){
		if(test==2){printf("\n");}
		i=0;
		cin>>kata[i];
		int n = kata[i].length();
		for(i=1;i<n;i++){
			cin>>kata[i];
		}

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				a[i][j] = kata[i][j]-'0';
				if(a[i][j]==0){a[i][j]=-inf;}
			}
		}
		/*for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j>0){printf(" ");}
				printf("%d",a[i][j]);
			}
			printf("\n");
		}*/

		/*for(i=0;i<n;i++){
			printf("i: %d\n",i);
		}*/
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i>0){a[i][j] += a[i-1][j];}
				if(j>0){a[i][j] += a[i][j-1];}
				if(i>0 && j>0){a[i][j] -= a[i-1][j-1];}
			}
		}
		int maks = 0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(k=i;k<n;k++){
					for(l=j;l<n;l++){
						int temp = a[k][l];
						if(i>0){temp-=a[i-1][l];}
						if(j>0){temp-=a[k][j-1];}
						if(i>0 && j>0){temp+=a[i-1][j-1];}
						maks = max(maks,temp);
					}
				}
			}
		}
		printf("%d\n",maks);
		test=2;
	}
	return 0;
}