#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int dx[] = {-1,1,1,-1};
int dy[] = {-1,-1,1,1};

bool reachable(int r1, int c1, int r2, int c2){
	
	for(int i=0;i<4;i++){
		int r = r1, c = c1;
		while(r>=1 && r<=8 && c>=1 && c<=8){
			r+=dx[i]; c+=dy[i];
			if(r==r2 && c==c2){return true;}
		}
	}
	return false;
}

int main() {
	int r1,c1,r2,c2;
	scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
	if(r1==r2 && c1==c2){printf("0\n"); return 0;}
	int selisihR = abs(r1-r2);
	int selisihC = abs(c1-c2);
	if((selisihC + selisihR)%2==1){printf("-1\n");}
	else{
		if(reachable(r1,c1,r2,c2)){printf("1\n");}
		else{printf("2\n");}
	}
	return 0;
}