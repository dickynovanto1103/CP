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

const int maxn = 1e7 + 7;

int square[maxn];
int idxSquare[500];

int mat[6005][6005];

int getIdx(int idx, int nilai) {
	int kiri = 0, kanan = idx, mid, ans;
	// printf("kanan: %d nilai: %d\n",kanan,nilai);
	while(kiri <= kanan){
		mid = (kiri + kanan) / 2;
		if(square[mid] <= nilai) {
			ans = mid;
			kiri = mid+1;
		}else{
			kanan = mid-1;
		}
	}
	// printf("ans: %d\n",ans);
	return ans;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	memset(square, -1, sizeof square);
	memset(idxSquare, -1, sizeof idxSquare);
	
	int idx;
	for(i=0;i*i<maxn;i++){
		idxSquare[i*i] = i;
		square[i] = i*i;
		idx = i;
	}
	// printf("idx: %d\n",idx);
	int dx[] = {1,1,-1,-1};
	int dy[] = {1,-1,-1,1};

	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d:\n",tt);
		int n,m;
		scanf("%d %d",&n,&m);
		memset(mat, -1, sizeof mat);
		for(i=0;i<n;i++){
			int x,y,w;
			scanf("%d %d %d",&x,&y,&w);
			mat[x][y] = w;
		}
		ll last = 0;
		
		while(m--){
			int com, x,y,k,w;
			scanf("%d",&com);
			if(com == 1){
				scanf("%d %d %d",&x,&y,&w);
				x += last; x%=6000; x++;
				y += last; y%=6000; y++;

				mat[x][y] = w;
				// printf("x: %d y: %d mat: %d\n",x,y,mat[x][y]);
			}else if(com == 2){
				scanf("%d %d",&x,&y);
				x += last; x%=6000; x++;
				y += last; y%=6000; y++;

				mat[x][y] = -1;
			}else if(com == 3) {
				scanf("%d %d %d %d",&x,&y,&k,&w);
				x += last; x%=6000; x++;
				y += last; y%=6000; y++;
				//binser
				int indeks = getIdx(idx, k);
				// printf("indeks: %d\n",indeks);
				for(i=indeks;i>=0;i--){
					int bil1 = i;
					int jarak2 = k - square[i];
					int bil2 = idxSquare[jarak2];
					// printf("bil1: %d bil2: %d\n",bil1,bil2);
					if(bil2 == -1){continue;}
					else{
						//ada 4 kombinasi
						set<ii> s;
						for(j=0;j<4;j++){

							int xbaru = x + bil1*dx[j], ybaru = y + bil2*dy[j];	
							if(s.find(ii(xbaru,ybaru)) != s.end()){continue;}
							else{s.insert(ii(xbaru, ybaru));}
							if(xbaru >= 1 && xbaru<=6000 && ybaru >= 1 && ybaru<=6000) {
								if(mat[xbaru][ybaru] == -1){
									continue;
								}else{
									mat[xbaru][ybaru] += w;
								}
							}
						}
					}
				}
				//ditambah sebanyak w
			}else if(com == 4){
				scanf("%d %d %d",&x,&y,&k);
				x += last; x%=6000; x++;
				y += last; y%=6000; y++;

				int indeks = getIdx(idx, k);
				// printf("indeks: %d\n",indeks);
				ll ans = 0;
				for(i=indeks;i>=0;i--){
					int bil1 = i;
					int jarak2 = k - square[i];
					int bil2 = idxSquare[jarak2];
					// printf("bil1: %d bil2: %d\n",bil1,bil2);

					if(bil2 == -1){continue;}
					else{
						//ada 4 kombinasi
						set<ii> s;
						for(j=0;j<4;j++){
							int xbaru = x + bil1*dx[j], ybaru = y + bil2*dy[j];	
							if(s.find(ii(xbaru,ybaru)) != s.end()){continue;}
							else{s.insert(ii(xbaru, ybaru));}
							// printf("xbaru: %d ybaru: %d\n",xbaru, ybaru);
							if(xbaru >= 1 && xbaru<=6000 && ybaru >= 1 && ybaru<=6000) {
								if(mat[xbaru][ybaru] == -1){
									continue;
								}else{
									ans += mat[xbaru][ybaru];
								}
							}
						}
					}
				}
				last = ans;
				printf("%lld\n",ans);
			}
		}
	}
	

	return 0;
};