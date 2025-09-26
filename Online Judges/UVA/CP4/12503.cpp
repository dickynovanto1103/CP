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

void solve(){
	int n;
	scanf("%d",&n);
	int pos = 0;
	vector<int> instructions(n+1);
	for(int i=0;i<n;i++){
		char instruction[10];
		scanf("%s", instruction);
		// printf("instruction: %s\n", instruction);
		if(strcmp(instruction, "LEFT") == 0) {
			pos--;
			instructions[i] = -1;
			// printf("LEFT i: %d instruction: %d\n", i, instruction[i]);
		}else if(strcmp(instruction, "RIGHT") == 0){
			pos++;
			instructions[i] = 1;
			// printf("RIGHT i: %d instruction: %d\n", i, instruction[i]);
		} else {
			char dummy[3];
			int idx;

			scanf("%s %d",dummy, &idx);
			idx--;
			// printf("dummy: %s, idx: %d, instruction: %d\n", dummy, idx, instruction[idx]);
			pos += instructions[idx];
			// printf("instruction that is copied is from idx: %d, val: %d\n", idx, instruction[idx]);
			instructions[i] = instructions[idx];
		}
	}
	printf("%d\n", pos);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};