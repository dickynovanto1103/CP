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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int a[22][22];

void cetak(int n, int m) {
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(j){printf(" ");}
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int tc,i,j,n,m;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		scanf("%d %d",&n,&m);
		bool swapped = false;
		if(n > m){swap(n,m); swapped = true;}
		
		int b[22][22];
		ii koor[440];
		int cnt = 0;
		if(n == 2){
			if(m <=4){printf("IMPOSSIBLE\n");}
			else{
				printf("POSSIBLE\n");
				//prosees
				int kol = 0;
				
				for(j=m/2;j<m;j++){
					a[1][j] = cnt++;
					a[0][kol++] = cnt++;
				}
				for(j=0;j<m/2;j++){
					a[1][j] = cnt++;
					a[0][kol++] = cnt++;
				}
				cetak(n,m);
			}
		}else if(n == 3){
			if(m == 3){printf("IMPOSSIBLE\n");}
			else{
				printf("POSSIBLE\n");
				int kol = 0;
				if(m & 1){

				}
				for(i=1;i<n;i++){
					for(j=m/2;j<m;j++){
						if(m & 1) {
							 
						}
					}
				}
			}
		}else{
			printf("POSSIBLE\n");
		}
		
	}
	return 0;
};