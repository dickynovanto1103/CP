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
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,r,c;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d:\n", tt);
		scanf("%d %d",&r,&c);
		char mat[100][100];
		for(int i=0;i<2*r+1;i++){
			for(int j=0;j<2*c+1;j++){
				mat[i][j] = '.';
				if(i % 2 == 0) {
					if(j % 2 == 0){
						mat[i][j] = '+';
					}else{
						mat[i][j] = '-';
					}
				}else{
					if(j % 2 == 0){
						mat[i][j] = '|';
					}
				}
			}
		}

		mat[0][0] = '.';
		mat[1][0] = '.';
		mat[0][1] = '.';

		for(int i=0;i<2*r+1;i++){
			for(int j=0;j<2*c+1;j++){
				printf("%c", mat[i][j]);
			}
			puts("");
		}
	}
	
	return 0;
};