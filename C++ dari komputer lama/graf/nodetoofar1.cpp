#include <bits/stdc++.h>

using namespace std;
typedef vector <int> vi;

vector <vi> AdjList;

int main(){
	int V,i,j,v1,v2,idx,a,b,tc;
	map <int,int> mapper;
	map <int,int>::iterator it;
	vi listnode;
	vector <int>::iterator it2;
	while(scanf("%d",&V),V){
		for(i=0;i<V;i++){
			idx=1;
			scanf("%d %d",&v1,&v2);
			it=mapper.find(v1);
			if(it==mapper.end()){mapper[v1]=idx++;listnode.push_back(idx-1);}
			it=mapper.find(v2)
			if(it==mapper.end()){mapper[v2]=idx++;listnode.push_back(idx-1);}

			it=mapper.find(v1); a=it->second;
			it=mapper.find(v2); b=it->second;
			AdjList[a].push_back(b);
			AdjList[b].push_back(a);
		}
		while(scanf("%d %d"))
	}

	return 0;
}