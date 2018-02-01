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

ll ans[1010][5];

int main(){
	int n,i,j,k;
	scanf("%d %d",&n,&k);
	int inputN = n, inputK = k;
	ans[4][1] = 1; ans[4][2] = 7; ans[4][3] = 15; ans[4][4] = 24;
	for(i=5;i<=1000;i++){
		for(j=1;j<=4;j++){
			if(j==1){ans[i][j] = 1;}
			else if(j==2){ans[i][j] = ans[i-1][j] + i-1;}
			else if(j==3){ans[i][j] = ans[i-1][j] + (i-1)*(i-1);}
			else{
				ll diff1[1010], diff2[1010], diff3[1010];
				diff1[0] = 38;
				for(k=1;k<=1000;k++){
					diff1[k]= diff1[k-1] + 9;
					//printf("diff1: k: %d %lld\n",k, diff1[k]);
				}
				diff2[0] = 63;
				for(k=1;k<=1000;k++){
					diff2[k]= diff2[k-1] + diff1[k-1];
					//printf("diff2: k: %d %lld\n",k, diff2[k]);
				}

				diff3[0] = 52;
				for(k=1;k<=1000;k++){
					diff3[k]=diff3[k-1] + diff2[k-1];
				}				
				ans[i][j] = ans[i-1][j] + diff3[i-5];
				//printf("i: %d ditambah diff3: %lld\n",i,diff3[i-5]);
			}
		}
	}

	// for(i=4;i<=10;i++){
	// 	for(j=1;j<=4;j++){
			
	// 		printf("i: %d j: %d %lld\n",i,j,ans[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("n: %d k: %d\n",n,k);
	printf("%lld\n",ans[inputN][inputK]);
	return 0;
};