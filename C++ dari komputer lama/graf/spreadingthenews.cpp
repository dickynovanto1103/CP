#include <bits/stdc++.h>

using namespace std;
#define visited 1
#define unvisited -1
typedef vector <int> vi;

vector <vi> AdjList;
vi bfs_num;
int main(){
	int E,j,k,i,tc,n,akhir,s,cnt,hari,ans,a,total;
	queue <int> q,temp;
	scanf("%d",&E);
	AdjList.assign(E,vi());
	
	for(i=0;i<E;i++){
		scanf("%d",&n);
		for(j=0;j<n;j++){scanf("%d",&akhir); AdjList[i].push_back(akhir);}
	}
	scanf("%d",&tc);
	while(tc--){
		bfs_num.assign(E,unvisited);
		scanf("%d",&s);
		q.push(s); bfs_num[s]=visited;
		ans=0; j =1;
		while(!q.empty()){
			total=0;
			while(!q.empty()){a = q.front();q.pop(); temp.push(a);total++;}
			while(!temp.empty()){a = temp.front(); temp.pop(); q.push(a);}
			cnt=0;
			for(k=0;k<total;k++){
				int head = q.front(); q.pop();
				
				for(i=0;i<(int)AdjList[head].size();i++){
					int tetangga = AdjList[head][i];
					if(bfs_num[tetangga]==unvisited){cnt++; bfs_num[tetangga]=visited; q.push(tetangga);}
				}
			}
			//printf("cnt: %d hari : %d\n",cnt,j);
			if(cnt>ans){ans=cnt; hari=j;}
			j++;
			
		}
		if(ans==0){printf("0\n");}
		else{printf("%d %d\n",ans,hari);}
	}

	return 0;
}