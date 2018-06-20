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

const int maxn = 1e3 + 3;

int dp[maxn][maxn];
string kata[maxn];
int dx[] = {-1,-1,0};
int dy[] = {0,-1,-1};

void processWinningStates(int n) {
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			char kar = kata[i][j];
			if(kar=='X'){continue;}
			set<int> s;
			for(int k=0;k<3;k++){
				int xbaru = i + dx[k], ybaru = j+dy[k];
				if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<n){
					if(kata[xbaru][ybaru] == '.' || kata[xbaru][ybaru] == 'K') {
						s.insert(dp[xbaru][ybaru]);	
					}
				}
			}
			for(int k=0;;k++){
				if(!s.count(k)){
					dp[i][j] = k;
					break;
				}
			}
		}
	}
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			cin>>kata[i];
		}
		processWinningStates(n);
		
		
		int hasilXor = 0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				char kar = kata[i][j];
				if(kar=='K'){
					hasilXor^=dp[i][j];
				}
			}
		}
		
		if(hasilXor==0){
			printf("LOSE\n");
		}else{
			int cnt = 0;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					char kar = kata[i][j];
					if(kar=='K'){
						int xorBaru = hasilXor ^ dp[i][j];
						for(int k=0;k<3;k++){
							int xbaru = i+dx[k], ybaru = j+dy[k];
							if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<n){
								if(kata[xbaru][ybaru] == 'X'){continue;}
								int nilai = xorBaru^dp[xbaru][ybaru];
								if(nilai==0){cnt++;}
							}
						}
					}
				}
			}
			printf("WIN %d\n",cnt);
		}
		
	}
	return 0;
};