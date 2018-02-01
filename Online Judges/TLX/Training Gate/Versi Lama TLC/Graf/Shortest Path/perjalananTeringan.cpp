#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1001;
bool isvisited[maxn][maxn];
int a[maxn][maxn];
int r1,c1,r2,c2;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n,m;
bool benar;
stack<ii> s;
void isFeasible(int batas){
	int i;
	while(!s.empty()){
		ii front = s.top(); s.pop();
		int r = front.first,c = front.second;
		if(r==r2 && c==c2){benar = true; break;}
		isvisited[r][c] = true;
		for(i=0;i<4;i++){
			int x = r+dx[i], y = c+dy[i];
			if(x>=0 && x<n && y>=0 && y<m){
				if(!isvisited[x][y] && a[x][y]!=-1){

					if(a[x][y]<=batas){
						//printf("x: %d y: %d\n",x,y);
						//printf("masuk sini\n");
						s.push(ii(x,y));
					}	
				}	
			}
		}	
	}
	
}

int main() {
	int i,j;
	scanf("%d %d",&n,&m);
	//printf("n: %d m: %d\n",n,m);
	int minim = inf,maks = -inf;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			minim = min(minim,a[i][j]); maks = max(maks,a[i][j]);
		}
	}
	
	scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
	//printf("r2: %d c2: %d\n",r2,c2);
	r1--; r2--; c1--; c2--;
	int kiri=minim, kanan=maks, mid, ans;
	while(kiri<=kanan){
		memset(isvisited,false,sizeof isvisited);
		mid = (kiri+kanan)/2;
		//printf("mid: %d\n",mid);
		benar = false;
		s.push(ii(r1,c1));
		isFeasible(mid);

		if(benar){
			ans = mid;
			//printf("ans: %d\n",ans);
			kanan = mid-1;
		}else{
			//printf("salah\n");
			kiri = mid+1;
		}
		while(!s.empty()){s.pop();}
	}
	printf("%d\n",ans);
	return 0;
}