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
typedef pair<int,ii> iii;
typedef vector<ii> vii;

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


vector<iii> edgeList;

int main(){

	int n,m,i,j;
	scanf("%d %d",&n,&m);
	UnionFind UF(n);
	priority_queue<iii, vector<iii>, greater<iii> > pq;
	for(i=0;i<m;i++){
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		a--; b--;
		pq.push(iii(w, ii(a,b)));
	}
	int cur = 0;
	int cnt = 0;
	int minim[200010];
	memset(minim, -1, sizeof minim);
	while(!pq.empty()){
		iii front = pq.top(); pq.pop();
		int berat = front.first, a = front.second.first, b = front.second.second;
		if(!UF.isSameSet(a,b)){
			UF.unionSet(a,b);
			// printf("gabung %d %d\n",a+1,b+1);
			if(minim[a] == -1){
				minim[a] = berat;
			}
			if(minim[b] == -1){
				minim[b] = berat;
			}
			minim[a] = min(minim[a], berat);
			minim[b] = min(minim[b], berat);
			cur = berat;
			// if(UF.numDisjointSet() == 1){break;}
		}else{
			int minim1 = minim[a], minim2 = minim[b];
			if(berat <= max(minim1, minim2)){
				pq.push(iii(berat+1, ii(a,b)));
				// printf("dipush lg dengan berat: %d dan %d %d\n",berat+1, a+1, b+1);
				cnt++;				
			}
			
		}
	}
	printf("%d\n",cnt);
	return 0;
};