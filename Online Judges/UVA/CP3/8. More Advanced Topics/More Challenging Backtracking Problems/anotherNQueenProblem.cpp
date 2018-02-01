#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

string kata[20];
ll ans;
map<ll,int> mapper;
void backtrack(int rw, int ld, int rd, int col, int ok){
	if(rw==ok){ans++; return;}
	int pos = ok & (~(rw|ld|rd));
	while(pos){
		int p = pos & -pos;//LSOne
		pos-=p;
		int row = mapper[p];
		if(kata[row][col]=='.'){
			backtrack(rw|p,(ld|p) << 1, (rd|p)>>1,col+1,ok);	
		}
	}
}

int main() {
	int n,i,j,test=1;
	for(i=0;i<16;i++){
		mapper[(ll)pow(2,i)] = i;
	}
	while(scanf("%d",&n),n){
		ans = 0;
		printf("Case %d: ",test++);
		for(i=0;i<n;i++){cin>>kata[i];}
		int ok = (1<<n) - 1;
		backtrack(0,0,0,0,ok);
		printf("%lld\n",ans);
	}
	return 0;
}