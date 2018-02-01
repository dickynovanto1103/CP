#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int n,m,x,y,i,j;
	ll a,b,k,c,cnt[110][110],pembagi,sisa;
	bool putar=false;
	memset(cnt,0,sizeof cnt);
	scanf("%d %d %lld %d %d",&n,&m,&k,&x,&y);
	
	if(k>(((n*2)-1)*m)){
		k-=(((n*2)-1)*m);
		//printf("k sekarang: %lld\n",k);
		a=-1; b=LLONG_MAX; c=0;
		pembagi=k/(((n*2)-2)*m);
		sisa=k%(((n*2)-2)*m);
		//printf("pembagi: %lld sisa: %lld\n",pembagi,sisa);
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){cnt[i][j]++;}
		}
		for(j=1;j<=m;j++){cnt[1][j]++;}
		//printf("pembagi: %lld sisa: %lld\n",pembagi,sisa);
		for(j=1;j<=m;j++){cnt[1][j]+=pembagi; cnt[n][j]+=pembagi;}
		for(i=2;i<=n-1;i++){
			for(j=1;j<=m;j++){cnt[i][j]+=(2*pembagi)+1;}
		}

		while(sisa){

			do{
				if(!putar){
					for(i=2;i<=n && sisa>0;i++){
						for(j=1;j<=m && sisa>0;j++){
							cnt[i][j]++; sisa--;
							//printf("putar false, i: %d j: %d, cnt: %d k: %d\n",i,j,cnt[i][j],k);
						}
					}
					if(sisa>0){putar=true;}
				}else{
					for(i=n-1;i>=1 && sisa>0;i--){
						for(j=1;j<=m && sisa>0;j++){
							cnt[i][j]++; sisa--;
							//printf("putar true, i: %d j: %d, cnt: %d k: %d\n",i,j,cnt[i][j],k);
						}
					}
					if(sisa>0){putar=false;}
				}
			}while(sisa>0);
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				//printf("i: %d j: %d cnt %lld\n",i,j,cnt[i][j]);
				a=max(a,cnt[i][j]);
				b=min(b,cnt[i][j]);
			}
		}
		c=cnt[x][y];
		printf("%lld %lld %lld\n",a,b,c);
	}else{
		//simulasi saja
		do{
			if(!putar){
				for(i=1;i<=n && k>0;i++){
					for(j=1;j<=m && k>0;j++){
						cnt[i][j]++; k--;
						//printf("putar false, i: %d j: %d, cnt: %d k: %d\n",i,j,cnt[i][j],k);
					}
				}
				if(k>0){putar=true;}
			}else{
				for(i=n-1;i>=1 && k>0;i--){
					for(j=1;j<=m && k>0;j++){
						cnt[i][j]++; k--;
						//printf("putar true, i: %d j: %d, cnt: %d k: %d\n",i,j,cnt[i][j],k);
					}
				}
				if(k>0){putar=false;}
			}
		}while(k>0);
		
		//cari minimal maks dan sergei
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				a=max(a,cnt[i][j]);
				b=min(b,cnt[i][j]);
			}
		}
		c=cnt[x][y];
		printf("%lld %lld %lld\n",a,b,c);
	}
	
	return 0;
}
