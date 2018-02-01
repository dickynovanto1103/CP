#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef long long ll;
typedef pair<double,double> dd;
typedef pair<int,double> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
vector <vii> AdjList;

vi dist;

int main(){
	char s[30];
	int v,m,i,j,n;
	ll batas;
	queue <int> q;
	double x[1010],y[1010],jarak;
	while(scanf("%d %d",&v,&m),(v||m)){
		batas = m*60; //batas berapa detik boleh diatas
		gets(s);
		i=0;
		//printf("v: %d m: %d\n",v,m);
		while(gets(s)){
			if(strlen(s)==0){break;}
			sscanf(s,"%lf %lf",&x[i],&y[i]);
			//printf("i: %d ",i);
			//printf("x: %.3lf y: %.3lf\n",x[i],y[i]);
			i++;
		}
		n = i;
		dist.assign(n,inf);
		AdjList.assign(n,vii());
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				jarak = hypot(x[i]-x[j], y[i]-y[j]);
				AdjList[i].push_back(ii(j,jarak));
				AdjList[j].push_back(ii(i,jarak));
			}
		}
		//mulai bfs
		dist[0] = 0; q.push(0);
		while(!q.empty()){
			int front = q.front(); q.pop();
			for(i=0;i<AdjList[front].size();i++){
				ii node = AdjList[front][i];
				if(dist[node.first]==inf){
					if(node.second / (double)v <=batas){
						dist[node.first] = dist[front] + 1;
						q.push(node.first);
					}
				}
			}
		}
		if(dist[1]==inf){printf("No.\n");}
		else{
			printf("Yes, visiting %d other holes.\n",dist[1]-1);
		}
		AdjList.clear(); dist.clear();

	}
	return 0;
}