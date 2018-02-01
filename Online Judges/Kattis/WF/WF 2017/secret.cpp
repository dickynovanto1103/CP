#include <bits/stdc++.h>

using namespace std;
#define visited 1
#define unvisited -1
typedef vector<int> vi;

vector<vi> AdjList;

bool foundKar;
vi dfs_num;

void dfs(int a, int b){
	if(foundKar){return;}
	dfs_num[a] = visited;
	for(int i=0;i<AdjList[a].size();i++){
		int c = AdjList[a][i];
		//printf("c: %d\n",c);
		if(c!=b){
			//printf("kar c: %d berbeda\n");
			if(dfs_num[c]==unvisited){dfs(c,b);}
			
		}else{foundKar = true;}
	}
}

int main(){
	int n,m,i,j;
	map<char,int> mapper;
	map<char,int>::iterator it;
	while(scanf("%d %d\n",&n,&m)!=EOF){
		//printf("n: %d m: %d\n",n,m);
		int cnt=0;
		AdjList.assign(1001,vi());
		for(i=0;i<n;i++){
			//printf("i: %d\n",i);
			char kar1,kar2;
			scanf("%c %c\n",&kar1,&kar2);
			//printf("kar1: %c kar2: %c\n",kar1,kar2);
			it = mapper.find(kar1);
			if(it==mapper.end()){mapper[kar1] = cnt++;}
			it = mapper.find(kar2);
			if(it==mapper.end()){mapper[kar2] = cnt++;}
			int a = mapper[kar1], b = mapper[kar2];
			AdjList[a].push_back(b);
		}
		for(i=0;i<m;i++){
			string kata1,kata2;
			cin>>kata1>>kata2;
			int pjg1 = kata1.length(),pjg2=kata2.length();
			if(pjg1!=pjg2){printf("no\n");}
			else{
				//cout<<"kata1: "<<kata1<<" kata2: "<<kata2<<endl;
				bool found = true;
				for(j=0;j<pjg1;j++){
					char kar1 = kata1[j] ,kar2 = kata2[j];
					if(kar1!=kar2){
						dfs_num.assign(cnt,unvisited);
						it = mapper.find(kar1);
						if(it!=mapper.end()){
							it = mapper.find(kar2);
							if(it != mapper.end()){
								int a = mapper[kar1], b = mapper[kar2];
								foundKar = false;
								dfs(a,b);
							}else{foundKar = false;}
						}else{foundKar = false;}
						
						/*printf("kar1: %c kar2: %c\n",kar1,kar2);
						if(foundKar){printf("ditemukan\n");}
						else{printf("tidak ditemukan\n");}*/
						if(!foundKar) {found = false; break;}
						//else{printf("kar1 %c bs mencapai kar2: %c\n",kar1,kar2);}
					}
				}
				if(!found){printf("no\n");}
				else{printf("yes\n");}
			}
		}
		dfs_num.clear();
		AdjList.clear();
		mapper.clear();
	}
	
	return 0;
}