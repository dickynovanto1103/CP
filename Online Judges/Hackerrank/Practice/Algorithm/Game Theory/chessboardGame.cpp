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

int dx[] = {-2,-2,1,-1};
int dy[] = {1,-1,-2,-2};

const int maxn = 15;
int a[15][15];

bool isAllComplete(){
	int i,j;
	for(i=0;i<maxn;i++){
		for(j=0;j<maxn;j++){
			if(a[i][j]==-1){return false;}
		}
	}
	return true;
}

int main(){
	int i,j,k;
	int n = maxn;
	memset(a,-1,sizeof a);
	a[0][0] = a[1][0] = a[1][0] = a[1][1] = 0;
	while(true){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				set<int> s;
				bool foundNotValid = false;
				for(k=0;k<4;k++){
					int xbaru = i+dx[k], ybaru = j+dy[k];
					if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<n){
						if(a[xbaru][ybaru]==-1){foundNotValid = true; break;}
						s.insert(a[xbaru][ybaru]);
					}
				}
				if(!foundNotValid){
					for(k=0; ;k++){
						if(!s.count(k)){
							a[i][j] = k;
							break;
						}
					}
				}
			}
		}
		/*printf("kondisi sekarang: \n");
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j){printf(" ");}
				printf("%d",a[i][j]);
			}
			printf("\n");
		}*/
		if(isAllComplete()){break;}
	}
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&i,&j);
		int bil = a[i-1][j-1];
		if(bil==0){printf("Second\n");}
		else{printf("First\n");}
	}
	return 0;
};