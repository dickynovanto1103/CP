#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define explored 2
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;


int main() {
	int m,i,j;
	scanf("%d %d",&n,&m);
	AdjList.assign(n+1,vi());
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b); AdjList[a].pb(b); AdjList[b].pb(a);
	}
	int countGanjil = 0;
	for(i=1;i<=n;i++){
		if(AdjList[i].size()%2==1){countGanjil++;}
	}
	if(countGanjil==0){printf("Tipe A\n");}
	else if(countGanjil==2){printf("Tipe B\n");}
	else{printf("Tipe C\n");}
	
	list<int> cyc;
	void EulerTour(list<int>::iterator i, int u){
		for(int j=0;j<AdjList[u].size();j++){
			ii v = AdjList[u][j];
			if(v.second){
				v.second = 0;
				for(int k=0;k<AdjList[v.first].size();k++){
					ii uu = AdjList[v.first][k];
					if(uu.first == u && uu.second){
						uu.second = 0;
						break;
					}
				}
			}
			EulerTour(cyc.insert(i,u),v.first);
		}
	}

	cyc.clear();
	EulerTour(cyc.begin(),A);
	for(list<int>::iterator it = cyc.begin();it!=cyc.begin();it++){
		printf("%d\n",*it);
	}
	return 0;
}