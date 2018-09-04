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
vector<vi> listAnak;
vector<vi> urutan;
const int maxn = 2e5 + 5;

int main(){
	int n,i,j;
	scanf("%d",&n);
	if(n==1){printf("Yes\n"); return 0;}
	AdjList.assign(n+1,vi());
	listAnak.assign(n+1,vi());
	urutan.assign(maxn,vi());
	bool isVisited[maxn];
	for(i=0;i<(n-1);i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}
	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(a[0]!=1){printf("No\n"); return 0;}
	memset(isVisited, false, sizeof isVisited);
	queue<int> q;
	q.push(1);
	isVisited[1] = true;
	
	int banyakAnak[maxn];
	// listIdx[0] = ii(0,0);
	while(!q.empty()){
		int front = q.front(); q.pop();
		int cntAnak = 0;
		for(i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			if(!isVisited[v]){
				cntAnak++;
				isVisited[v] = true;
				q.push(v);
				listAnak[front].pb(v);
			}
		}
		sort(listAnak[front].begin(), listAnak[front].end());
		banyakAnak[front] = cntAnak;
	}

	ii listIdx[maxn];
	listIdx[0] = ii(0,0);
	int idx = 0;
	for(i=0;i<n;i++){
		int cntAnak = banyakAnak[a[i]];
		if(cntAnak == 0){
			listIdx[i] = ii(-1,-1);
		}else{
			listIdx[i] = ii(idx+1, idx+cntAnak);
			idx += cntAnak;
		}
	}

	
	// printf("n: %d\n",n);
	int temp[maxn];
	for(i=0;i<n;i++){
		int awal = listIdx[i].first, akhir = listIdx[i].second;
		if(awal == akhir && awal == -1){continue;}
		int ukuran = akhir - awal + 1;
		for(j=awal;j<=akhir;j++){
			temp[j-awal] = a[j];
		}
		sort(temp,temp+ukuran);
		int node = a[i];
		// printf("i: %d node: %d\n",i,node);
		for(j=0;j<ukuran;j++){
			if(temp[j] != listAnak[node][j]){
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	
	return 0;
};