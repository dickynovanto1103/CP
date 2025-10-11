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

bool isLeapYear(int y) {
	if(y % 400 == 0) {return true;}
	if(y % 100 == 0) {return false;}
	return y % 4 == 0; 
}

void solve(){
	int d,m,y, qy;
	scanf("%d %d %d %d",&d,&m,&y,&qy);
	if(d == 29 && m == 2) {
		int cnt = 0;
		for(int i=y+1;i<=qy;i++){
			if(isLeapYear(i)){
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}else{
		printf("%d\n", qy-y);
	}
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case %d: ",tt);
		solve();
	}

	return 0;
};