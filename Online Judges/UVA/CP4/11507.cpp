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
	int l;
	while(scanf("%d\n",&l), l) {
		// printf("l: %d\n",l);
		char command[4];
		string pos = "+x";
		for(int i=0;i<l-1;i++){
			// printf("halo l: %d\n", l);
			scanf("%s", command);
			// printf("i: %d command: %s l: %d\n",i, command, l);
			if(strcmp(command, "No") == 0) {
				continue;
			}else if(strcmp(command, "+y") == 0) {
				if(pos == "+x") {
					pos = "+y";
				}else if(pos == "-x") {
					pos = "-y";
				}else if(pos == "+y") {
					pos = "-x";
				}else if(pos == "-y") {
					pos = "+x";
				}
			}else if(strcmp(command, "-y") == 0) {
				if(pos == "+x") {
					pos = "-y";
				}else if(pos == "-x") {
					pos = "+y";
				}else if(pos == "+y") {
					pos = "+x";
				}else if(pos == "-y") {
					pos = "-x";
				}
			}else if(strcmp(command, "+z") == 0) {
				if(pos == "+x") {
					pos = "+z";
				}else if(pos == "-x") {
					pos = "-z";
				}else if(pos == "+z") {
					pos = "-x";
				}else if(pos == "-z") {
					pos = "+x";
				}
			}else if(strcmp(command, "-z") == 0) {
				if(pos == "+x") {
					pos = "-z";
				}else if(pos == "-x") {
					pos = "+z";
				}else if(pos == "+z") {
					pos = "+x";
				}else if(pos == "-z") {
					pos = "-x";
				}
			}
			
		}

		cout<<pos<<endl;
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