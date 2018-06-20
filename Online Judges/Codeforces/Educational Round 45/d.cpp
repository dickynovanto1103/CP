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

const int maxn = 1e3 + 3;

int arr[maxn][maxn];

int main(){
	int n,i,j,a,b;
	scanf("%d %d %d",&n,&a,&b);
	if(n==1){
		if(a==1 && b==1){
			printf("YES\n");
			printf("0\n");
		}else{
			printf("NO\n");
		}
	}else if(n==2){
		if(a==1 && b==1){printf("NO\n");}
		else if(a==1 && b==2){
			printf("YES\n");
			printf("01\n");
			printf("10\n");
		}else if(a==2 && b==1){
			printf("YES\n");
			printf("00\n");
			printf("00\n");
		}else{
			printf("NO\n");
		}
	}else if(n==3) {
		if(a==3){
			if(b==1){
				printf("YES\n");
				printf("000\n");
				printf("000\n");
				printf("000\n");
			}else{
				printf("NO\n");
			}
		}else if(a==2){
			if(b==1){
				printf("YES\n");
				printf("010\n");
				printf("100\n");
				printf("000\n");
			}else{
				printf("NO\n");
			}
		}else if(a==1){
			if(b==2){
				printf("YES\n");
				printf("010\n");
				printf("101\n");
				printf("010\n");
			}else if(b==3){
				printf("YES\n");
				printf("011\n");
				printf("101\n");
				printf("110\n");
			}else{
				printf("NO\n");
			}
		}
	}else{
		if(a==1 && b==1){
			printf("YES\n");
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(abs(i-j)==1){
						printf("1");
					}else{
						printf("0");
					}
				}
				printf("\n");
			}
		}
		else{
			if(a==1 || b==1){
				if(a==1){
					if(b==n){
						printf("YES\n");
						for(i=0;i<n;i++){
							for(j=0;j<n;j++){
								if(i!=j){printf("1");}
								else{printf("0");}
							}
							printf("\n");
						}
					}else{
						int connectedUntil = n-(b-1);
						for(i=0;i<n;i++){
							for(j=0;j<n;j++){
								if(i==j){arr[i][j] = 1; continue;}
								if(i>=connectedUntil || j>=connectedUntil){arr[i][j] = 0;}
								else{
									arr[i][j] = 1;
								}
							}
						}
						printf("YES\n");
						for(i=0;i<n;i++){
							for(j=0;j<n;j++){
								printf("%d",1-arr[i][j]);
							}
							printf("\n");
						}
					}
				}else if(b==1){
					if(a==n){
						printf("YES\n");
						for(i=0;i<n;i++){
							for(j=0;j<n;j++){
								printf("0");
							}
							printf("\n");
						}	
					}else{
						int connectedUntil = n-(a-1);
						// printf("connectedUntil: %d\n",connectedUntil);
						printf("YES\n");
						for(i=0;i<n;i++){
							for(j=0;j<n;j++){
								if(i==j){printf("0"); continue;}
								if(i>=connectedUntil || j>=connectedUntil){printf("0");}
								else{
									printf("1");
								}	
							}
							printf("\n");
						}
					}
				}
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
};