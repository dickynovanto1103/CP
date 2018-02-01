#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
typedef vector <int> vi;

vector <vi> AdjList,listnode;
vi bfs_num;
queue <int> q;
int main(){
	int n,i,j,k,bil,m,a,b;
	string kata;
	bool found;
	
	while(scanf("%d",&n)!=EOF){
		printf("-----\n");
		AdjList.assign(n+1,vi());
		
		for(i=0;i<n;i++){
			if(i==0){getline(cin>>ws,kata);}
			else{getline(cin,kata);}
			bil=0;
			for(j=0;j<kata.length();j++){
				if(kata[j]=='-'){bil=0;continue;}
				else if(kata[j]==','){AdjList[i+1].push_back(bil); bil=0; continue;}
				else{bil=bil*10 + kata[j]-'0';}
			}
			if(bil==0){continue;}
			AdjList[i+1].push_back(bil);
		}
		/*for(i=1;i<=n;i++){
			printf("node %d:",i);
			for(j=0;j<AdjList[i].size();j++){
				printf(" %d",AdjList[i][j]);
			}
			printf("\n");
		}*/


		scanf("%d",&m);
		for(i=0;i<m;i++){
			bfs_num.assign(n+1,unvisited);
			scanf("%d %d",&a,&b);
			found=true;
			if((a>=1 && a<=n) || (b>=1 && b<=n)){
				listnode.assign(n+1,vi());
				/*printf("untuk i: %d\n",i);
				for(j=1;j<=n;j++){
					printf("node %d:",j);
					for(k=0;k<listnode[j].size();k++){
						printf(" %d",listnode[j][k]);
					}
					printf("\n");
				}*/

				bfs_num[a]=visited; q.push(a); listnode[a].push_back(a); //printf("ditambahkan: %d pada node: %d luar\n",a,a);
				while(!q.empty()){
					int front = q.front(); q.pop();
					for(j=0;j<AdjList[front].size();j++){
						int node = AdjList[front][j];
						if(bfs_num[node]==unvisited){
							bfs_num[node]=visited; q.push(node);
							//printf("ukuran listnode front: %d\n",listnode[front].size());
							for(k=0;k<listnode[front].size();k++){
								int temp = listnode[front][k]; //printf("ditambahkan: %d pada node: %d\n",temp,node );
								listnode[node].push_back(temp);
							}
							listnode[node].push_back(node);
							//printf("ditambahkan: %d pada node: %d akhir\n",node,node);
						}
					}
				}
				if(bfs_num[b]==unvisited){printf("connection impossible\n");}
				else{
					//printf("untuk b: %d\n",b);
					for(j=0;j<listnode[b].size();j++){
						int temp = listnode[b][j];
						if(j==0){printf("%d",temp);}
						else{printf(" %d",temp);}
					}
					printf("\n");
				}
				listnode.clear();
			}else{
				printf("connection impossible\n");
			}
			
		}
		AdjList.clear();
	}
	return 0;
}