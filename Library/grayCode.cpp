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
	int n,i,j;
	scanf("%d",&n);
	vi listBil;
	for(i=0;i<=n;i++){
		listBil.pb(i);
	}
	do{
		// for(i=0;i<=n;i++){
		// 	printf("%d ",listBil[i]);
		// }
		// printf("\n");
		bool bisa = true;

		for(i=1;i<=n;i++){
			int bil1 = listBil[i-1];
			int bil2 = listBil[i];
			int cnt = 0;
			for(j=0;j<31;j++){
				if(((1<<j) & bil1) && !((1<<j) & bil2)) {
					cnt++;
				}else if(!((1<<j) & bil1) && ((1<<j) & bil2)){
					cnt++;
				}
				if(cnt == 2){
					// printf("ga bisa\n");
					bisa = false;
					goto end;	
				}
				
			}

		}
		end:;
		if(bisa){
			printf("bisa\n");
			for(i=0;i<=n;i++){
				printf("%d ",listBil[i]);
			}
			printf("\n");
		}

	}while(next_permutation(listBil.begin(), listBil.end()));

	return 0;
};