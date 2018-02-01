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

const int maxn = 205;

int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

int manhattan(int x1,int y1, int x2, int y2){
	return abs(x1-x2) + abs(y1-y2);
}

int main(){
	int x1,y1,x2,y2,i,j;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	int minim = inf;
	for(i=0;i<8;i++){
		j=i+2;
		j%=8;
		int xbaru1 = x2+dx[i], ybaru1 = y2+dy[i];
		int xbaru2 = x2+dx[j], ybaru2 = y2+dy[j];
		int jarak = 6;
		jarak+=manhattan(xbaru1,ybaru1,x1,y1);
		jarak+=manhattan(xbaru2,ybaru2,x1,y1);
		minim = min(minim,jarak);
	}
	printf("%d\n",minim);
	return 0;
};