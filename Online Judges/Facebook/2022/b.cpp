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

string s[3010];
string temp[3010];

void fillAllBlankSpaceWithTree(int r, int c) {
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(temp[i][j] == '.') {
				temp[i][j] = '^';
			}
		}
	}
}

int neigh[3010][3010];

queue<ii> q;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

bool isTree(int i, int j) {
	return temp[i][j] == '^';
}

int numNeigh(int x, int y, int n, int m) {
	int ans = 0;

	for(int i=0;i<4;i++){
		int xbaru = x + dx[i];
		int ybaru = y + dy[i];
		if(xbaru >= 0 && xbaru < n && ybaru >= 0 && ybaru < m) {
			if(isTree(xbaru, ybaru)) {
				ans++;
			}
		}
	}

	return ans;
}

void calculateNeighbors(int r, int c) {
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(isTree(i, j)) {
				neigh[i][j] = numNeigh(i, j, r, c);
				if(neigh[i][j] <= 1) {
					q.push(ii(i,j));
				}
			}
		}
	}
}

bool isValid;

void eliminateAloneTrees(int r, int c) {
	while(!q.empty()) {
		ii koor = q.front(); q.pop();

		int x = koor.first, y = koor.second;
		if(s[x][y] == '^') {
			isValid = false;
			continue;
		}

		temp[x][y] = '.';
		for(int i=0;i<4;i++){
			int xbaru = x + dx[i], ybaru = y + dy[i];
			if(xbaru >= 0 && xbaru < r && ybaru >= 0 && ybaru < c && isTree(xbaru, ybaru)) {
				neigh[xbaru][ybaru]--;
				if(neigh[xbaru][ybaru] <= 1) {
					q.push(ii(xbaru, ybaru));
				}
			}
		}
	}
}

int main(){
	int tc;
	scanf("%d",&tc);
	
	for(int tt=1;tt<=tc;tt++){
		int r,c;
		scanf("%d %d",&r,&c);

		memset(neigh, 0, sizeof neigh);

		for(int i=0;i<r;i++){
			cin>>s[i];
			temp[i] = s[i];
		}

		fillAllBlankSpaceWithTree(r, c);
		calculateNeighbors(r, c);

		isValid = true;

		eliminateAloneTrees(r, c);
		if(!isValid) {
			puts("Impossible");
			continue;
		}

		puts("Possible");
		for(int i=0;i<r;i++){
			cout<<temp[i]<<endl;
		}
	}
	
	return 0;
};