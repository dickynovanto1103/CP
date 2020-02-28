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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool 

int main(){
	int n,m,i,j,tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		if(n > m){swap(n,m);}
		if(n == 1) {
			if(m <= 2){printf("%d\n",m);}
			else{printf("0\n");}
		}else if(n == 2){
			if(m % 2 == 1){
				printf("4\n");
			}else{
				printf("%d\n",n*m);
			}
		}else{
			if(n % 2 == 0){
				if(m%2 == 0){
					printf("%d\n",n*2 + 2*m - 4);
				}else{
					printf("0\n");
				}
			}else{
				printf("0\n");	
			}
			
		}
	}
	return 0;
};