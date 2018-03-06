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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e6;
int numDiv[maxn + 4];

void getNumDiv(int n){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j+=i){
			numDiv[j]++;
		}
	}
}

vector<vi> AdjList;

int main(){
	int i,j;
	getNumDiv(maxn);
	
	AdjList.assign(1000002,vi());
	// printf("test\n");
	for(i=1;i<=maxn;i++){
		AdjList[numDiv[i]].pb(i);
	}

	// for(i=1;i<=5;i++){
	// 	printf("node %d:",i);
	// 	for(j=0;j<AdjList[i].size();j++){
	// 		if(j){printf(" ");}
	// 		printf("%d",AdjList[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("test2\n");
	int tc,a,b,c;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d %d",&a,&b,&c);
		if(AdjList[c].empty()){printf("0\n"); continue;}
		int idxAwal = lower_bound(AdjList[c].begin(), AdjList[c].end(), a) - AdjList[c].begin();
		int idxAkhir = upper_bound(AdjList[c].begin(), AdjList[c].end(), b) - AdjList[c].begin();
		printf("%d\n",idxAkhir-idxAwal);
	}

	return 0;
};