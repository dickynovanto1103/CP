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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct rec {
	int minX, minY, maksX, maksY;
};

ii intersect(int x1,int y1, int x, int y) {
	int maksX = max(x1, x);
	int minY = min(y1, y);
	if(minY < maksX){
		return ii(inf,inf);
	}else{
		return ii(maksX, minY);
	}
}

int main(){
	int q,i,j;
	scanf("%d",&q);

	while(q--){
		int n;
		scanf("%d",&n);
		int x,y,a,b,c,d;
		int x1, y1, x2,y2;
		bool valid = true;
		for(i=0;i<n;i++){
			scanf("%d %d %d %d %d %d",&x,&y,&a,&b,&c,&d);
			int minX, minY, maksX, maksY;
			if(a == 0){
				minX = x;
			}else{
				minX = -100000;
			}
			if(b == 0){
				maksY = y;
			}else{
				maksY = 100000;
			}
			if(c == 0){
				maksX = x;
			}else{
				maksX = 100000;
			}

			if(d == 0){
				minY = y;
			}else{
				minY = -100000;
			}
			if(i == 0){
				x1 = minX, y1 = minY, x2 = maksX, y2 = maksY;
			}else{
				ii intersectX = intersect(x1, x2, minX, maksX);
				if(intersectX == ii(inf,inf)){valid = false; }
				ii intersectY = intersect(y1,y2,minY, maksY);
				if(intersectY == ii(inf,inf)){valid = false; }
				x1 = intersectX.first, x2 = intersectX.second;
				y1 = intersectY.first, y2 = intersectY.second;
			}
		}
		if(valid){
			printf("1 %d %d\n",x1,y1);
		}else{
			printf("0\n");
		}
	}
	return 0;
};