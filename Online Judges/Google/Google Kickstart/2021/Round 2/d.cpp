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

string actual[11], expected[11], temp[11];
int r, c;

bool canSwap(int a, int b, int c, int d){
	return (actual[a][b] == expected[c][d] && actual[c][d] == expected[a][b]) && (actual[a][b] != actual[c][d]);
}

int swapHorizontal() {
	int ans = 0,i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c-1;j++){
			if(canSwap(i, j, i, j+1)) {
				// printf("can swap idx: %d %d and %d %d\n", i,j,i,j+1);
				swap(actual[i][j], actual[i][j+1]);
				ans++;
			}
		}
	}
	return ans;
}

int swapVertical() {
	int ans = 0,i,j;
	for(j=0;j<c;j++){
		for(i=0;i<r-1;i++){
			if(canSwap(i, j, i+1, j)) {
				swap(actual[i][j], actual[i+1][j]);
				ans++;
			}
		}
	}
	return ans;
}

int flip() {
	int ans = 0, i,j;
	for(i=0;i<r;i++) {
		for(j=0;j<c;j++){
			if(actual[i][j] != expected[i][j]) {
				ans++;
			}
		}
	}
	return ans;
}

void resetActual() {
	int i,j;
	for(i=0;i<r;i++){
		actual[i] = temp[i];
	}
}

int main(){
	int tc,i,j,f, s;
	
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		scanf("%d %d %d %d",&r,&c,&f,&s);
		for(i=0;i<r;i++){
			cin>>actual[i];
			temp[i] = actual[i];
		}
		for(i=0;i<r;i++){
			cin>>expected[i];
		}

		//swap if found
		//find horizontally first
		int ans1 = flip();
		resetActual();
		int ans2 = swapHorizontal() + flip();
		resetActual(); 
		int ans3 = swapVertical() + flip();
		// printf("finalAns: %d\n", ans);
		// resetActual();
		printf("%d\n", min(ans1, min(ans2, ans3)));

	}
	
	return 0;
};