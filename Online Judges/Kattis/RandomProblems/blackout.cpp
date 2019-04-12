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

bool mat[6][7];

int main(){
	
	int tc;
	scanf("%d",&tc);
	int i,j;
	while(tc--){
		memset(mat, false, sizeof mat);
		printf("%d %d %d %d\n", 3,1,3,6);
		for(i=1;i<=6;i++){
			mat[3][i] = true;
		}

		fflush(stdout);
		string kata;
		while(cin>>kata){

			if(kata == "GAME"){break;}
			else{
				int a,b,c,d;
				scanf("%d %d %d %d",&a,&b,&c,&d);
				
				if(a == c && b == d) {
					//2 kemungkinan
					mat[a][b] = true;
					if(!mat[6-a][b]){
						mat[6-a][b] = true;
						printf("%d %d %d %d\n",6-a,b,6-a,b);
						fflush(stdout);
						continue;
					}else if(!mat[a][7-b]){
						mat[a][7-b] = true;
						printf("%d %d %d %d\n",a,7-b,a,7-b);
						fflush(stdout);
						continue;
					}else if(!mat[6-a][7-b]){
						mat[6-a][7-b] = true;
						printf("%d %d %d %d\n",6-a, 7-b,6-a, 7-b);
						fflush(stdout);
						// assert(false);
						continue;
					}
				}

				if(a == c){
					printf("%d %d %d %d\n",5-a+1, b, 5-c+1, d);
					for(i=b;i<=d;i++){
						mat[6-a][i] = true;
						mat[a][i] = true;
					}

					fflush(stdout);
				}else{
					printf("%d %d %d %d\n",a,6-b+1,c,6-d+1);
					for(i=a;i<=c;i++){
						mat[i][7-b] = true;
						mat[i][b] = true;
					}
					fflush(stdout);
				}
			}	
		}
	}
	

	return 0;
};