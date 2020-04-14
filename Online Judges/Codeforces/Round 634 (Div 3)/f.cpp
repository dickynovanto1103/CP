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

string pet[1000001];
string dir[1000001];

const int LOGN = 24;
const int LANGKAH = 1000001;

int n,m;

int nextIdx(int now, char dir) {
	if(dir == 'U'){
		now -= m;
	}else if(dir == 'L') {
		now--;
	}else if(dir == 'R') {
		now++;
	}else{
		now += m;
	}
	return now;
}

int convert(int x, int y) {
	return x*m + y;
}

int nxt[LOGN][1000001];

int cntVisit[1000001];
bool isFromBlack[1000001];

int main(){
	int tc,i,j;
	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++){cin>>pet[i];}
		for(i=0;i<n;i++){cin>>dir[i];}
		for(int t=0;t<LOGN;t++){
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					int koor = convert(i,j);
					cntVisit[koor] = 0;
					isFromBlack[koor] = false;
					if(t == 0){
						nxt[0][koor] = nextIdx(koor, dir[i][j]);
					}else{
						nxt[t][koor] = nxt[t-1][nxt[t-1][koor]];
					}
				}
			}
		}
		int cnt = 0, cntBlack = 0;		
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				int koor = convert(i,j);
				int final = koor;
				for(int k=0;k<LOGN;k++){
					if((1<<k) & LANGKAH) {
						final = nxt[k][final];
					}
				}
				if(pet[i][j] == '0'){
					if(!isFromBlack[final]){cntBlack++;}
					isFromBlack[final] = true;
				}
				cntVisit[final]++;
				if(cntVisit[final] == 1){cnt++;}
			}
		}
		printf("%d %d\n",cnt, cntBlack);
	}
	return 0;
};