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

int main(){
	int n,i,j;
	scanf("%d",&n);

	int cnt[100010];
	memset(cnt, 0, sizeof cnt);
	for(int i=0;i<4*n-1;i++){
		int bil;
		scanf("%d",&bil);
		cnt[bil]++;
	}
	for(int i=1;i<=n;i++){
		if(cnt[i] == 3){
			printf("%d\n", i);
			return 0;
		}
	}
	
	assert(false);
	return 0;
};