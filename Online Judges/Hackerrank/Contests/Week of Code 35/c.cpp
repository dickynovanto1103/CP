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

int main(){
	int r,c,i,j;
	int a[110][110];
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int ans = 2*r*c;
	//secara horizontal
	for(i=0;i<r;i++){
		int sum = a[i][0];
		for(j=0;j<c;j++){
			if(j==(c-1)){
				sum+=a[i][j];
			}else{
				sum+=abs(a[i][j] - a[i][j+1]);
			}
		}
		//printf("i: %d sum: %d\n",i, sum);
		ans+=sum;
		//printf("ans jd: %d\n",ans);
	}
	//secara vertikal
	for(j=0;j<c;j++){
		int sum = a[0][j];
		for(i=0;i<r;i++){
			if(i==(r-1)){
				sum+=a[i][j];
			}else{
				sum+=abs(a[i][j] - a[i+1][j]);
			}
		}
		//printf("i: %d sum: %d\n",i, sum);
		ans+=sum;
		//printf("ans jd: %d\n",ans);
	}
	printf("%d\n",ans);
	return 0;
};