#include <bits/stdc++.h>

using namespace std;

int main(){
	int V,E,i,j,k,cnt,a,b,tc=1;
	int dist[60][60];
	string nama1,nama2;
	map <string,int> mapper;
	map <string,int>::iterator it;

	while(scanf("%d %d",&V,&E), (V||E)){
		cnt=0;

		for(i=0;i<V;i++){
			for(j=0;j<=V;j++){
				dist[i][j]=1000000000;
			}
		}
		for(i=0;i<V;i++){dist[i][i]=0;}
		for(i=0;i<E;i++){
			cin>>nama1>>nama2;
			it=mapper.find(nama1);
			if(it==mapper.end()){mapper[nama1]=cnt++;}
			it=mapper.find(nama2);
			if(it==mapper.end()){mapper[nama2]=cnt++;}
			it=mapper.find(nama1); a=it->second;
			it=mapper.find(nama2); b=it->second;
			dist[a][b]=dist[b][a]=1;
		}
		//floyd
		for(k=0;k<V;k++){
			for(i=0;i<V;i++){
				for(j=0;j<V;j++){
					dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		//cari maks
		int ans=0;
		for(i=0;i<V;i++){
			for(j=0;j<V;j++){
				ans=max(ans,dist[i][j]);
			}
		}
		printf("Network %d: ",tc++);
		if(ans==1000000000){printf("DISCONNECTED\n\n");}
		else{printf("%d\n\n",ans);}
		mapper.clear();
	}
	return 0;
}