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
typedef pair<int,ii> iii;
typedef vector<ii> vii;

const int maxn = 810;

char kata[maxn][maxn];
char occupie[maxn][maxn];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n;

bool isValidLebah(int x, int y){
	return x>=0 && x<n && y>=0 && y<n && occupie[x][y]!='#' && occupie[x][y]!='@' && occupie[x][y] != 'H';
}

bool isValidBear(int x, int y){
	return x>=0 && x<n && y>=0 && y<n && occupie[x][y]!='#' && occupie[x][y]!='H' && occupie[x][y]!='K';
}

bool isRumah(int x, int y){
	return occupie[x][y] == '@';
}

int main(){
	int tc,i,j,k;
	scanf("%d",&tc);
	ii listKoorLebah[maxn*maxn];

	for(int tt=1;tt<=tc;tt++){
		printf("Kasus #%d: ",tt);
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){scanf("%s",kata[i]);}
		ii koorBear, koorRumah;
		int cntLebah = 0; 
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				char kar = kata[i][j];
				if(kar == 'H'){
					listKoorLebah[cntLebah] = ii(i,j);
					cntLebah++;
				}else if(kar == 'K'){
					koorBear = ii(i,j);
				}else if(kar == '@'){
					koorRumah = ii(i,j);
				}
			}
		}
		int kiri = 0, kanan = n*n, mid, ans = -1;
		
		while(kiri <= kanan){
			mid = (kiri + kanan)/2;
			queue<ii> q;
			
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					occupie[i][j] = kata[i][j];
				}
			}

			for(i=0;i<cntLebah;i++){
				ii koor = listKoorLebah[i];
				q.push(koor);
			}

			int temp = mid;
			for(i=0;i<temp;i++){
				int ukuran = q.size();
				for(int t = 0;t<ukuran;t++){
					ii front = q.front(); q.pop();
					int x = front.first, y = front.second;
					
					occupie[x][y] = 'H';
					for(j=0;j<4;j++){
						int xbaru = x + dx[j], ybaru = y + dy[j];
						if(isValidLebah(xbaru,ybaru)){
							q.push(ii(xbaru,ybaru));
							
							occupie[xbaru][ybaru] = 'H';
						}
					}
				}	
			}
			if(occupie[koorBear.first][koorBear.second] == 'H'){
				kanan = mid-1;
				continue;
			}
			queue<ii> qBear;
			qBear.push(koorBear);
			bool isBisaSampeRumah = false;
			bool isMasihAda = false;
			while(true){
				isMasihAda = false;
				for(i=0;i<k;i++){
					int ukuran = qBear.size();

					while(ukuran--){
						ii front = qBear.front(); qBear.pop();
						int x = front.first, y = front.second;
						if(occupie[x][y] == 'H'){
							continue;
						}
						isMasihAda = true;
						occupie[x][y] = 'K';
						for(j=0;j<4;j++){
							int xbaru = x + dx[j], ybaru = y + dy[j];
							if(isValidBear(xbaru, ybaru)){
								if(isRumah(xbaru,ybaru)){

									isBisaSampeRumah = true;
									break;
								}
								qBear.push(ii(xbaru,ybaru));
								occupie[xbaru][ybaru] = 'K';
							}
						}
						if(isBisaSampeRumah){break;}
					}
					if(isBisaSampeRumah){break;}
				}
				// printf("nilai isMasihAda: %d\n",isMasihAda);
				if(isBisaSampeRumah){break;}
				if(!isMasihAda){break;}
				int ukuran = q.size();
				while(ukuran--){
					ii front = q.front(); q.pop();
					int x = front.first, y = front.second;
					// printf("x sekarang: %d y sekarang: %d\n",x,y);
					occupie[x][y] = 'H';
					for(i=0;i<4;i++){
						int xbaru = x + dx[i], ybaru = y + dy[i];
						if(isValidLebah(xbaru,ybaru)){
							q.push(ii(xbaru,ybaru));
							occupie[xbaru][ybaru] = 'H';
							// printf("dipush %d %d\n",xbaru,ybaru);
						}
					}
				}
			}
			if(isBisaSampeRumah){
				ans = mid;
				kiri = mid+1;
				continue;
			}
			if(!isMasihAda){
				kanan = mid-1;
				continue;
			}


		}
		printf("%d\n",ans);
	}
	return 0;
};