#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef pair<int,int> ii;
typedef vector <int> vi;
typedef pair<int,ii> iii;
typedef vector <iii> vii;


vector <vii> AdjList;
vi dist;
int main(){
	int n,k,i,j,a[110],t[10],bil,pjg,cnt,cntel,elevator[5];
	string kata[10];
	while(scanf("%d %d",&n,&k)!=EOF){
		AdjList.assign(100,vii());//jumlah lantai
		for(i=0;i<n;i++){scanf("%d",&t[i]);}
		cntel=0;
		for(i=0;i<n;i++){
			cnt=0;
			if(i==0){getline(cin>>ws,kata[i]);}
			else{getline(cin,kata[i]);}
			bil=0; pjg = kata[i].length();
			for(j=0;j<pjg;j++){
				char karakter = kata[i][j];
				if(karakter==' '){
					a[cnt]=bil; 
					if(a[cnt]==0){elevator[cntel]=i; cntel++;}//untuk list semua lift yg awalnya di lantai 0
					cnt++;bil=0;continue;
				}
				else{bil=bil*10 + (karakter-'0');}
			}
			a[cnt]=bil; cnt++;//yang terakhir
			printf("isi array:");
			for(j=0;j<cnt;j++){printf(" %d",a[j]);}
			printf("\n");
			for(j=0;j<cnt;j++){
				int weight,node1,node2;
				if(j>0){weight = t[i] * (a[j]-a[j-1]); node1 = a[j]; node2 = a[j-1];
					AdjList[node1].push_back(make_pair(node2,ii(weight,i))); AdjList[node2].push_back(make_pair(node1,ii(weight,i)));
				}
			}			
		}
		for(i=0;i<100;i++){
			printf("node %d:",i);
			for(j=0;j<AdjList[i].size();j++){iii front = AdjList[i][j];printf(" %d %d(%d)",front.first, front.second.first, front.second.second);}
			printf("\n");
		}
		dist.assign(100,inf);dist[0]=0;
		priority_queue <iii, vector <iii>, greater<iii> > pq;
		for(i=0;i<cntel;i++){
			pq.push(make_pair(dist[0],ii(0,elevator[i])));
		}
		
		while(!pq.empty()){
			iii front = pq.top(); pq.pop();
			int d = front.first, u = front.second.first, statawal = front.second.second;
			//printf("d: %d dist[%d] = %d\n",d,u,dist[u]);
			if(d > dist[u]) continue;
			//printf("masuk sini\n");
			for(j=0;j<AdjList[u].size();j++){
				iii v = AdjList[u][j];
				int stat = v.second.second, berat = v.second.first;
				printf("berat: %d\n",berat);
				printf("statawal: %d stat: %d\n",statawal,stat);
				if(stat == statawal){
					if(dist[u]+ berat < dist[v.first]){
						dist[v.first] = dist[u]+berat;
						printf("dist[%d]: %d\n",v.first,dist[v.first]);
						pq.push(make_pair(dist[v.first],ii(v.first,stat)));
					}	
				}else{
					if(dist[u]+ berat+60 < dist[v.first]){
						dist[v.first] = dist[u]+berat+60;
						printf("dist[%d]: %d\n",v.first,dist[v.first]);
						pq.push(make_pair(dist[v.first],ii(v.first,stat)));
					}
				}
				
			}
		}


		if(dist[k]==inf){printf("IMPOSSIBLE\n");}
		else{printf("%d\n",dist[k]);}
		AdjList.clear(); dist.clear();
	}
	
	return 0;
}