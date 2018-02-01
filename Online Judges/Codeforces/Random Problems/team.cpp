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
	if(n>=m){
		if((n-m)>1){printf("-1\n");}
		else if((n-m)==1){
			for(i=0;i<m;i++){printf("01");}
			printf("0\n");
		}else{//n dan m sama
			for(i=0;i<m;i++){printf("01");}
			printf("\n");
		}
	}else{
		int selisih = m-n;
		int selisihMaks = 3 + (n-1);
		if(selisih>selisihMaks){printf("-1\n"); return 0;}
		while(m>n){
			printf("110");
			m-=2;
			n--;
			if(n==0 || m==0){break;}
		}
		if(n==0){
			for(i=0;i<m;i++){printf("1");}	
			printf("\n");
		}else{
			if(m==0){
				if(n==1){printf("0\n");}

			}else{
				for(i=0;i<m;i++){
					printf("10");
				}
				printf("\n");
			}
		}
		
		printf("\n");

	}
	
	return 0;
};