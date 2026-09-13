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
	string s;
	cin>>s;
	map<ii, int> left, right;
	int cntA = 0, cntB = 0;
	for(int i=0;i<n;i++){
		if(s[i] == 'a'){cntA++;}
		else{cntB++;}

		left[ii(cntA, cntB)] = i;
	}

	cntA = 0, cntB = 0;
	for(int i=n-1;i>=0;i--){
		if(s[i] == 'a'){cntA++;}
		else{cntB++;}

		right[ii(cntA, cntB)] = i;
	}

	cntA = 0, cntB = 0;
	int ans = n;
	for(int i=0;i<n;i++){
		if(s[i] == 'a'){cntA++;}
		else{cntB++;}

		int expectedA = 0, expectedB = 0;
		if(cntA > cntB){
			expectedB = cntA - cntB;
		}else if (cntA < cntB){
			expectedA = cntB - cntA;
		}

		if(expectedA == 0 && expectedB == 0) {
			ans = min(ans, n - (cntA + cntB));
		}

		if(right.find(ii(expectedA, expectedB)) == right.end()) {
			continue;	
		}

		int idxRight = right[ii(expectedA, expectedB)];
		
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