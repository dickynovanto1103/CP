#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> AdjList;
bool visited[105];
bool isAwalVisited;
int nodeAwal;

void dfs(int u)
{
	visited[u] = true;

	for(int i=0;i<(int)AdjList[u].size();i++)
	{
		ii temp = AdjList[u][i];
		if(temp.first == nodeAwal){isAwalVisited = true;}
		int v = temp.first;

		if (!visited[v])
			dfs(v);
	}
}

int main ()
{
	int input, n, v, nSimpul;

	while(scanf("%d",&input),input){

		nSimpul = input;

		AdjList.assign(input+1,vii());

		
		while(scanf("%d",&n),n){
			while(scanf("%d",&v),v) {
				AdjList[n].push_back(ii(v,1));
			}		
		}
			
		
		//scanf("%d",&n);

		scanf("%d",&input);
		
		for(int i=0;i<input;i++)
		{
			int v, counter=0;
			vector<int> list;
			scanf("%d",&v);
			nodeAwal = v;
			memset(visited,false,sizeof visited);
			isAwalVisited = false;
			
			dfs(v);
			
			

			for(int j=1;j<=nSimpul;j++)
			{
				if (!visited[j])
				{
					//printf("j: %d\n",j);
					counter++;
					list.push_back(j);
				}
				if (!isAwalVisited && j==v)
				{
					//printf("j: %d masuk sini\n",j);
					counter++;
					list.push_back(j);
				}
			}
				
			printf("%d",counter);
			for(int j=0;j<list.size();j++)
			{
				printf(" %d",list[j]);
			}
			printf("\n");
		}
		AdjList.clear(); 

	}

	

	return 0;
}