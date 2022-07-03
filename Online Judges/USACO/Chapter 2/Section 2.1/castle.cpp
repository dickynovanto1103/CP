/*
ID: dickyno1
LANG: C++14
TASK: castle
*/

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
#define WEST 1
#define NORTH 2
#define EAST 4
#define SOUTH 8
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

class UnionFind{
private: 
	vi rank,p,setSize;
	int numset,i;
public:
	UnionFind(int n){
		numset=n; setSize.assign(n,1); rank.assign(n,0); p.assign(n,0);
		for(i=0;i<n;i++){p[i]=i;}
	}

	int findSet(int i){return (p[i]==i) ? i : (p[i]=findSet(p[i]));}
	bool isSameSet(int i, int j){return findSet(i)==findSet(j);}
	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			numset--;
			int x=findSet(i), y=findSet(j);
			if(rank[x] > rank[y]){p[y]=x; setSize[x]+=setSize[y];}
			else{
				p[x]=y;
				setSize[y]+=setSize[x];
				if(rank[x]==rank[y]){rank[y]++;}
			}
		}
	}
	int numDisjointSet(){return numset;}
	int sizeSetOf(int i){return setSize[findSet(i)];}
};

int convertToNum(int r, int c, int numCol) {
	return r * numCol + c;
}

bool isThereWallInDir(int num, int dir) {
	// printf("num: %d dir: %d and: %d\n", num, dir, num & dir);
	return num & dir;
}

bool isInBound(int i, int j, int n, int m) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

int a[51][51];

int main(){
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);

	int n,m,i,j;
	scanf("%d %d",&m,&n);

	UnionFind UF(n * m);

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			int numKoor = convertToNum(i,j, m);
			int bil;
			scanf("%d",&bil);
			a[i][j] = bil;
			if(!isThereWallInDir(bil, NORTH)) {
				// printf("bil: %d dir: %d, isThereWallInDir: %d\n", bil, NORTH, isThereWallInDir(bil, NORTH));
				int num = convertToNum(i-1, j, m);
				UF.unionSet(numKoor, num);
				// printf("NORTH union: %d %d with %d %d\n", i, j, i-1, j);
			}

			if(!isThereWallInDir(bil, EAST)) {
				int num = convertToNum(i, j+1, m);
				UF.unionSet(numKoor, num);
				// printf("EAST union: %d %d with %d %d\n", i, j, i, j + 1);
			}

			if(!isThereWallInDir(bil, SOUTH)) {
				int num = convertToNum(i + 1, j, m);
				UF.unionSet(numKoor, num);
				// printf("SOUTH union: %d %d with %d %d\n", i, j, i+1, j);
			}

			if(!isThereWallInDir(bil, WEST)) {
				int num = convertToNum(i, j-1, m);
				UF.unionSet(numKoor, num);
				// printf("WEST union: %d %d with %d %d\n", i, j, i, j - 1);
			}
			// puts("");
		}
	}
	
	//num of rooms
	printf("%d\n", UF.numDisjointSet());
	//size of largest room
	int maks = 0;
	for(int i=0;i<n;i++){
		for(j=0;j<m;j++){
			int numKoor = convertToNum(i,j, m);
			maks = max(maks, UF.sizeSetOf(numKoor));
		}
	}
	printf("%d\n", maks);


	int maksGabung = 0;
	ii koor = ii(-1, -1);
	char c = 'z';
	//num of largest room created by removing one wall
	for(int j=0;j<m;j++){
		for(int i=n-1;i>=0;i--){
			int numKoor = convertToNum(i,j, m);
			int currSz = UF.sizeSetOf(numKoor);
			if(isThereWallInDir(a[i][j], NORTH) && isInBound(i-1, j, n, m)) {
				int num = convertToNum(i-1, j, m);
				if(UF.isSameSet(numKoor, num)) {continue;}
				int sz = UF.sizeSetOf(num);
				int szGabung = currSz + sz;
				if(maksGabung < szGabung) {
					maksGabung = szGabung;
					koor = {i + 1, j + 1};
					c = 'N';
				}
			}

			if(isThereWallInDir(a[i][j], EAST) && isInBound(i, j+1, n, m)) {
				int num = convertToNum(i, j+1, m);
				if(UF.isSameSet(numKoor, num)) {continue;}
				int sz = UF.sizeSetOf(num);
				int szGabung = currSz + sz;
				if(maksGabung < szGabung) {
					maksGabung = szGabung;
					koor = {i + 1, j + 1};
					c = 'E';
				}
			}
		}
	}
	printf("%d\n", maksGabung);
	assert(koor != ii(-1, -1));
	printf("%d %d %c\n", koor.first, koor.second, c);

	return 0;
};