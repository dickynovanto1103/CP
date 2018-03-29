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
	int r,c,i,j;
	string kata[510];
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++){
		cin>>kata[i];
	}

	int dx[]={-1,0,1,0};
	int dy[]={0,1,0,-1};
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			char kar = kata[i][j];
			if(kar=='W'){
				for(int k=0;k<4;k++){
					int xbaru = i+dx[k], ybaru = j+dy[k];
					if(xbaru>=0 && xbaru<r && ybaru>=0 && ybaru<c){
						if(kata[xbaru][ybaru]=='S'){printf("No\n"); return 0;}
					}
				}
			}
		}
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			char kar = kata[i][j];
			if(kar=='.'){
				kata[i][j] = 'D';
			}
		}
	}
	printf("Yes\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			char kar = kata[i][j];
			printf("%c",kar);
		}
		printf("\n");
	}

	return 0;
};