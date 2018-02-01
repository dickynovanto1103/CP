#include <bits/stdc++.h>

using namespace std;

int main(){
	int dist[105][105];
	int a,b,i,j,k,sum,cnt,tc=1,bil1,bil2;
	map <int,int> mapper;
	map <int,int>::iterator it;
	while(scanf("%d %d",&a,&b),(a||b)){
		cnt=sum=0;
		for(i=1;i<=100;i++){
			for(j=1;j<=100;j++){
				dist[i][j]=1000000000;
			}
		}
		for(i=1;i<=100;i++){dist[i][i]=0;}

		it=mapper.find(a);
		if(it==mapper.end()){mapper[a]=++cnt;}
		it=mapper.find(b);
		if(it==mapper.end()){mapper[b]=++cnt;}
		it=mapper.find(a); bil1=it->second;
		it=mapper.find(b); bil2=it->second;

		dist[bil1][bil2]=1;
		while(scanf("%d %d",&a,&b),(a||b)){
			it=mapper.find(a);
			if(it==mapper.end()){mapper[a]=++cnt;}
			it=mapper.find(b);
			if(it==mapper.end()){mapper[b]=++cnt;}
			it=mapper.find(a); bil1=it->second;
			it=mapper.find(b); bil2=it->second;
			dist[bil1][bil2]=1;
		}
		printf("cnt: %d\n",cnt);
		for(k=1;k<=cnt;k++){
			for(i=1;i<=cnt;i++){
				for(j=1;j<=cnt;j++){
					dist[i][j]=min(dist[i][j],dist[i][k] + dist[k][j]);
				}
			}
		}
		//cari rata"
		
		for(i=1;i<=cnt;i++){
			for(j=1;j<=cnt;j++){
				sum+=dist[i][j];
				//printf("sum dari dist[%d][%d] = %d\n",i,j,sum);
			}
		}
		//printf("sum total = %d\n",sum);
		cnt=cnt*(cnt-1);
		//printf("cnt sekarang: %d\n",cnt);
		double ans = (double)sum / (double)cnt;
		printf("Case %d: average length between pages = %.3lf clicks\n",tc++,ans);
		mapper.clear();
	}

	return 0;
}