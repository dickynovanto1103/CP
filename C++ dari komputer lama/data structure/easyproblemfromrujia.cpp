#include <cstdio>
#include <vector>
#include <map>
using namespace std;
typedef vector <int> vi;

vector <vi> AdjList;
int main(){
	int n,m,i,j,a[100000],cnt,k,v;
	map<int,int> mapper;
	map<int,int>::iterator it;
	while(scanf("%d %d",&n,&m)!=EOF){
		cnt=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			it=mapper.find(a[i]);
			if(it==mapper.end()){mapper[a[i]]=cnt++;}
		}
		//for(i=0;i<n;i++){printf("%d mapped to %d\n",a[i],mapper[a[i]]);}
		AdjList.assign(cnt,vi());
		for(i=0;i<n;i++){it=mapper.find(a[i]); AdjList[it->second].push_back(i+1);}
		/*for(i=0;i<cnt;i++){
			printf("node %d:",i);
			for(j=0;j<AdjList[i].size();j++){printf(" %d",AdjList[i][j]);}
			printf("\n");
		}*/
		for(i=0;i<m;i++){
			scanf("%d %d",&k,&v);
			it=mapper.find(v);
			if(k > AdjList[it->second].size()){printf("0\n");}
			else{printf("%d\n",AdjList[it->second][k-1]);}
		}
		mapper.clear(); AdjList.clear();
	}
	return 0;
}