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

int dist[26][26];
int jarak[26];
vector<vi> AdjList;

void bfs(int node){
	dist[node][node] = 0;
	fill(jarak,jarak+26,inf);
	queue<int> q;
	q.push(node);
	jarak[node] = 0;
	while(!q.empty()){
		int front = q.front(); q.pop();
		for(int i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			if(jarak[v]==inf){
				q.push(v);
				jarak[v] = jarak[front] + 1;
			}
		}
	}

	for(int i=0;i<26;i++){
		dist[node][i] = jarak[i];
	}
}

int main(){
	string a,b;
	cin>>a>>b;
	int i,j;
	AdjList.assign(26,vi());
	for(i=0;i<26;i++){
		string kata;
		cin>>kata;
		int pjg = kata.length();
		for(j=0;j<pjg;j++){
			char kar = kata[j];
			AdjList[i].pb(kar-'A');
		}
	}
	for(i=0;i<26;i++){
		for(j=0;j<26;j++){
			dist[i][j] = inf;
		}
	}

	for(i=0;i<26;i++){
		//bfs
		bfs(i);
	}

	// printf("dist\n");
	// for(i=0;i<26;i++){
	// 	printf("i %d:",i);
	// 	for(j=0;j<26;j++){
	// 		if(j){printf(" ");}
	// 		printf("%d",dist[i][j]);
	// 	}
	// 	printf("\n");
	// }

	int pjg = a.length();
	int sum = 0;
	for(i=0;i<pjg;i++){
		if(a[i]!=b[i]){
			int jarak = dist[a[i]-'A'][b[i]-'A'];
			if(jarak==inf){printf("IMPOSSIBLE\n"); return 0;}
			sum+=jarak;
		}
	}
	printf("%d\n",sum);
	return 0;
};