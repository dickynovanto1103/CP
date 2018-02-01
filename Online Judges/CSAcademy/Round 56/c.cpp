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
int dfs_num[100010];
bool foundCycle = false;

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

vi ans;

void toposort(int u){
	int i;
	dfs_num[u] = visited;
	
	for(i=0;i<AdjList[u].size();i++){
		int v = AdjList[u][i];
	
		if(dfs_num[v]==unvisited){
			toposort(v);
		}
	}
	ans.push_back(u);
}

int main(){
	int n,i,j;
	map<ii,int> mapper;
	map<ii,int>::iterator it;
	map<int,ii> mapper2;
	scanf("%d",&n);

	memset(dfs_num,unvisited,sizeof dfs_num);
	AdjList.assign(n+10,vi());
	int cnt = 0;
	for(i=1;i<=n;i++){
		int banyak;
		scanf("%d",&banyak);
		vector<ii> listPair;
		for(j=0;j<banyak;j++){
			int bil;
			scanf("%d",&bil);
			int a = i, b = bil;
			if(a>b){swap(a,b);}
			
			listPair.pb(ii(a,b));
		}
		//printf("size: %d\n",listPair.size());
		int batas = listPair.size()-1;
		//printf("bata: %d\n",);
		for(j=0;j<batas;j++){
			//printf("j: %d\n",j);
			ii pas1 = listPair[j], pas2 = listPair[j+1];
			int bil11 = pas1.first, bil12 = pas1.second;
			int bil21 = pas2.first, bil22 = pas2.second;
			// printf("bil11: %d bil12: %d bil21: %d bil22: %d\n",bil11,bil12,bil21,bil22);
			bool foundPerlu = false;

			it=mapper.find(ii(bil11,bil12));
			if(it==mapper.end()){
				foundPerlu = true;
				mapper[ii(bil11,bil12)] = cnt;
				// printf("bil: %d %d dimap ke: %d\n",bil11,bil12,cnt);
				mapper2[cnt] = ii(bil11,bil12); cnt++;
			}
			it=mapper.find(ii(bil21,bil22));
			
			if(it==mapper.end()){
				foundPerlu = true;
				mapper[ii(bil21,bil22)] = cnt;
				// printf("bil: %d %d dimap ke: %d\n",bil21,bil22,cnt);
				mapper2[cnt] = ii(bil21,bil22); cnt++;
			}
			
				int a = mapper[ii(bil11,bil12)], b = mapper[ii(bil21,bil22)];
				AdjList[a].pb(b);	
				// printf("yang dipush\n");
				// printf("ini bil11: %d bil12: %d bil21: %d bil22: %d\n",bil11,bil12,bil21,bil22);
				// printf("a: %d b: %d\n",a,b);
			
			
		}
		// if(batas==0){
		// 	int bil11 = listPair[0].first, bil12 = listPair[0].second;
		// 	it=mapper.find(ii(bil11,bil12));
		// 	if(it==mapper.end()){
				
		// 		mapper[ii(bil11,bil12)] = cnt;
		// 		// printf("bil: %d %d dimap ke: %d\n",bil11,bil12,cnt);
		// 		mapper2[cnt] = ii(bil11,bil12); cnt++;
		// 	}

			
		// }
		//printf("keluar\n");
	}
	// printf("AdjList\n");
	// for(i=0;i<cnt;i++){
	// 	printf("node: %d:",i);
	// 	for(j=0;j<AdjList[i].size();j++){
	// 		printf(" %d",AdjList[i][j]);
	// 	}
	// 	printf("\n");
	// }
	//cek ada cycle apa ga..klo ada print -1
	//printf("test\n");
	for(i=1;i<=n;i++){
		if(dfs_num[i]==unvisited){graphCheck(i);}
		if(foundCycle){break;}
	}
	if(foundCycle){printf("-1\n"); return 0;}

	memset(dfs_num,unvisited,sizeof dfs_num);
	for(i=0;i<n;i++){
		if(dfs_num[i]==unvisited){toposort(i);}
	}
	reverse(ans.begin(),ans.end());
	bool isValid = false;
	for(i=0;i<ans.size();i++){
		int bil = ans[i];
		//printf("bil: %d\n",bil);
		ii pas = mapper2[bil];
		if(pas!=ii(0,0)){
			isValid = true;
			printf("%d %d\n",pas.first, pas.second);	
		}
		
	}
	//if(!isValid){printf("-1\n");}
	return 0;
};