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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;

map<ii, int> mapper;

const int maxn = 2e5 + 5;

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	set<ii> s;
	AdjList.assign(n+1, vi());
	int x[maxn], y[maxn];
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		x[i] = a, y[i] = b;
		int minim = min(a,b), maks = max(a,b);
		mapper[ii(minim, maks)] = i;
		AdjList[a].pb(b); AdjList[b].pb(a);
		s.insert(ii(minim, maks));
	}

	bool dir[200010];
	int stat[200010];
	memset(stat, -1, sizeof stat);
	queue<int> q;
	q.push(1);
	int keluar = false;
	stat[1] = 0;
	while(!q.empty()){
		int front = q.front(); q.pop();
		// printf("stat[%d]: %d\n",front,stat[front]);
		for(i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			int minim = min(v, front), maks = max(v,front);
			// printf("-- stat[%d]: %d\n",v, stat[v]);
			if(s.find(ii(minim, maks)) != s.end()){
				int idxEdge = mapper[ii(minim, maks)];
				ii asli = ii(x[idxEdge], y[idxEdge]);
				if(stat[v] == -1){
					stat[v] = 1 - stat[front];
					if(asli == ii(front, v)){
						dir[idxEdge] = (stat[front] == 0 ? 1 : 0);
					}else{
						dir[idxEdge] = (stat[front] == 0 ? 0 : 1);
					}
				}else{
					if(stat[v] == stat[front]){
						printf("NO\n"); return 0;
					}else{
						if(asli == ii(front,v)){
							dir[idxEdge] = (stat[front] == 0 ? 1 : 0);	
						}else{
							dir[idxEdge] = (stat[front] == 0 ? 0 : 1);
						}
						

					}
				}
				q.push(v);
				s.erase(ii(minim, maks));
			}
		}
	}
	printf("YES\n");
	for(i=0;i<m;i++){
		printf("%d",dir[i]);
	}
	printf("\n");
	
	return 0;
};