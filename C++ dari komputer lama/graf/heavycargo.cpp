#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector <int> vi;
typedef vector<ii> vii;

vector <iii> EdgeList;
vector <vii> AdjList;
class UnionFind{
private: 
	vi rank,p,setSize;
	int numset,i;
public:
	UnionFind(int n){
		numset=n; setSize.assign(n,1); rank.assign(n,0); p.assign(n,0);
		for(i=0;i<n;i++){p[i]=i;}
	}

	int findSet(int i){return (p[i]==i) ? i : (p[i]=findSet(p[i]));}
	bool isSameSet(int i, int j){return findSet(i)==findSet(j);}
	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			numset--;
			int x=findSet(i), y=findSet(j);
			if(rank[x] > rank[y]){p[y]=x; setSize[x]+=setSize[y];}
			else{
				p[x]=y;
				setSize[y]+=setSize[x];
				if(rank[x]==rank[y]){rank[y]++;}
			}
		}
	}
	int numDisjointSet(){return numset;}
	int sizeSetOf(int i){return setSize[findSet(i)];}
};

vi dist;
int main(){
	int V,E,i,j,w,cnt,a,b,tc=1;
	string kata1,kata2;
	queue <int> q;
	map<string,int> mapper;
	map<string,int>::iterator it;
	while(scanf("%d %d",&V,&E),(V||E)){
		UnionFind UF(V); AdjList.assign(V,vii());
		cnt=0;
		for(i=0;i<E;i++){
			cin>>kata1>>kata2>>w;
			it=mapper.find(kata1);
			if(it==mapper.end()){mapper[kata1]=cnt++;}
			it=mapper.find(kata2);
			if(it==mapper.end()){mapper[kata2]=cnt++;}
			it=mapper.find(kata1); a = it->second;
			it=mapper.find(kata2); b = it->second;
			EdgeList.push_back(make_pair(w,ii(a,b)));
			
		}
		cin>>kata1>>kata2; //awal dan akhir
		sort(EdgeList.begin(),EdgeList.end());
		reverse(EdgeList.begin(), EdgeList.end());
		for(i=0;i<E;i++){
			iii front = EdgeList[i];
			int node1 = front.second.first, node2 = front.second.second;
			if(!UF.isSameSet(node1,node2)){
				UF.unionSet(node1,node2);
				AdjList[node1].push_back(ii(node2,front.first)); AdjList[node2].push_back(ii(node1,front.first));
			}
		}
		it=mapper.find(kata1); a = it->second;//node awal
		it=mapper.find(kata2); b = it->second;//node akhir
		dist.assign(V,inf);
		q.push(a);
		while(!q.empty()){
			int front = q.front(); q.pop();
			//printf("front: %d\n",front);
			for(i=0;i<AdjList[front].size();i++){
				ii v = AdjList[front][i];
				if(dist[v.first]==inf){
					//printf("v second: %d\n",v.second);
					dist[v.first] = min(v.second,dist[front]);
					//printf("v.first: %d dist: %d\n",v.first,dist[v.first]);
					q.push(v.first);	
				}
			}
		}
		dist[a] = 0;
		printf("Scenario #%d\n",tc++);
		printf("%d tons\n\n",dist[b]);
		EdgeList.clear(); AdjList.clear(); mapper.clear();
	}
	return 0;
}