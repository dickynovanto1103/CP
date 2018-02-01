#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector <int> vi;

vector <iii> EdgeList;

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

int main(){
	int tc,n,i,j,k,jarak,E,mst,temp,idx;
	string kata[500];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		UnionFind UF(n+1);
		kata[0]="0000";
		temp=1000; idx=0;
		for(i=1;i<=n;i++){cin>>kata[i];}
		//cari yang terdekat dengan 0000
		for(i=1;i<=n;i++){
			jarak=0;
			for(k=0;k<4;k++){
				int a,b;
				a=kata[0][k]-'0'; b=kata[i][k]-'0';
				if(a<b){jarak+=min(b-a,a+10-b);}
				else{jarak+=min(a-b,10-a+b);}
				//printf("jarak menjadi: %d\n",jarak);
			}
			if(temp>jarak){temp = jarak; idx = i;}
		}
		EdgeList.push_back(make_pair(temp,ii(0,idx)));
		//cari antar key yang kunci
		for(i=1;i<=n-1;i++){
			for(j=i+1;j<=n;j++){
				//cout<<"kata ke "<<i<<":"<<kata[i]<<", "<<"kata ke "<<j<<":"<<kata[j]<<endl;
				//mulai itung jarak kata 1 ke yang lain
				jarak=0;
				for(k=0;k<4;k++){
					int a,b;
					a=kata[i][k]-'0'; b=kata[j][k]-'0';
					if(a<b){jarak+=min(b-a,a+10-b);}
					else{jarak+=min(a-b,10-a+b);}
					//printf("jarak menjadi: %d\n",jarak);
				}
				EdgeList.push_back(make_pair(jarak,ii(i,j)));
			}
		}
		sort(EdgeList.begin(),EdgeList.end());
		E=EdgeList.size();
		mst=0;
		for(i=0;i<E;i++){
			iii front = EdgeList[i];
			int node1 = front.second.first, node2 = front.second.second;
			//printf("node1 : %d node2: %d berat: %d\n",node1,node2,front.first);
			if(!UF.isSameSet(node1,node2)){
				mst+=front.first;
				//printf("mst: %d node1 : %d node2: %d\n",mst,node1,node2);
				UF.unionSet(node1,node2);
			}
		}
		printf("%d\n",mst);
		EdgeList.clear();
	}
	return 0;
}