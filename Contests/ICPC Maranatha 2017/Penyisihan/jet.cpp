#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int tc,x,y,z,x1,y1,x2,y2,dist;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d %d %d %d %d %d",&x,&y,&z,&x1,&y1,&x2,&y2,&dist);
		int minimx = min(x1,x2), maksx = max(x1,x2);
		int minimy = min(y1,y2), maksy = max(y1,y2);
		if(x>=minimx && x<=maksx && y>=minimy && y<=maksy){
			if(z > dist){printf("hold\n");}
			else{printf("shoot\n");}
		}else{
			printf("hold\n");
		}
	}
	return 0;
}