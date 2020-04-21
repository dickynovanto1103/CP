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

int getMin(int a) {
	return a - inf;
}

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){
	int tc,a,b,i,j;
	scanf("%d %d %d",&tc,&a,&b);
	while(tc--){
		if(a == b){
			//radius = a
			int r = a;
			int minim = getMin(a);
			int minX, minY, maksX, maksY;
			minX = minim, maksX = -minim;
			minY = minim, maksY = -minim;
			int midX = 0, midY = 0, ansX, ansY;
			
			
			bool found = false;
			while(true){
				//tembak atas
				vi list;
				int cntHit = 0;
				midX = (minX + maksX) / 2;
				midY = (minY + maksY) / 2;
				ii pas = ii(midX, midY);
				for(i=0;i<4;i++){
					int selX = dx[i] * r, selY = dy[i] * r;

					printf("%d %d\n",pas.first + selX, pas.second + selY);
					fflush(stdout);
					string ans;
					cin>>ans;
					if(ans == "WRONG"){return 0;}
					if(ans == "HIT"){list.pb(i); cntHit++;}
					else if (ans == "CENTER"){found = true; break;}
					else{list.pb(-1);}
				}

				if(found){break;}

				if(cntHit == 4){
					printf("%d %d\n",pas.first, pas.second); fflush(stdout); 
					string ans;
					cin>>ans;
					if(ans == "WRONG"){return 0;}
					else if(ans == "CENTER"){found = true;}
				}

				if(found){break;}
				int totalX = 0, totalY = 0;
				for(i=0;i<list.size();i++){
					if(list[i] != -1){

						int bil = list[i];
						totalX += dx[bil], totalY += dy[bil];
					}
				}

				if(totalX == -1){
					maksX = midX-1;
				}else if(totalX == 1){
					minX = midX + 1;
				}

				if(totalY == -1){
					maksY = midY-1;
				}else if(totalY == 1){
					minY = midY + 1;
				}
			}
		}
	}
	
	return 0;
};