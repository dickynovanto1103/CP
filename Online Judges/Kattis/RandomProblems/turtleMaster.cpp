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

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
string kata[10];

bool isValid(int x, int y){
	return x>=0 && x<8 && y>=0 && y<8 && (kata[x][y] == '.' || kata[x][y] == 'D');
}
bool isValidIce(int x, int y){
	return x>=0 && x<8 && y>=0 && y<8 && kata[x][y] == 'I';
}

int main(){
	
	int i,j;
	for(i=0;i<8;i++){
		cin>>kata[i];
	}
	string dir;
	cin>>dir;
	int arah = 1;
	int x = 7, y = 0;
	for(i=0;i<dir.length();i++){
		char kar = dir[i];
		if(kar == 'F'){
			x += dx[arah]; y += dy[arah];
			if(!isValid(x,y)){
				// printf("halo\n");
				printf("Bug!\n"); return 0;
			}
		}else if(kar == 'R'){
			arah++; arah%=4;
		}else if(kar == 'L'){
			arah--; arah%=4;
			if(arah < 0){arah+=4;}
		}else if(kar == 'X'){
			int xbaru = x + dx[arah], ybaru = y + dy[arah];
			// printf("xbaru: %d ybaru; %d %c\n",xbaru, ybaru, kata[xbaru][ybaru]);
			if(isValidIce(xbaru, ybaru)){
				kata[xbaru][ybaru] = '.';
			}else{
				// printf("halo2\n");
				printf("Bug!\n");
				return 0;
			}
		}
		// printf("koor skrg: %d %d\n",x,y);
	}
	if(kata[x][y] == 'D'){printf("Diamond!\n");}
	else{printf("Bug!\n");}
	return 0;
};