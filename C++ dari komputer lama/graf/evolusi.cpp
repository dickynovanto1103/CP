#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
typedef vector <int> vi;

vector <vi> AdjList;
vi listnode; vi dfs_num;
bool found=false;

void del(int acuan){
	//traversal cari indeks acuan
	int idx,i;
	for(i=0;i<listnode.size();i++){
		if(listnode[i]==acuan){idx=i;break;}
	}
	//printf("idx: %d\n",idx,listnode[idx+1]);
	while(listnode.size()>idx+1){
		dfs_num[listnode[idx+1]]=visited;
		listnode.erase(listnode.begin()+(idx+1));
		/*printf("listnode proses:");
		for(i=0;i<listnode.size();i++){printf(" %d",listnode[i]);}
		printf("\n");*/
	}
}

void dfs(int source,int dest){
	int i,v;
	dfs_num[source]=visited;
	listnode.push_back(source);
	//if(source==dest){found=true;}
	/*printf("listnode added:");
	for(i=0;i<listnode.size();i++){printf(" %d",listnode[i]);}
	printf("\n");*/
	for(i=0;i<AdjList[source].size();i++){
		if(i>0 && !found){del(source);}
		v=AdjList[source][i];
		if(v==dest){listnode.push_back(v);found=true;return;}
		else{if(dfs_num[v]==unvisited && !found) dfs(v,dest);}//when found, stop visiting unvisited node

	}
}

int main(){
	int V,E,i,j,idx,a,b;
	char ortu[25],anak[25],string1[25],string2[25];
	map <string,int> mapper;
	map <string,int>::iterator it;
	map <int,string> mapper2;
	bool test;
	
	//test
	/*dfs_num.assign(11,unvisited);
	scanf("%d",&V);
	for(i=0;i<V;i++){scanf("%d",&a);listnode.push_back(a);}
	scanf("%d",&b);
	printf("listnode awal:");
	for(i=0;i<listnode.size();i++){printf(" %d",listnode[i]);}
	printf("\n");
	del(b);
	printf("listnode akhir:");
	for(i=0;i<listnode.size();i++){printf(" %d",listnode[i]);}
	printf("\n");*/
	idx=0;
	scanf("%d %d",&V,&E);
	AdjList.assign(V,vi());
	dfs_num.assign(V,unvisited);
	for(i=0;i<E;i++){
		scanf("%s %s",ortu,anak);
		it=mapper.find((string)ortu);
		if(it==mapper.end()){mapper[(string)ortu]=idx++; mapper2[idx-1]=(string)ortu;}
		it=mapper.find((string)anak);
		if(it==mapper.end()){mapper[(string)anak]=idx++; mapper2[idx-1]=(string)anak;}
		it=mapper.find((string)ortu); a=it->second;
		it=mapper.find((string)anak); b=it->second;
		//printf("%s mapped: %d, %s mapped %d\n",ortu,a,anak,b);
		AdjList[a].push_back(b);
	}
	/*for(i=0;i<V;i++){
		printf("node %d:",i);
		for(j=0;j<AdjList[i].size();j++){printf(" %d",AdjList[i][j]);}
		printf("\n");
	}*/
	scanf("%s %s",string1,string2);
	it=mapper.find((string)string1); a=it->second;
	it=mapper.find((string)string2); b=it->second;
	//printf("%s mapped %d, %s mapped %d\n",string1,a,string2,b);
	//traversal 2 kali
	//traversal node a
	
	dfs_num.assign(V,unvisited);//reset
	dfs(a,b);
	if(!found){
		listnode.clear();
		dfs(b,a);
		if(!found){printf("TIDAK MUNGKIN\n");}
		else{for(i=0;i<listnode.size();i++){printf("%s\n",mapper2[listnode[i]].data());}}
	}else{for(i=0;i<listnode.size();i++){printf("%s\n",mapper2[listnode[i]].data());}}
	
	return 0;
}