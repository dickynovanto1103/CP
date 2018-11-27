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
typedef pair<ii,ii> iiii;
typedef vector<ii> vii;

int n;

bool isMenang(ii koor){
	return koor.second > n;
}

ii move(ii koorAwal){
	if(koorAwal.second % 2 == 0){
		koorAwal.first--;
	}else{
		koorAwal.first++;
	}
	if(koorAwal.first == 0){
		koorAwal.first = 1;
		koorAwal.second++;
	}else if(koorAwal.first > n){
		koorAwal.first = n;
		koorAwal.second++;
	}
	return koorAwal;
}

map<ii,ii> mapperSnake, mapperLadder, dp;

ii solve(ii pos){
	if(!dp.count(pos)){
		if(mapperSnake.count(pos)){
			dp[pos] = solve(mapperSnake[pos]);
		}
		else if(mapperLadder.count(pos)){
			dp[pos] = solve(mapperLadder[pos]);
		}
		else dp[pos] = pos;
	}
	return dp[pos];
}

int main(){
	int player, snake, ladder, roll;
	int i,j;
	scanf("%d %d",&n,&player);
	scanf("%d",&snake);
	for(i=0;i<snake;i++){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		mapperSnake[ii(x1,y1)] = ii(x2,y2);
	}
	scanf("%d",&ladder);
	for(i=0;i<ladder;i++){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		mapperLadder[ii(x1,y1)] = ii(x2,y2);
	}
	scanf("%d",&roll);
	ii posPlayer[15];
	for(i=0;i<player;i++){posPlayer[i] = ii(0,1);}
	int idx = 0;
	for(i=0;i<roll;i++){
		int satu,dua;
		scanf("%d %d",&satu,&dua);
		int tot = satu + dua;
		for(j=0;j<tot;j++){
			posPlayer[idx] = move(posPlayer[idx]);
			// printf("posPlayer[%d] jadi: %d %d\n",idx,posPlayer[idx].first,posPlayer[idx].second);
		}
		posPlayer[idx] = solve(posPlayer[idx]);
		// printf("posPlayer[%d] final jadi: %d %d\n",idx,posPlayer[idx].first,posPlayer[idx].second);

		idx++;
		idx%=player;
	}
	for(i=0;i<player;i++){
		printf("%d ",i+1);
		if(isMenang(posPlayer[i])){printf("winner\n");}
		else{printf("%d %d\n",posPlayer[i].first,posPlayer[i].second);}
	}
	return 0;
};