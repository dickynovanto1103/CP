#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
typedef vector <int> vi;
typedef pair <int,int> ii;
vector <vi> AdjList,listnode;
vector <ii> pairlist;
vi bfs_num;
queue <int> q;
int main(){
	int n,i,j,cnt,a,b,ukuran,tc=0;
	bool found;
	string awal,akhir;
	map <string,int> mapper;
	map <string,int>::iterator it;
	map <int,string> mapper2;
	map <int,string>::iterator it2;

	while(scanf("%d",&n)!=EOF){
		cnt=0;
		if(tc>0){printf("\n");}
		for(i=0;i<n;i++){
			cin>>awal>>akhir;
			it=mapper.find(awal);
			if(it==mapper.end()){mapper[awal]=cnt; mapper2[cnt]=awal; cnt++;}
			it=mapper.find(akhir);
			if(it==mapper.end()){mapper[akhir]=cnt; mapper2[cnt]=akhir; cnt++;}
			it=mapper.find(awal); a = it->second;
			it=mapper.find(akhir); b = it->second;
			pairlist.push_back(ii(a,b));
		}
		AdjList.assign(cnt,vi());
		listnode.assign(cnt,vi());
		ukuran = pairlist.size();
		for(i=0;i<ukuran;i++){
			ii data = pairlist[i];
			AdjList[data.first].push_back(data.second);
			AdjList[data.second].push_back(data.first);
		}
		pairlist.clear();
		cin>>awal>>akhir;
		found=true;
		it=mapper.find(awal); 
		if(it==mapper.end()){found = false;}
		else{a = it->second;}
		it=mapper.find(akhir);
		if(it==mapper.end()){found = false;}
		else{b = it->second;}
		if(found){
			bfs_num.assign(cnt,unvisited);
			q.push(a); bfs_num[a]=visited; listnode[a].push_back(a);
			while(!q.empty()){
				int front = q.front(); q.pop();
				for(i=0;i<AdjList[front].size();i++){
					int node = AdjList[front][i];
					if(bfs_num[node]==unvisited){
						bfs_num[node]=visited;
						q.push(node);
						//ambil listnode dari node front ke dirinya
						for(j=0;j<listnode[front].size();j++){
							listnode[node].push_back(listnode[front][j]);
						}
						listnode[node].push_back(node);
					}
				}
			}
			if(bfs_num[b]==unvisited){printf("No route\n");}
			else{
				ukuran = listnode[b].size();
				for(i=0;i<ukuran;i++){
					if(i+1<ukuran){
						string kata1 = mapper2[listnode[b][i]].data();
						string kata2 = mapper2[listnode[b][i+1]].data();
						cout<<kata1 << " "<<kata2<<endl;
					}
				}
			}	
		}else{printf("No route\n");}
		
		tc=1;
		AdjList.clear(); mapper.clear(); mapper2.clear(); listnode.clear();

	}
	return 0;
}