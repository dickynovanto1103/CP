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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int snakesOrLadder[102];
int pos[1000001];

void solve(){
	memset(snakesOrLadder, -1, sizeof snakesOrLadder);
	int numPlayer, numSnakesOrLadders, numDieRoll;
	scanf("%d %d %d",&numPlayer,&numSnakesOrLadders, &numDieRoll);
	for(int i=0;i<numSnakesOrLadders;i++){
		int head, tail;
		scanf("%d %d",&head,&tail);
		snakesOrLadder[head] = tail;
	}
	for(int i=0;i<numPlayer;i++){
		pos[i] = 1;
	}

	int playerIdx = 0;
	int isEnded = false;
	for(int i=0;i<numDieRoll;i++){
		int dieRoll;
		scanf("%d",&dieRoll);
		if(isEnded) {continue;}
		pos[playerIdx] += dieRoll;
		if(snakesOrLadder[pos[playerIdx]] != -1) {
			pos[playerIdx] = snakesOrLadder[pos[playerIdx]];
		}
		if(pos[playerIdx] >= 100) {
			pos[playerIdx] = 100;
			isEnded = true;
			continue;
		}

		playerIdx++;
		playerIdx %= numPlayer;
	}

	for(int i=0;i<numPlayer;i++){
		printf("Position of player %d is %d.\n", i+1, pos[i]);
	}
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};