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
typedef pair<ii,int> iii;
typedef vector<ii> vii;

const int maxn = 52;
int n,m;
int peta1[maxn][maxn];
bool isValid(int x, int y){
	if(x>0 && x<n && y>0 && y<m){
		if(peta1[x][y]==1){return false;}
		else{return true;}
	}
	return false;
}

int main() {
	int i,j,k;
	int a[maxn][maxn];
	int dist[maxn][maxn][4];

	while(scanf("%d %d",&n,&m),(n||m)){
		for(i=0;i<=n;i++){
			for(j=0;j<=m;j++){
				peta1[i][j] = 0;
			}
			
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(i=1;i<=n-1;i++){
			for(j=1;j<=m-1;j++){
				peta1[i][j] = (a[i-1][j-1] || a[i-1][j] || a[i][j-1] || a[i][j]);
			}
		}
		

		int r1,c1,r2,c2;
		string posisi;
		scanf("%d %d %d %d",&r1,&c1,&r2,&c2); cin>>posisi;
		if(peta1[r1][c1]==1 || peta1[r2][c2]==1){printf("-1\n"); continue;}
		//if(!((r1>=0 && r1<n && c1>=0 && c1<m) && (r2>=0 && r2<n && c2>=0 && c2<m))){printf("-1\n"); continue;}
		/*printf("peta:\n");
		for(i=0;i<=n;i++){
			for(j=0;j<=m;j++){
				if(j){printf(" ");}
				printf("%d",peta1[i][j]);
				//if((i==r1 && j==c1) || (i==r2 && j==c2)){printf("t");}
			}
			printf("\n");
		}
		printf("asli\n");
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(j){printf(" ");}
				printf("%d",a[i][j]);
				//if((i==r1 && j==c1) || (i==r2 && j==c2)){printf("t");}
			}
			printf("\n");
		}*/
		int idx; 
		if(posisi=="north"){idx = 0;}
		else if(posisi=="east"){idx = 1;}
		else if(posisi=="south"){idx=2;}
		else{idx = 3;}
		//inisialisasi
		for(i=0;i<=n;i++){
			for(j=0;j<=m;j++){
				for(k=0;k<4;k++){
					dist[i][j][k] = inf;
				}
			}
		}
		queue<iii> q; q.push(make_pair(ii(r1,c1),idx)); dist[r1][c1][idx] = 0;

		while(!q.empty()){
			iii front = q.front(); q.pop();
			int r = front.first.first, c = front.first.second, arah = front.second;
			//printf("front r: %d c: %d arah: %d dist: %d\n",r,c,arah,dist[r][c][arah]);
			//menghadap dulu ke kiri kanan
			int idx1 = (arah-1)<0? 3:arah-1;
			int idx2 = (arah+1)>3? 0:arah+1;
			//printf("ditambahin dulu yang samping\n");
			if(dist[r][c][idx1]==inf){

				dist[r][c][idx1] = dist[r][c][arah] + 1; q.push(make_pair(ii(r,c),idx1));
				//printf("ke kanan yang dipush: r: %d c: %d idx1: %d dist: %d\n",r,c,idx1, dist[r][c][idx1]);
				//printf("yang dipush: %d %d\n", );
			}
			if(dist[r][c][idx2]==inf){
				dist[r][c][idx2] = dist[r][c][arah] + 1; q.push(make_pair(ii(r,c),idx2));
				//printf("yang dipush: r: %d c: %d idx1: %d dist: %d\n",r,c,idx2, dist[r][c][idx2]);
			}
			//kalo maju
			//printf("arah: %d\n",arah);
			bool ketemu = false;
			for(i=1;i<=3;i++){
				//printf("i: %d\n",i);
				int row = r, col = c;
				if(arah==0){row = r - i;}
				else if(arah==1){col = c + i;}
				else if(arah==2){row = r + i;}
				else if(arah==3){col = c - i;}
				// printf("row jd: %d col jd: %d\n",row,col);
				if(row>0 && row<n && col>0 && col<m){
					// printf("a[%d][%d]: %d\n",row,col,a[row][col]);
					if(peta1[row][col]==1){break;}//sudah nabrak obstable
					
					if(dist[row][col][arah]==inf){
						dist[row][col][arah] = dist[r][c][arah] + 1;
						q.push(make_pair(ii(row,col),arah));
						if(row==r2 && col==c2){
							//printf("ketemu\n");
							ketemu = true; break;
						}
						// printf("yang dipush: row: %d col: %d arah: %d dist: %d\n",row,col,arah, dist[row][col][arah]);
					}
					
					
				}
			}
			if(ketemu){break;}
		}
		/*printf("dist:\n");
		for(i=0;i<=n;i++){
			for(j=0;j<=m;j++){
				printf("i: %d j: %d\n",i,j);
				for(k=0;k<4;k++){
					if(k){printf(" ");}
					printf("%d",dist[i][j][k]);	
				}
				printf("\n");
				
				
			}
			
		}*/
		int ans = inf;
		for(i=0;i<4;i++){
			ans = min(ans,dist[r2][c2][i]);
		}
		if(ans==inf){printf("-1\n");}
		else{printf("%d\n",ans);}
	}
	return 0;
}