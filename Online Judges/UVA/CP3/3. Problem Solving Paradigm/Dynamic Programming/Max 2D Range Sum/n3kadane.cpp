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
	int n,a[110][110],i,j,k,l;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	//summing on column first
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j){a[i][j]+=a[i][j-1];}
		}
	}
	int maks = -inf;
	for(i=0;i<n;i++){//batas kiri
		for(j=i;j<n;j++){//batas kanan
			//sekarang lewat row	
			int temp = 0;
			//mulai kadane algo
			for(int row=0;row<n;row++){
				if(i){temp+=a[row][j] - a[row][i-1];}
				else{temp+=a[row][j];}

				if(temp<0){temp = 0;}
				maks = max(maks,temp);
			}
		}
	}
	printf("%d\n",maks);
	return 0;
}