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

vector<vi> AdjList;
const int maxn = 10005;
int memo[maxn][2];
int a[maxn];

int solve(int node, int nilaiParent){
	if(memo[node][nilaiParent]!=-1){return memo[node][nilaiParent];}
	//klo misal bapaknya 0..cari tau minimal klo nodenya berubah atau tetap
	int sum = 0;
	//int minim = inf;
	int i;
	if(nilaiParent==0){
		int jawab1 = 1, jawab2 = 0;
		for(i=0;i<AdjList[node].size();i++){
			int v = AdjList[node][i];
			int ans1 = solve(v,1-a[node]);//klo ngubah
			//int ans2 = solve(v,0);//klo tetep
			jawab1+=ans1;
		}
		for(i=0;i<AdjList[node].size();i++){
			int v = AdjList[node][i];
			int ans = solve(v,a[node]);
			jawab2+=ans;
		}
		sum=min(jawab1,jawab2);
		/*if(a[node]==0){
			//mau ngubah nilai di node
			int jawal1 = 0;
			for(i=0;i<AdjList[node].size();i++){
				int v = AdjList[node][i];
				int ans1 = 1+solve(v,1);//klo ngubah
				//int ans2 = solve(v,0);//klo tetep
				jawab1+=ans1;
			}
			//ga ngubah
			int jawab2 = 0;
			for(i=0;i<AdjList[node].size();i++){
				int v = AdjList[node][i];
				int ans = solve(v,0);
				jawab2+=ans;
			}
			sum+=min(jawab1,jawab2);
		}else{

		}*/
		
	}else{
		if(a[node]==0){sum++;}//nilai node ini harus 1 kalo nilai parent 0
		for(i=0;i<AdjList[node].size();i++){
			int v = AdjList[node][i];
			int ans2 = solve(v,1);//klo tetep
			sum+=ans2;
		}
	}
	return memo[node][nilaiParent] = sum;
}

int main(){
	int tc,n,i;
	
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		AdjList.assign(n+1,vi());
		for(i=1;i<=n;i++){
			int parent;
			scanf("%d",&parent);
			AdjList[parent].pb(i);
		}
		for(i=1;i<=n;i++){
			int bil;
			scanf("%d",&bil);
			a[i] = bil;
		}
		memset(memo,-1,sizeof memo);
		int ans = solve(1,0);//root nya 1..dan anggep nilai parentnya 0..karena pasti bener apapun nilai di 1
		printf("%d\n",ans);
		// printf("tabel:\n");
		// for(i=1;i<=n;i++){
		// 	for(int j=0;j<2;j++){
		// 		if(j){printf(" ");}
		// 		printf("%d",memo[i][j]);
		// 	}
		// 	printf("\n");
		// }
	}
	return 0;
};