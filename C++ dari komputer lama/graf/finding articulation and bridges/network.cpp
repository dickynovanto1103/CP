#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;
#define DFS_WHITE -1
typedef vector<int> vi;
typedef pair<int,int> ii;

vector<vi> AdjList;
vi dfs_num, dfs_low, dfs_parent;       // additional information for articulation points/bridges/SCCs
vi articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    int v = AdjList[u][j];
    if (dfs_num[v] == DFS_WHITE) {                          // a tree edge
      dfs_parent[v] = u;
      if (u == dfsRoot) rootChildren++;  // special case, count children of root

      articulationPointAndBridge(v);

      if (dfs_low[v] >= dfs_num[u])              // for articulation point
        articulation_vertex[u] = true;           // store this information first
      if (dfs_low[v] > dfs_num[u])                           // for bridge
        //printf(" Edge (%d, %d) is a bridge\n", u, v);
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);       // update dfs_low[u]
    }
    else if (v != dfs_parent[u])       // a back edge and not direct cycle
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);       // update dfs_low[u]
} }
int main(){
  int V,i,j, cnt;
  while(scanf("%d",&V),V){
    AdjList.assign(V+1,vi());
    dfsNumberCounter = 0; dfs_num.assign(V+1, DFS_WHITE); dfs_low.assign(V+1, 0);
    dfs_parent.assign(V+1, -1); articulation_vertex.assign(V+1, 0);
    int node_awal, tetangga;
    string kata;
    getline(cin>>ws,kata);
    while(kata[0]!='0'){
      //cout<<"kata: "<<kata<<endl;
      //parsing
      int bil = cnt = 0;
      int a[110];
      for(i=0;i<kata.length();i++){
        if(kata[i]==' '){a[cnt] = bil; cnt++ ;bil = 0;}
        else{bil*=10; bil+=kata[i]-48;}
      }
      if(bil>0){a[cnt] = bil; cnt++;}
      /*printf("list angka: ");
      for(i=0;i<cnt;i++){printf(" %d",a[i]);}
      printf("\n");*/
      for(i=1;i<cnt;i++){AdjList[a[0]].push_back(a[i]); AdjList[a[i]].push_back(a[0]); }
      getline(cin,kata);
    }
    /*for(i=1;i<=V;i++){
      printf("node %d:",i);
      for(j=0;j<AdjList[i].size();j++){printf(" %d",AdjList[i][j]);}
      printf("\n");
    }*/
    

    //printf("Bridges:\n");
    for (int i = 1; i <= V; i++)
      if (dfs_num[i] == DFS_WHITE) {
        dfsRoot = i; rootChildren = 0;
        articulationPointAndBridge(i);
        articulation_vertex[dfsRoot] = (rootChildren > 1); }       // special case
    //printf("Articulation Points:\n");
    int ans = 0;
    for (int i = 1; i <= V; i++)
      if (articulation_vertex[i]){
        printf("node %d\n",i);
        ans++;
      }

    printf("%d\n",ans);
    dfs_num.clear(); dfs_low.clear(); dfs_parent.clear(); articulation_vertex.clear(); AdjList.clear();
  }
 

  return 0;
  }