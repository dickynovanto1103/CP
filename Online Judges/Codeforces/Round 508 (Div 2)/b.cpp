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
	int i,n,j;
	scanf("%d",&n);
	if(n<=2){printf("No\n");}
	else{
		printf("Yes\n");
		
		if(n%2==1){
			printf("1 %d\n",(n+1)/2);
			printf("%d",n-1);
			for(i=1;i<=n;i++){
				if(i == ((n+1)/2)){continue;}
				printf(" %d",i);
			}
			printf("\n");
		}else{
			printf("1 %d\n",n/2);
			printf("%d",n-1);
			for(i=1;i<=n;i++){
				if(i == (n/2)){continue;}
				printf(" %d",i);
			}
			printf("\n");
		}
	}
	return 0;
};