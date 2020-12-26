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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int obsX, obsY;
bool isObstacle(int x, int y) {
	return obsX == x && obsY == y;
}

int main(){
	int tc,i,j;
	string s;
	scanf("%d",&tc);
	while(tc--){
		// printf("new tc\n");
		cin>>s;
		// cout<<"s: "<<s<<endl;
		int n=s.length();
		int x = 0, y = 0;	
		for(i=0;i<n;i++){
			if(s[i] == 'L'){
				x--;
			}else if(s[i] == 'R'){
				x++;
			} else if(s[i] == 'D') {
				y--;
			}else if(s[i] == 'U'){
				y++;
			}
		}
		int banyakTidak0 = 0;
		if(x != 0){banyakTidak0++;}
		if(y != 0){banyakTidak0++;}
		// printf("x: %d y: %d banyakTidak0: %d\n", x,y, banyakTidak0);
		int ansX = 0, ansY = 0;
		if(banyakTidak0 == 0){
			printf("%d %d\n",inf,inf);
		} else {
			//cari di semua kemungkinan titik
			for(i=0;i<n;i++){
				int koorX = 0, koorY = 0;
				obsX = 0; obsY = 0;
				for(j=0;j<=i;j++){
					if(s[j] == 'L'){
						obsX--;
					}else if(s[j] == 'R'){
						obsX++;
					} else if(s[j] == 'D') {
						obsY--;
					}else if(s[j] == 'U'){
						obsY++;
					}
				}
				// printf("i: %d obs: %d %d\n",i, obsX, obsY);

				int x = 0, y = 0;
				for(j=0;j<n;j++){
					if(s[j] == 'L'){
						x--;
						if(isObstacle(x, y)){
							x++;
						}
					}else if(s[j] == 'R'){
						x++;
						if(isObstacle(x, y)){
							x--;
						}
					} else if(s[j] == 'D') {
						y--;
						if(isObstacle(x, y)){
							y++;
						}
					}else if(s[j] == 'U'){
						y++;
						if(isObstacle(x, y)){
							y--;
						}
					}	
				}
				if(x == y && x == 0){
					ansX = obsX, ansY = obsY;
					break;
				}

			}
			printf("%d %d\n", ansX, ansY);
		}

		
	}
	
	return 0;
};