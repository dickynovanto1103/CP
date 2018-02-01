#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,i,a[1010];
	while(scanf("%d",&n),n){
		int bil;
		int cnt = 0;
		for(i=0;i<n;i++){scanf("%d",&bil); if(bil!=0){a[cnt] = bil; cnt++;}}
		if(!cnt){printf("0\n" );}
		else{
			for(i=0;i<cnt;i++){
				if(i){printf(" ");}
				printf("%d",a[i]);
			}
			printf("\n");
		}
	}
	return 0;
}