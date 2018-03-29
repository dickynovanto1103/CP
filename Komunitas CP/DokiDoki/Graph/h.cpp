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
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	ll c[10][10];
	ll dist[10][10];
	for(i=0;i<=9;i++) {
		for(j=0;j<=9;j++){
			scanf("%lld",&c[i][j]);
			dist[i][j] = c[i][j];
			
		}
	}

	//floyd wharshall
	for(int k=0;k<=9;k++){
		for(i=0;i<=9;i++){
			for(j=0;j<=9;j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);		
			}
		}
		
	}
	

	// for(i=0;i<=9;i++){
	// 	for(j=0;j<=9;j++){
	// 		if(j){printf(" ");}
	// 		printf("%d",dist[i][j]);
	// 	}
	// 	printf("\n");
	// }
	ll sum = 0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			int bil;
			scanf("%d",&bil);
			if(bil==-1){continue;}
			sum+=dist[bil][1];
		}
	}
	printf("%lld\n",sum);
	return 0;
};