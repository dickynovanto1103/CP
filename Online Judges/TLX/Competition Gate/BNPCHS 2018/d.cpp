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
typedef vector<ii> vii;

const int maxn = 810;

char kata[maxn][maxn];
char occupie[maxn][maxn];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n;

bool isValidLebah(int x, int y){
	return x>=0 && x<n && y>=0 && y<n && occupie[x][y]!='#' && occupie[x][y]!='@';
}

bool isValidBear(int x, int y){
	return x>=0 && x<n && y>=0 && y<n && occupie[x][y]!='#' && occupie[x][y]!='H';
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
			// printf("kiri: %d kanan: %d\n",kiri,kanan);
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
			// printf("temp: %d\n",temp);
			while(!q.empty()){
				int ukuranQ = q.size();

				if(temp == 0){break;}
				while(ukuranQ--){
					ii front = q.front(); q.pop();
					int x = front.first, y = front.second;
					for(i=0;i<4;i++){
						int xbaru = x + dx[i], ybaru = y + dy[i];
						if(isValidLebah(xbaru,ybaru)){
							if(occupie[xbaru][ybaru] == 'H'){continue;}
							occupie[xbaru][ybaru] = 'H';
							q.push(ii(xbaru,ybaru));
						}
					}
				}
				temp--;
				if(temp == 0){break;}
				
			}
			// printf("peta\n");
			// for(i=0;i<n;i++){
			// 	for(j=0;j<n;j++){
			// 		printf("%c",occupie[i][j]);
			// 	}
			// 	printf("\n");
			// }
			// printf("temp: %d\n",temp);
			if(temp){//bahkan udah penuh dengan lebah
				kanan = mid-1;
				continue;
			}
			if(!isValidBear(koorBear.first,koorBear.second)){
				kanan = mid-1;
				continue;
			}
			
			bool bisaKeRumah = false;
			//gerak lebah dulu baru gerak bear
			queue<ii> qBear;
			qBear.push(koorBear);
			while(true){
				if(!qBear.empty()){
					int banyakLangkah = k;
					int ukuranBear = qBear.size();
					while(ukuranBear--){
						while(banyakLangkah--){
							if(qBear.empty()){break;}
							ii front = qBear.front(); qBear.pop();

							int x = front.first, y = front.second;
							if(!isValidBear(x,y)){continue;} //sudah dioccupy sama lebah lain
							for(i=0;i<4;i++){
								int xbaru = x + dx[i], ybaru = y + dy[i];
								if(isValidBear(xbaru, ybaru)){
									if(ii(xbaru,ybaru) == koorRumah){bisaKeRumah = true; break;}
									if(occupie[xbaru][ybaru] == 'K'){continue;}
									occupie[xbaru][ybaru] = 'K';
									// printf("occupie: %d %d dengan K\n",xbaru,ybaru);
									qBear.push(ii(xbaru,ybaru));
								}
							}
							if(bisaKeRumah){break;}
						}
						if(qBear.empty()){break;}
						if(bisaKeRumah){break;}
					}
					
				}else{
					break;
				}

				if(bisaKeRumah){break;}
				if(!q.empty()){
					ii front = q.front(); q.pop();
					int x = front.first, y = front.second;
					
					for(i=0;i<4;i++){
						int xbaru = x + dx[i], ybaru = y + dy[i];
						if(isValidLebah(xbaru, ybaru)){
							if(occupie[xbaru][ybaru] == 'H'){continue;}
							occupie[xbaru][ybaru] = 'H';
							// printf("occupie: %d %d dengan H\n",xbaru,ybaru);
							q.push(ii(xbaru,ybaru));
						}
					}
				}
				// printf("halo\n");
			}
			if(bisaKeRumah){
				ans = mid;
				// printf("diassign ans: %d\n",ans);
				kiri = mid+1;
			}else{
				kanan = mid-1;
			}
			
		}
		printf("%d\n",ans);
	}
	return 0;
};