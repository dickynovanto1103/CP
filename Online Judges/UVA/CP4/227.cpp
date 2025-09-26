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

int tt = 1;

void solve(){
	string puzzle[5];
	while(getline(cin, puzzle[0]) && puzzle[0] != "Z") {
		if(tt > 1) {puts("");}
		printf("Puzzle #%d:\n", tt++);
		for(int i=1;i<5;i++){
			getline(cin, puzzle[i]);
		}

		string moves;
		string move;
		while(cin>>move) {
			if(move[move.size() - 1] == '0'){
				move.pop_back();
				moves += move;
				break;
			}else{
				moves += move;
			}
		}
		getline(cin, move); //just dummy;
		ii posBlank = ii(-1,-1);
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(puzzle[i][j] == ' '){
					posBlank = ii(i,j);
					break;
				}
			}
		}

		bool valid = true;
		for(char ch: moves){
			int r = posBlank.first, c = posBlank.second;
			if(ch == 'A'){
				if(r == 0) {
					valid = false;
					break;
				}else{
					swap(puzzle[r][c], puzzle[r-1][c]);
				}
				posBlank.first--;
			}else if(ch == 'B') {
				if(r == 4) {
					valid = false;
					break;
				}

				swap(puzzle[r][c], puzzle[r+1][c]);
				posBlank.first++;
			}else if(ch == 'L') {
				if(c == 0) {
					valid = false;
					break;
				}

				swap(puzzle[r][c], puzzle[r][c-1]);
				posBlank.second--;
			}else{
				if(c == 4) {
					valid = false;
				}

				swap(puzzle[r][c], puzzle[r][c+1]);
				posBlank.second++;
			}
		}

		if(!valid) {
			puts("This puzzle has no final configuration.");
			continue;
		}

		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(j){printf(" ");}
				printf("%c", puzzle[i][j]);
			}
			puts("");
		}
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};