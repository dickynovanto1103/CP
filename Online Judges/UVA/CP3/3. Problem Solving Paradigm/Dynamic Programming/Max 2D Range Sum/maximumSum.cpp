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

int main() {
	int n,a[102][102],i,j,k,l;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){scanf("%d",&a[i][j]);}
	}
	//dp
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i>0){a[i][j]+=a[i-1][j];}
			if(j>0){a[i][j]+=a[i][j-1];}
			if(i>0 && j>0){a[i][j]-=a[i-1][j-1];}
		}
	}

	int maks = -127*100*100;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=i;k<n;k++){
				for(l=j;l<n;l++){
					int temp = a[k][l];
					if(i>0){temp-=a[i-1][l];}
					if(j>0){temp-=a[k][j-1];}
					if(i>0 && j>0){temp+=a[i-1][j-1];}
					maks = max(maks, temp);
				}
			}
		}
	}
	printf("%d\n",maks);
	return 0;
}