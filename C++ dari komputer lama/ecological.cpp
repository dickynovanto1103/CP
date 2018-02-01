#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000

int main(){
	int b[4],g[4],c[4];
	int id,i;
	int minim;
	string kata;
	while(scanf("%d %d %d %d %d %d %d %d %d",&b[1],&g[1],&c[1],&b[2],&g[2],&c[2],&b[3],&g[3],&c[3])==9){
		minim=inf;
		minim=min(minim,b[2]+b[3]+c[1]+c[3]+g[1]+g[2]);
		kata="BCG";
		if(b[2]+b[3]+g[1]+g[3]+c[1]+c[2] < minim){minim=b[2]+b[3]+g[1]+g[3]+c[1]+c[2];kata="BGC";}
		if(c[2]+c[3]+b[1]+b[3]+g[1]+g[2] < minim){minim=c[2]+c[3]+b[1]+b[3]+g[1]+g[2];kata="CBG";}
		if(c[2]+c[3]+g[1]+g[3]+b[1]+b[2] < minim){minim=c[2]+c[3]+g[1]+g[3]+b[1]+b[2];kata="CGB";}
		if(g[2]+g[3]+b[1]+b[3]+c[1]+c[2] < minim){minim=g[2]+g[3]+b[1]+b[3]+c[1]+c[2];kata="GBC";}
		if(g[2]+g[3]+c[1]+c[3]+b[1]+b[2] < minim){minim=g[2]+g[3]+c[1]+c[3]+b[1]+b[2];kata="GCB";}
		cout<<kata<<" "<<minim<<endl;
	}
	return 0;
}