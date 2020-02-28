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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int h,w;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int cnt[5];
string kata[550];

int getSur(int r, int c) {
	int i,j;
	int ans = 0;
	vi listBil;
	for(i=0;i<4;i++){
		int x = r + dx[i], y = c + dy[i];
		if(x >= 0 && x < h && y >= 0 && y < w) {
			if(kata[x][y] == '*'){ans++; listBil.pb(i);}
		}
	}
	if(ans == 2){
		if(abs(listBil[0] - listBil[1]) == 2){return ans;}
		else{printf("NO\n"); exit(0);}
	}
	return ans;
}

int main(){
	int i,j;
	scanf("%d %d",&h,&w);
	
	for(i=0;i<h;i++){
		cin>>kata[i];
	}
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(kata[i][j] == '*'){
				cnt[getSur(i,j)]++;
			}
		}
	}
	if(cnt[1] == 4 && cnt[3] == 0 && cnt[4] == 1 && cnt[0]==0) {
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
};