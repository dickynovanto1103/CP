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

int dx[]={-2,-2,0,2,2,0};
int dy[]={-1,1,2,1,-1,-2};

ii parent[201][201];
vector<string> listAns;
void print(int x, int y) {
	if(parent[x][y]==ii(-1,-1)){return;}
	int absis = parent[x][y].first, ordinat = parent[x][y].second;
	//printf("absis: %d ordinat: %d\n",absis,ordinat);
	
	

	if(absis==(x+2) && ordinat==(y+1)){listAns.pb("UL");}
	else if(absis==(x+2) && ordinat==(y-1)){listAns.pb("UR");}
	else if(absis==(x) && ordinat==(y-2)){listAns.pb("R");}
	else if(absis==(x-2) && ordinat==(y-1)){listAns.pb("LR");}
	else if(absis==(x-2) && ordinat==(y+1)){listAns.pb("LL");}
	else if(absis==(x) && ordinat==(y+2)){listAns.pb("L");}
	print(absis,ordinat);
}

int main(){
	int n;
	int dist[201][201];
	int i,j;
	int x1,y1,x2,y2;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			dist[i][j] = inf;
			parent[i][j] = ii(-1,-1);
		}
	}
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	dist[x1][y1] = 0;
	queue<ii> q;
	q.push(ii(x1,y1));
	while(!q.empty()){
		ii front = q.front(); q.pop();
		int x = front.first, y = front.second;
		for(i=0;i<6;i++){
			int xbaru = x+dx[i], ybaru = y+dy[i];
			if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<n) {
				if(dist[xbaru][ybaru]==inf){
					dist[xbaru][ybaru] = dist[x][y] + 1;
					parent[xbaru][ybaru] = ii(x,y);
					// if(i==0){parent[xbaru][ybaru]="UR";}
					// else if(i==1){parent[xbaru][ybaru]="R";}
					// else if(i==2){parent[xbaru][ybaru]="LR";}
					// else if(i==3){parent[xbaru][ybaru]="LL";}
					// else if(i==4){parent[xbaru][ybaru]="L";}
					// else if(i==5){parent[xbaru][ybaru]="UL";}
					q.push(ii(xbaru,ybaru));
				}
			}
		}
	}
	// for(i=0;i<n;i++){
	// 	for(j=0;j<n;j++){
	// 		if(j){printf(" ");}
	// 		if(dist[i][j]==inf){printf("-1");}
	// 		else{printf("%d",dist[i][j]);}
			
	// 	}
	// 	printf("\n");
	// }
	// for(i=0;i<n;i++){
	// 	for(j=0;j<n;j++){
	// 		printf("parent[%d][%d]: %d %d\n",i,j,parent[i][j].first,parent[i][j].second);
	// 	}
	// 	printf("\n");
	// }
	if(dist[x2][y2]==inf){
		printf("Impossible\n");
	}else{
		printf("%d\n",dist[x2][y2]);
		print(x2,y2);
		int ukuran = listAns.size();
		for(i=ukuran-1;i>=0;i--){
			if(i<ukuran-1){printf(" ");}
			cout<<listAns[i];
		}
		printf("\n");
	}

	return 0;
};