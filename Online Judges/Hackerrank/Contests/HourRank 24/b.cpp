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
vi dist;
const int maxn = 100010;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn],b[maxn];
	vi isVisited;
	dist.assign(n+1,inf); AdjList.assign(n+1,vi());
	isVisited.assign(n+1,unvisited);
	for(i=0;i<n;i++){
		
		scanf("%d %d",&a[i],&b[i]);
		AdjList[a[i]].pb(b[i]);// AdjList[b[i]].pb(a[i]);
	}

	queue<int> q;
	q.push(1);
	dist[1] = 0;
	//bfs

	while(!q.empty()){
		int front = q.front(); q.pop();
		for(i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			
			//if(v==parent[front]){continue;}
			if(dist[v]==inf){
				dist[v] = dist[front] + 1;
				q.push(v);
			}
		}
	}

	vi nilaiAnak;
	nilaiAnak.assign(n+1,0);

	for(i=1;i<=n;i++){
		if(AdjList[i].size()==0){//sebagai daun
			q.push(i);
			//nilaiAnak[i] = 0;
		}
	}
	//tambahin yg belakang
	for(i=0;i<n;i++){
		AdjList[b[i]].pb(a[i]);
	}

	while(!q.empty()){
		int front = q.front(); q.pop();
		if(isVisited[front]==visited){continue;}
		isVisited[front] = visited;
		nilaiAnak[front] += 1;
		set<int> s;
		//printf("front: %d\n",front);
		for(i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			
			//if(v==parent[front]){continue;}
			if(isVisited[v]==visited){continue;}
			
			nilaiAnak[v] += nilaiAnak[front];
			//printf("nilaiAnak[%d] jd: %d\n",v,nilaiAnak[v]);
			s.insert(v);
			//printf("yang diinsert: %d\n",v);
			
		}
		for(set<int>::iterator it=s.begin();it!=s.end();it++){
			int bil = *it;
			q.push(bil);
		}
	}

	// printf("jarak:\n");
	// for(i=1;i<=n;i++){
	// 	printf("i: %d jarak: %d\n",i,dist[i]);
	// }
	// printf("jumlahAnak:\n");
	// for(i=1;i<=n;i++){
	// 	printf("i: %d jumlahAnak: %d\n",i,nilaiAnak[i]);
	// }
	ll sum = 0, weight = 0;
	for(i=0;i<n;i++){
		int bil1 = a[i], bil2 = b[i];
		int kom1 = (n-nilaiAnak[bil2]);
		//printf("kom1: %d\n",kom1);
		if(kom1==n){continue;}
		sum+=(kom1*dist[bil2]);
		weight+=dist[bil2];
		//printf("sum jd: %lld weight: %lld\n",sum,weight);
	}
	printf("%.6lf\n",(double)sum/(double)weight);
	return 0;
};