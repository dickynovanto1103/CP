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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;

const int maxn = 12;

void parse(const string& kata, int idx) {
	int num = 0;
	int pjg = kata.length();
	int i,j;
	for(i=0;i<pjg;i++){
		if(kata[i] == ' '){
			if(idx != num){
				AdjList[idx].pb(num);	
			}
			
			num = 0;
		}else{
			num *= 10;
			num += (kata[i] - '0');
		}
	}
	if(num != idx)
		AdjList[idx].pb(num);
}

int color[maxn];

bool isBipartite(int n){
	queue<int> q;
	color[n] = 0;
	q.push(n);

	int i,j;
	while(!q.empty()){
		int node = q.front(); q.pop();
		// printf("node: %d\n", node);
		for(i=0;i<AdjList[node].size();i++){
			int v = AdjList[node][i];
			if(color[v] == -1){
				color[v] = 1 - color[node];
				q.push(v);
			}else if(color[v] == color[node]){return false;}
		}
	}
	return true;
}

bool found = false;

bool isValid(int numNodes){
	int i,j;
	for(i=0;i<numNodes;i++){
		for(j=0;j<AdjList[i].size();j++){
			int v = AdjList[i][j];
			if(color[v] == color[i]){return false;}
		}
	}
	return true;
}

int ans = inf;
int counter = 0;
void generate(int idx, int n){
	int i,j;

	if(idx == n){
		// for(i=0;i<idx;i++){
		// 	printf("%d ",color[i]);	
		// }

		// printf("\n");
		counter++;
		if(isValid(n)){
			set<int> s;
			for(i=0;i<idx;i++){
				s.insert(color[i]);
				// printf("color[%d]: %d\n",i,color[i]);
			}
			ans = min(ans, (int)s.size());
		}
		return;
	}
	for(i=0;i<;i++){
		color[idx] = i;
		generate(idx+1,n);
	}
}

int main(){
	int n,i,j;
	scanf("%d\n",&n);
	AdjList.assign(maxn, vi());

	for(i=0;i<n;i++){
		string kata;
		getline(cin, kata);
		parse(kata, i);
		// printf("i: %d->",i);
		// for(j=0;j<AdjList[i].size();j++){
		// 	printf("%d ",AdjList[i][j]);
		// }
		// printf("\n");
	}
	// if(isBipartite(0)){printf("2\n"); return 0;}
	color[0] = 0;
	generate(1,n);
	// printf("counter: %d\n",counter);
	// if(ans == inf){assert(false);}
	printf("%d\n",ans);
	// if(found){printf("%d\n",ans);}
	// else{
	// 	if(n != 4){assert(false);}
	// 	printf("4\n");

	// }
	return 0;
};