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

const int maxn = 2e5 + 5;

vector<vi> AdjList;

int deg[maxn];

int main(){
	int n,m,x,l;
	int i,j;
	scanf("%d %d %d %d",&n,&m,&x,&l);
	AdjList.assign(n+1, vi());

	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		deg[a]++; deg[b]++;
		AdjList[a].pb(b);
		AdjList[b].pb(a);
	}
	int minim[maxn];
	for(i=1;i<=n;i++){
		minim[i] = (deg[i]) / 2;
		// printf("minim %d: %d, deg: %d\n",i,minim[i],deg[i]);
	}
	queue<int> q;
	q.push(l);
	bool isStay[maxn];
	memset(isStay, true, sizeof isStay);
	while(!q.empty()){
		int front = q.front(); q.pop();
		isStay[front] = false;
		deg[front] = 0;
		// printf("keluar: %d\n",front);
		for(i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			deg[v]--;
			if(deg[v] <= minim[v] && isStay[v]){
				isStay[v] = false;
				q.push(v);
			}
			
		}
	}
	if(isStay[x]){printf("stay\n");}
	else{printf("leave\n");}
	return 0;
};