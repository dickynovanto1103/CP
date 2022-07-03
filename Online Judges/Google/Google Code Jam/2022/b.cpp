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

const int MAX = 1000000;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d:", tt);
		int a[4][4];
		for(i=0;i<3;i++){
			for(j=0;j<4;j++){
				scanf("%d",&a[i][j]);
			}
		}
		int arrMin[4];
		int sum = 0;
		for(int j=0;j<4;j++){
			int minim = inf;
			for(int i=0;i<3;i++){
				minim = min(minim, a[i][j]);
			}
			arrMin[j] = minim;
			sum += minim;
		}

		if(sum < MAX){
			printf(" IMPOSSIBLE\n");
			continue;
		}

		int selisih = sum - MAX;
		int sumNow = 0;
		for(int i=0;i<4;i++) {
			int minim = min(arrMin[i], selisih);
			arrMin[i] -= minim;
			selisih -= minim;
			printf(" %d", arrMin[i]);
			sumNow += arrMin[i];
		}
		assert(sumNow == MAX);
		puts("");
	}
	
	return 0;
};