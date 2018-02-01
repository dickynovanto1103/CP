#include <bits/stdc++.h>

using namespace std;

int a[1025][1025];

int main(){
	int tc,i,j,b,n,d,x[20010],y[20010],pop[20010],startkolom,startbaris,endkolom,endbaris,ans,ansbaris,anskolom;
	scanf("%d",&tc);
	while(tc--){
		memset(a,0,sizeof a);
		scanf("%d %d",&d,&n);
		for(i=0;i<n;i++){scanf("%d %d %d",&x[i],&y[i],&pop[i]);}
		for(b=0;b<n;b++){
			if(x[b] - d < 0){startbaris = 0;}
			else{startbaris = x[b]-d;}
			if(x[b] + d > 1024){endbaris = 1024;}
			else{endbaris = x[b]+d;}
			if(y[b] - d < 0){startkolom = 0;}
			else{startkolom = y[b]-d;}
			if(y[b] + d > 1024){endkolom = 1024;}
			else{endkolom = y[b]+d;}
			for(i=startbaris;i<=endbaris;i++){
				for(j=startkolom;j<=endkolom;j++){
					a[i][j]+=pop[b];
				}
			}
		}
		//cek maksimal
		ans=-1;
		for(i=0;i<1025;i++){
			for(j=0;j<1025;j++){
				if(ans < a[i][j]){ans=a[i][j]; ansbaris=i; anskolom=j;}
			}
		}
		printf("%d %d %d\n",ansbaris,anskolom,ans);
	}
	return 0;
}