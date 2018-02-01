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
vi color;

int main(){
	int tc,i,j,v,e;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Scenario #%d:\n",tt);
		scanf("%d %d",&v,&e);
		AdjList.assign(v+1,vi()); color.assign(v+1,unvisited);
		int a,b;
		for(i=0;i<e;i++){scanf("%d %d",&a,&b); AdjList[a].pb(b); AdjList[b].pb(a);}
		bool valid = true;
		for(i=1;i<=v;i++){
			if(color[i]==unvisited){
				color[i] = 0;
				bool isBipartite = true;
				queue<int> q; q.push(i);
				while(!q.empty() && isBipartite){
					int front = q.front(); q.pop();
					for(j=0;j<AdjList[front].size();j++){
						int tetangga = AdjList[front][j];
						if(color[tetangga]==unvisited){
							color[tetangga] = 1 - color[front];
							q.push(tetangga);
						}else if(color[tetangga]==color[front]){
							isBipartite = false; break;
						}
					}
				}
				valid = valid && isBipartite;
				if(!valid){break;}
			}
		}
		if(valid){printf("No suspicious bugs found!\n");}
		else{printf("Suspicious bugs found!\n");}
	}
	return 0;
};