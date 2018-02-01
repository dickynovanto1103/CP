#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_num;
bool foundNew;
int listIdx[28];

int main(){
	string kata;
	int i,j;
	map<char,int> mapper;
	map<char,int>::iterator it;
	
	bool isTetangga, isNode;
	int listkar[9];
	while(cin>>kata && kata!="#"){
		AdjList.assign(26,vi());
		int cnt = 0;
		int ukuran = kata.length();
		isNode = true; isTetangga = false;
		for(i=0;i<ukuran;i++){
			int curNode;
			char kar = kata[i];

			if(kar==':'){isTetangga = true; isNode = false; continue;}
			else if(kar==';'){isNode = true; isTetangga = false; continue;}

			it = mapper.find(kar);
			int ascii = kar-65;
			if(it==mapper.end()){mapper[kar] = ascii; listkar[cnt] = ascii; cnt++;}
			int bil = mapper[kar];
			//printf("kar: %c termap ke %d\n",kar,bil);
			if(isNode){	
				curNode = bil;
				//printf("mencatat curnode: %d\n",curNode);
			}else if(isTetangga){
				//printf("mencatat tetangga: %d\n",bil);
				AdjList[curNode].push_back(bil); //AdjList[bil].push_back(curNode);
			}
		}
		sort(listkar,listkar+cnt);
		//int counter = 0;
		
		int ans = 1000000000;
		int listjawaban[9];
		do{
			for(i=0;i<cnt;i++){
				int bilangan = listkar[i];
				//printf("%d ",listkar[i]);
				listIdx[bilangan] = i;
			}
			int maks = -1;

			for(i=0;i<26;i++){
				for(j=0;j<AdjList[i].size();j++){
					int v = AdjList[i][j];
					maks = max(maks, abs(listIdx[v] - listIdx[i]));
				}
			}

			if(ans > maks){
				ans = maks;
				//printf("ans menjadi: %d\n",ans);
				//catat jawabannya
				for(i=0;i<cnt;i++){listjawaban[i] = listkar[i];}
			}
			//ans = min(ans,minim);
			//printf("\n");
			//counter++;
		}while(next_permutation(listkar,listkar+cnt));
		//printf("counter: %d\n",counter);
		//for(i=0;i<cnt;i++){printf("%d\n",listkar[i]);}
		for(i=0;i<cnt;i++){
			char kar = listjawaban[i] + 65;
			if(i>0){printf(" ");}
			printf("%c",kar);
		}
		printf(" -> %d\n",ans);
		/*for(i=0;i<cnt;i++){
			printf("node %d:",i);
			for(j=0;j<AdjList[i].size();j++){
				printf(" %d",AdjList[i][j]);
			}
			printf("\n");
		}*/

		AdjList.clear();
		mapper.clear();
	}
	return 0;
}