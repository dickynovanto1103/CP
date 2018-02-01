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

const int maxn = 1e5 + 5;

int color[maxn];
int a[maxn];
int indegree[maxn];
vector<vi> AdjList;
vii listPasangan;

bool cmpMengecil(ii a, ii b){
	return a.second > b.second;
}
bool cmpMembesar(ii a, ii b){
	return a.second < b.second;
}

int main(){
	int n,m,i,j;
	
	scanf("%d %d",&n,&m);
	AdjList.assign(n,vi());
	for(i=0;i<n;i++){
		scanf("%d",&color[i]);
		//color[i] = 1-color[i];
	}
	for(i=0;i<m;i++){
		int bil1, bil2;
		scanf("%d %d",&bil1,&bil2);
		AdjList[bil2].pb(bil1);
		indegree[bil1]++;
	}

	for(i=0;i<n;i++){
		if(indegree[i]==0){
			listPasangan.pb(ii(i,color[i]));
		}
	}
	int cnt = 0;
	vi history;
	vii calonListPasangan;
	while(listPasangan.size()>0){
		if(history.empty()){sort(listPasangan.begin(),listPasangan.end(),cmpMengecil);}
		else{
			if(history[history.size()-1]==1){sort(listPasangan.begin(),listPasangan.end(),cmpMembesar);}
			else{sort(listPasangan.begin(),listPasangan.end(),cmpMengecil);}
		}
		int ukuran = listPasangan.size();
		calonListPasangan.clear();
		for(i=ukuran-1;i>=0;i--){
			int node = listPasangan[i].first, warna = listPasangan[i].second;
			//printf("node: %d warna: %d\n",node,warna);
			if(warna==1){
				if(history.empty()){
					history.pb(1);
					cnt++;
				}else{
					if(history[history.size()-1]==0){cnt++;}
					history.pb(1);
				}
			}else{
				history.pb(0);
			}
			listPasangan.pop_back();
			
			for(j=0;j<AdjList[node].size();j++){
				int v = AdjList[node][j];
				indegree[v]--;
				if(indegree[v]==0){calonListPasangan.pb(ii(v,color[v]));}
			}
			
		}
		for(i=0;i<calonListPasangan.size();i++){
			ii data = calonListPasangan[i];
			listPasangan.pb(data);
		}
	}
	printf("%d\n",cnt);
	return 0;
};