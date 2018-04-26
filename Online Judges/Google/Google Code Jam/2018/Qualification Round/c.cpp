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

const int maxn = 1001;
bool mat[maxn][maxn];

int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

bool isFull(int x, int y){
	int j;
	for(j=0;j<8;j++){
		int xbaru = x+dx[j], ybaru = y+dy[j];
		if(!mat[xbaru][ybaru]){break;}
	}
	if(mat[x][y] && j==8){
		return true;
	}
	return false;
}

int main(){
	int tc,a,i,j;
	
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		scanf("%d",&a);
		memset(mat,false,sizeof mat);
		// cerr<<"a: "<<a<<endl;
		int x = 2, y = 2;
		bool status = true;
		int counter = 0;
		for(i=0;i<10000;i++){
			// cerr<<"i: "<<i<<endl;
			
			cout<<x<<" "<<y<<flush<<endl;
			int absis, ordinat;
			cin>>absis>>ordinat;
			if(absis == 0 && ordinat==0){break;}
			else if(absis == -1 && ordinat == -1){status = false; break;}
			mat[absis][ordinat] = true;
			
			if(isFull(x,y)){
				x+=3;
			}

		}

		// for(j=0;j<10;j++){
		// 	for(int k=0;k<10;k++){
		// 		cerr<<mat[j][k];
		// 	}
		// 	cerr<<endl;
		// }

		if(!status){
			break;
		}
	}

	return 0;
};