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
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	for(int tt=2;tt<=(k+1);tt++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j){printf(" ");}
				if(i==j){printf("%d",tt);}
				else{printf("1");}
			}
			printf("\n");
		}	
	}
	
	return 0;
};