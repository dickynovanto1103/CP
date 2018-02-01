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
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int a[110][110],i,j;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==0 && j==0){
				a[i][j] = m;
			}else if(i==j){
				a[i][j] = a[i-1][j-1] + k;
			}else if(i>j){
				a[i][j] = a[i-1][j] - 1;
			}else if(i<j){
				a[i][j] = a[i][j-1] - 1;
			}
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j){printf(" ");}
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
};