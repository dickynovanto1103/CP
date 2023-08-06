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
typedef pair<ii,ii> iiii;
typedef vector<ii> vii;

bool isUnder(ii koor, iiii sq) {
	bool isRowUnderSq = sq.first.first <= koor.first && koor.first <= sq.second.first;
	bool isColUnderSq = sq.first.second <= koor.second && koor.second <= sq.second.second;

	return isRowUnderSq && isColUnderSq;
}

int main(){
	int r, c;
	iiii list[] = {
		iiii(ii(1,1), ii(15, 15)),
		iiii(ii(3, 3), ii(13, 13)),
		iiii(ii(5, 5), ii(11, 11)),
		iiii(ii(7, 7), ii(9, 9)),
	};
	while(cin>>r>>c){
		bool found = false;
		for(iiii val: list) {
			if(r == val.first.first || r == val.second.first || c == val.first.second || c == val.second.second) {
				if(isUnder(ii(r, c), val)) {
					found = true;
					break;
				}
			}
		}

		if(found) puts("black");
		else puts("white");
	}
	
	return 0;
};