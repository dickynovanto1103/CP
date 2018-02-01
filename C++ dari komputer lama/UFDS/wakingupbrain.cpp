#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
typedef vector <int> vi;
vector <vi> AdjList;

bool \

int main(){
	int n,i,j,sleep,cnt,ans,cntconnected,v,s;
	map <char,int> mapper;
	map <char,int>::iterator it;
	vi dfs_num;
	bool found;
	char bangun[5],karakter;
	while(scanf("%d",&sleep)!=EOF){
		cnt=-1;
		scanf("%d",&n);
		AdjList.assign(sleep,vi()); dfs_num.assign(sleep,unvisited);
		char hubungan[n+5][5];
		scanf("%s",bangun);
		for(i=0;i<strlen(bangun);i++){
			karakter = bangun[i];
			it=mapper.find(karakter);
			if(it==mapper.end()){mapper[karakter]=++cnt;}
		}
		for(i=0;i<n;i++){
			scanf("%s",hubungan[i]);
			for(j=0;j<strlen(hubungan[i]);j++){
				karakter = hubungan[i][j];
				it=mapper.find(karakter);
				if(it==mapper.end()){mapper[karakter]=++cnt;}
			}
		}
		//AdjList.assign(cnt+1,vi()); dfs_num.assign(cnt,unvisited);
		for(i=0;i<n;i++){
			char kar1 = hubungan[i][0],kar2 = hubungan[i][1];
			AdjList[mapper[kar1]].push_back(mapper[kar2]);
			AdjList[mapper[kar2]].push_back(mapper[kar1]);
		}
		for(it=mapper.begin();it!=mapper.end();it++){printf("karakter: %c mapped to %d\n",it->first,it->second);}
		for(i=0;i<sleep;i++){
			printf("node %d:",i);
			for(j=0;j<AdjList[i].size();j++){printf(" %d",AdjList[i][j]);}
			printf("\n");
		}
		for(i=0;i<strlen(bangun);i++){
			karakter = bangun[i];
			dfs_num[mapper[karakter]]=visited;
		}
		found = false;
		for(i=0;i<strlen(bangun) && !found;i++){
			karakter = bangun[i];
			s = mapper[karakter];
			for(j=0;j<AdjList[s].size() && !found;j++){
				v = AdjList[s][j];
				if(dfs_num[v]==unvisited){found = true;}
			}
		}
		if(!found){printf("THIS BRAIN NEVER WAKES UP\n");}
		else{
			ans=0;
			
			for(i=0;i<cnt;i++){
				cntconnected = 0;
				if(dfs_num[i]==unvisited){
					for(j=0;j<AdjList[i].size();j++){
						v = AdjList[i][j];
						if(dfs_num[v]==visited) cntconnected++;
					}
					if(cntconnected>=3){ans++; dfs_num[i]=visited;}
				}
			}
			printf("WAKE UP IN, %d, YEARS\n",ans);
		}
		dfs_num.clear(); AdjList.clear(); mapper.clear();
	}
	return 0;
}