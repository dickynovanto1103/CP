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

int n,k;

int cnt = 0;
vector<vi> listAns;
bool foundAns = false;
int ans[51][51];

void find(int idx, int sum, vector<int> v) {
	int i,j;
	if(idx == n){
		if(sum == k) {
			listAns.pb(v);
		}
		
		return;
	}
	for(i=1;i<=n;i++){
		if(sum + i <= k){
			v.pb(i);
			find(idx+1, sum + i, v);
			v.pop_back();
		}
	}
}

ii findNext(int i, int j){
	if(j < (n-1)){return ii(i, j+1);}
	return ii(i+1, 0);
}

bool canCsp(int i, int j, vector<vector<bool> > rowDone, vector<vector<bool> > colDone) {
	// printf("i: %d j: %d\n",i,j);
	if(i == (n-1) && j == (n-1)){return true;}
	if(ans[i][j] == 0){
		// printf("i: %d j: %d ans 0\n",i,j);
		for(int k=1;k<=n;k++){
			if(rowDone[i][k] || colDone[j][k]){continue;}
			ans[i][j] = k;
			rowDone[i][k] = true; colDone[j][k] = true;
			ii next = findNext(i,j);
			bool can = canCsp(next.first, next.second, rowDone, colDone);
			if(!can) {
				rowDone[i][k] = false; colDone[j][k] = false;
				ans[i][j] = 0;
				continue;
			}
			return can;
		}
		//if reach end of loop, then the can value is false, then canCsp = false
		return false;
	} else {
		// printf("i: %d j: %d ans != 0\n",i,j);
		ii next = findNext(i, j);
		// printf("next: %d %d\n",next.first, next.second);
		return canCsp(next.first, next.second, rowDone, colDone);
	}
}

bool tryComb() {
	int i,j;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			ans[i][j] = 0;
		}
	}
	int ukuranListAns = listAns.size();
	// printf("%d\n",ukuranListAns);
	for(i=0;i<ukuranListAns;i++){
		// printf("case %d\n",i);
		for(j=0;j<n;j++){
			ans[j][j] = listAns[i][j];
			// printf("%d ",listAns[i][j]);
		}
		// printf("\n");
		vector<vector<bool> > rowDone, colDone;
		rowDone.assign(6, vector<bool>()); colDone.assign(6, vector<bool>());
		for(j=0;j<n;j++){
			for(int k=0;k<=n;k++){
				rowDone[j].pb(false);
				colDone[j].pb(false);
			}
			
		}
		for(j=0;j<n;j++){
			rowDone[j][ans[j][j]] = true;
			colDone[j][ans[j][j]] = true;
		}
		if(canCsp(0,0,rowDone, colDone)){
			return true;
		}
	}
	return false;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		listAns.clear();
		scanf("%d %d",&n,&k);
		vi v;
		cnt = 0;
		find(0,0,v);
		if(tryComb()){
			printf("POSSIBLE\n");
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(j){printf(" ");}
					printf("%d",ans[i][j]);
				}
				printf("\n");
			}
			continue;
		}else {
			printf("IMPOSSIBLE\n");
		}
		// printf("%d %d cnt: %d\n",n,k,cnt);
	}
	return 0;
};