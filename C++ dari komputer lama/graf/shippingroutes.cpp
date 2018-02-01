#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef vector <int> vi;

vector <vi> AdjList;
vi dist;
int main(){
	int tc,i,m,n,p,j,a,b,cnt,size,k;
	string kata,awal,akhir;
	map <string,int> mapper;
	map <string,int>::iterator it;
	queue <int> q;
	scanf("%d",&tc);
	printf("SHIPPING ROUTES OUTPUT\n\n");
	for(i=1;i<=tc;i++){
		printf("DATA SET  %d\n\n",i);
		scanf("%d %d %d",&m,&n,&p);
		cnt=0;
		AdjList.assign(m,vi());
		for(j=0;j<m;j++){cin>>kata; mapper[kata]=cnt++;}
		for(j=0;j<n;j++){
			cin>>awal>>akhir;
			it=mapper.find(awal); a=it->second;
			it=mapper.find(akhir); b=it->second;
			AdjList[a].push_back(b);
			AdjList[b].push_back(a);
		}
		for(j=0;j<p;j++){
			dist.assign(m,inf);
			scanf("%d",&size); cin>>awal>>akhir;
			it=mapper.find(awal); a=it->second;
			it=mapper.find(akhir); b=it->second;
			q.push(a); dist[a]=0;
			while(!q.empty()){
				int front = q.front(); q.pop();
				for(k=0;k<(int)AdjList[front].size();k++){
					int node = AdjList[front][k];
					if(dist[node]==inf){dist[node]=dist[front]+1; q.push(node);}
				}
			}
			if(dist[b]==inf){printf("NO SHIPMENT POSSIBLE\n");}
			else{printf("$%d\n",dist[b]*100*size);}
		}
		printf("\n");
		mapper.clear();AdjList.clear();
	}
	printf("END OF OUTPUT\n");
	return 0;
}