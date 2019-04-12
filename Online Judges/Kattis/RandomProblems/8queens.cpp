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

string kata[9];

int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

bool isAttacked(int x, int y) {
	int i,j;
	int xawal = x, yawal = y;
	for(i=0;i<8;i++){
		x = xawal, y = yawal;
		while(1){
			x += dx[i]; y += dy[i];
			if(x >= 0 && x < 8 && y>=0 && y<8){
				if(kata[x][y] == '*'){return true;}
			}
			else{
				break;
			}
		}
	}
	return false;
}

int main(){
	int i,j;
	
	for(i=0;i<8;i++){
		cin>>kata[i];
	}
	int cnt = 0;
	bool valid = true;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			// printf("i: %d j: %d\n",i,j);
			if(kata[i][j] == '*'){
				cnt++;
				// printf("i awal; %d j awal: %d\n",i,j);
				if(isAttacked(i,j)){valid = false; goto invalid;}
			}
		}
	}
	if(cnt < 8 || cnt > 8){valid =false;}

	invalid:
	if(valid){printf("valid\n");}
	else{printf("invalid\n");}
	return 0;
};