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

bool isSubSequence(vi big, vi small) {
	int idx = 0;
	for(int i=0;i<big.size();i++){
		if(idx < small.size() && small[idx] == big[i]) {
			idx++;
		}
	}

	return idx == small.size();
}

int main(){
	int n1, m1, n2, m2;
	scanf("%d %d",&n1,&m1);

	int a[11][11], b[11][11];
	vi big, small;
	for(int i=0;i<n1;i++){
		for(int j=0;j<m1;j++){
			scanf("%d",&a[i][j]);
			big.pb(a[i][j]);
		}
	}

	scanf("%d %d",&n2,&m2);
	for(int i=0;i<n2;i++){
		for(int j=0;j<m2;j++){
			scanf("%d",&b[i][j]);
			small.pb(b[i][j]);
		}
	}

	if(!isSubSequence(big, small)) {
		puts("No");
		return 0;
	}

	//check overlap big and small
	
	
	return 0;
};