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

int main(){
	int n,i,j;
	scanf("%d",&n);
	int x[50], y[50];
	int cntX[51], cntY[51];
	memset(cntX, 0, sizeof cntX);
	memset(cntY, 0, sizeof cntY);
	int minX = 50, minY = 50, maksX = 0, maksY = 0;
	int eks, ye;
	int normal = n+1;
	for(i=0;i<4*n+1;i++){
		scanf("%d %d",&x[i],&y[i]);
		cntX[x[i]]++; cntY[y[i]]++;

	}
	for(i=0;i<4*n+1;i++){
		cntX[x[i]]--; cntY[y[i]]--;
		minX = 50, minY = 50, maksX = 0, maksY = 0;
		for(j=0;j<=50;j++){
			if(cntX[j]){minX = min(minX, j); maksX = max(maksX, j);}
			if(cntY[j]){minY = min(minY, j); maksY = max(maksY, j);}
		}
		// printf("x[%d]: %d y[%d]: %d\n",i,x[i], i,y[i]);
		// printf("%d %d %d %d\n",minX, maksX, minY, maksY);
		bool valid = true;
		if(cntX[minX] == normal && cntX[maksX] == normal){
			for(j=minX+1;j<maksX;j++){
				if(cntX[j] == 2){

				}else{
					valid = false;
					break;
				}
			}
		}else{
			valid = false;
		}

		if(cntY[minY] == normal && cntY[maksY] == normal){
			for(j=minY+1;j<maksY;j++){
				if(cntY[j] == 2){

				}else{
					valid = false;
					break;
				}
			}
		}else{
			valid = false;
		}
		
		if(valid){
			printf("%d %d\n",x[i], y[i]);
			return 0;
		}
		cntX[x[i]]++; cntY[y[i]]++;

	}
	// printf("%d %d %d %d\n",minX, maksX, minY, maksY);
	
	// printf("%d %d\n",eks, ye);
	return 0;
};