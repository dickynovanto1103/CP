#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define explored 2
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
bool foundCycle;
const int maxn = 1e2 + 4;
int dfs_num[27];

void graphCheck(int u){
	if(foundCycle){return;}
	dfs_num[u] = explored;
	for(int i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
		if(dfs_num[v] == unvisited){
			graphCheck(v);
		}
		if(dfs_num[v] == explored){
			foundCycle = true;
		}
	}
	dfs_num[u] = visited;
}

int indegree[27];

int main(){
	int n,i,j;
	AdjList.assign(27,vi());
	scanf("%d",&n);
	string kata[maxn], kata2[maxn];
	for(i=0;i<n;i++){
		cin>>kata[i];
		kata2[i] = kata[i];
	}
	sort(kata2,kata2+n);
	bool isBeda = false;
	for(i=0;i<n;i++){
		if(kata2[i]!=kata[i]){isBeda = true; break;}
	}
	if(!isBeda){
		for(i=0;i<26;i++){
			printf("%c",i+'a');
		}
		printf("\n"); return 0;
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<min(kata[i].length(), kata[i+1].length()); j++) {
			char kar1 = kata[i][j], kar2 = kata[i+1][j];
			int nilai1 = kar1-'a', nilai2 = kar2-'a';
			if(kar1!=kar2){
				AdjList[nilai1].pb(nilai2);
				indegree[nilai2]++;
				break;
			}
		}
	}

	// for(i=0;i<26;i++){
	// 	printf("node %c:",i+'a');
	// 	for(j=0;j<AdjList[i].size();j++){
	// 		char v = AdjList[i][j] + 'a';
	// 		printf(" %c",v);
	// 	}
	// 	printf("\n");
	// }

	foundCycle = false;
	memset(dfs_num,unvisited,sizeof dfs_num);
	//cek ada siklus apa ngga
	for(i=0;i<26;i++){
		if(dfs_num[i]==unvisited){graphCheck(i);}
		if(foundCycle){printf("Impossible\n"); return 0;}
	}

	//ga ada cycle
	queue<int> q;
	vi ans;
	int isVisited[27];
	memset(isVisited,false,sizeof isVisited);
	for(i=0;i<26;i++){
		// printf("neliti karakter: %c\n",i+'a');
		if(indegree[i]==0){
			if(q.empty()){
				// q.push(i);
				if(isVisited[i]){continue;}
				ans.pb(i);
				isVisited[i] = true;
				// printf("yang dipush ke queue: %c\n",i+'a');
				// printf("yang dipush ke ans: %c\n",i+'a');
				for(j=0;j<AdjList[i].size();j++){
					int v = AdjList[i][j];
					indegree[v]--;
					if(indegree[v]==0){q.push(v);}
				}
			}else{
				int angka = q.front();
				if(i >= angka){
					if(isVisited[angka]){continue;}
					q.pop(); ans.pb(angka);
					isVisited[angka] = true;
					// printf("kasus ga kosong yang dipush ke ans: %c\n",angka+'a');
					for(j=0;j<AdjList[angka].size();j++){
						int v = AdjList[angka][j];
						indegree[v]--;
						if(indegree[v]==0){
							q.push(v);
							// printf("kasus ga kosong yang dipush ke queue: %c\n",v+'a');
						}
					}
					i--;
				}else{
					if(isVisited[i]){continue;}
					ans.pb(i);
					isVisited[i] = true;
					// printf("kasus ga kosong yang dipush ke ans: %c\n",i+'a');
				}
				
			}
			

		}
	}

	for(i=0;i<ans.size();i++){
		int angka = ans[i];
		printf("%c",angka+'a');
	}
	printf("\n");
	return 0;
};