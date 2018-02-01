#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
typedef vector <int> vi;
typedef pair <int,int> ii;
vector <vi> AdjList,listnode;
vector <ii> pairlist;
vi bfs_num;
int main(){
	int tc,i,j,k,n,m,cnt,bil1,bil2;
	string a,b,katatemp;
	map <string,int> mapper;
	map <string,int>::iterator it;
	map <int,string> mapper2;
	map <int,string>::iterator it2;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		cnt=0;
		for(i=0;i<n;i++){
			cin>>a>>b;	
			it = mapper.find(a); 
			if(it==mapper.end()){mapper[a]=cnt; mapper2[cnt]=a; cnt++;}
			it = mapper.find(b); 
			if(it==mapper.end()){mapper[b]=cnt; mapper2[cnt]=b; cnt++;}
			it = mapper.find(a); bil1 = it->second;
			it = mapper.find(b); bil2 = it->second;
			pairlist.push_back(ii(bil1,bil2));
		}
		AdjList.assign(cnt,vi()); 
		for(i=0;i<n;i++){
			ii data = pairlist[i];
			AdjList[data.first].push_back(data.second);
			AdjList[data.second].push_back(data.first);
		}
		for(i=0;i<m;i++){
			bfs_num.assign(cnt,unvisited);
			cin>>a>>b;
			it = mapper.find(a); bil1 = it->second;
			it = mapper.find(b); bil2 = it->second;
			listnode.assign(cnt,vi());
			queue <int> q;
			q.push(bil1); bfs_num[bil1] = visited; listnode[bil1].push_back(bil1);
			while(!q.empty()){
				int front = q.front(); q.pop();
				for(j=0;j<AdjList[front].size();j++){
					int node = AdjList[front][j];
					if(bfs_num[node]==unvisited){
						bfs_num[node]=visited; q.push(node);
						for(k=0;k<listnode[front].size();k++){
							listnode[node].push_back(listnode[front][k]);
						}
						listnode[node].push_back(node);
					}
				}
			}
			for(j=0;j<listnode[bil2].size();j++){
				int temp = listnode[bil2][j];
				katatemp = mapper2[temp].data();
				cout<<katatemp[0];
			}
			printf("\n");
			listnode.clear();
		}
		AdjList.clear(); mapper.clear(); mapper2.clear(); pairlist.clear();
		if(tc){printf("\n");}
	}
	return 0;
}