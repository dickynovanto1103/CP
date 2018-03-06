#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
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
map<string,int> mapper;
map<int,string> mapper2;

int indegree[20001];
vi listIdx;

void dfs(int i){
	if(AdjList[i].size()==0){return;}
	int v = AdjList[i][0];
	listIdx.pb(v);
	dfs(v);
}

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);

	for(int tt=1;tt<=tc;tt++){
		AdjList.assign(20001,vi());
		memset(indegree,0,sizeof indegree);
		map<string,int>::iterator it;
		scanf("%d",&n);
		int idx = 0;
		for(i=0;i<n;i++){
			string asal, tujuan;
			cin>>asal>>tujuan;
			it = mapper.find(asal);
			if(it==mapper.end()){
				mapper[asal] = idx;
				mapper2[idx] = asal;
				idx++;
			}
			it = mapper.find(tujuan);
			if(it==mapper.end()){
				mapper[tujuan] = idx;
				mapper2[idx] = tujuan;
				idx++;
			}
			int a = mapper[asal],b = mapper[tujuan];
			AdjList[a].pb(b);
			indegree[b]++;
		}
		for(i=0;i<idx;i++){
			if(indegree[i]==0){break;}
		}
		listIdx.pb(i);
		dfs(i);
		printf("Case #%d: ",tt);
		for(i=0;i<listIdx.size()-1;i++){
			if(i){printf(" ");}
			int idx1 = listIdx[i], idx2 = listIdx[i+1];
			cout<<mapper2[idx1]<<"-"<<mapper2[idx2];
		}
		printf("\n");
		AdjList.clear(); mapper.clear(); mapper2.clear(); listIdx.clear();
	}
	return 0;
};