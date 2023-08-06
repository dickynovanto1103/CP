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

bool isCrossMachine(int oldPoint, int newPoint, char newDir) {
	
}

bool addOne(int oldPoint, int newPoint, char newDir, char dirInMachine) {
	if(newDir != dirInMachine) {
		return false;
	}
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		int n;
		int l;
		scanf("%d %d",&l,&n);

		char dirInMachine = '';
		int oldPoint = 0, oldDir = 'z';
		int newPoint, newDir;
		int ans = 0;
		for(int i=0;i<n;i++){
			int jarak;
			char dir;
			cin>>jarak>>dir;
			if(i == 0) {
				dirInMachine = dir;
			}
			newPoint = oldPoint + jarak * (dir == 'C' ? 1 : -1);
			newDir = dir;

			newPoint %= l;
			if(addOne(oldPoint, newPoint, newDir, dirInMachine)) {
				ans++;
				dirInMachine = newDir;
			}

			oldPoint = newPoint;
			oldDir = newDir;
		}
	}
	
	
	return 0;
};