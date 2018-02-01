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
typedef pair<char,int> ii;
typedef vector<ii> vii;

string kata[55];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int floodFill(int x, int y, char kar){
	kata[x][y] = '.';
	int ans = 1;
	for(int i=0;i<4;i++){
		int xbaru = x+dx[i], ybaru = y+dy[i];
		if(kata[xbaru][ybaru]==kar){
			ans+=floodFill(xbaru,ybaru,kar);
		}
	}
	return ans;
}

bool cmp(ii a, ii b){
	if(a.second==b.second){return a.first<b.first;}
	return a.second > b.second;
}

int main(){
	int r,c,i,j;
	
	int test = 1;
	while(scanf("%d %d",&r,&c),(r||c)){
		vii listPasangan;
		printf("Problem %d:\n",test++);
		for(i=0;i<r;i++){cin>>kata[i];}
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				char kar = kata[i][j];
				if(kar!='.'){
					int hasil = floodFill(i,j,kar);
					listPasangan.pb(ii(kar,hasil));
				}
			}
		}
		sort(listPasangan.begin(),listPasangan.end(),cmp);
		int ukuran = listPasangan.size();
		for(i=0;i<ukuran;i++){
			ii ans = listPasangan[i];
			printf("%c %d\n",ans.first,ans.second);
		}
	}
	
	return 0;
};