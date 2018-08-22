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

const int maxn = 3e5 + 5;

vector<vii> AdjList;
bool isVisited[maxn];
set<int> ans;
bool isHapus[maxn];

int main(){
	int n,k,d;
	int i,j;
	vi kantor;
	scanf("%d %d %d",&n,&k,&d);
	AdjList.assign(n+1,vii());

	queue<ii> q;
	for(i=0;i<k;i++){
		int bil;
		scanf("%d",&bil);
		q.push(ii(bil,-1));
	}

	for(i=1;i<=(n-1);i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(ii(b,i));
		AdjList[b].pb(ii(a,i));
	}
	
	memset(isVisited, false, sizeof isVisited);
	memset(isHapus, false, sizeof isHapus);
	while(!q.empty()){
		ii front = q.front(); q.pop();

		int node = front.first, parent = front.second;
		if(isVisited[node]){continue;}
		isVisited[node] = true;
		for(i=0;i<AdjList[node].size();i++){
			ii v = AdjList[node][i];
			if(v.first==parent){continue;}
			if(!isVisited[v.first]){
				q.push(ii(v.first,node));
			}else{
				int idx = AdjList[node][i].second;
				isHapus[idx] = true;
			}
		}
	}

	int ukuran = 0;
	for(i=1;i<=(n-1);i++){
		if(isHapus[i]){ukuran++;}
	}

	printf("%d\n",ukuran);
	for(i=1;i<=(n-1);i++){
		if(isHapus[i]){printf("%d ",i);}
	}
	printf("\n");
	return 0;
};