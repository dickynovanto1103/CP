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

const int maxn = 1001;

string kata[maxn];
int grundy[maxn][maxn];

int dx[]={0,-1,-1};
int dy[]={-1,-1,0};

int main(){
	int n,i,j,k;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){cin>>kata[i];}
	
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				set<int> s;
				for(k=0;k<3;k++){
					int xbaru = i+dx[k], ybaru = j+dy[k];
					if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<n){
						if(kata[xbaru][ybaru]!='X'){
							s.insert(grundy[xbaru][ybaru]);
						}
					}
				}
				k=0;
				while(true){
					if(s.count(k)==0){
						grundy[i][j] = k;
						break;
					}
					k++;
				}			
			}
		}
		//mencari grundy total
		int tot = 0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(kata[i][j]=='K'){tot^=grundy[i][j];}
			}
		}
		//mencari banyak jalan
		if(tot==0){printf("LOSE\n"); continue;}
		int ways = 0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(kata[i][j]=='K'){//mau dipindahin
					int bil = tot^grundy[i][j];
					for(k=0;k<3;k++){
						int xbaru = i+dx[k], ybaru = j+dy[k];
						if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<n){
							if(kata[xbaru][ybaru]!='X' && grundy[xbaru][ybaru]==bil){
								ways++;
							}
						}
					}
				}
			}
		}	
		printf("WIN %d\n",ways);
	}
	return 0;
};
