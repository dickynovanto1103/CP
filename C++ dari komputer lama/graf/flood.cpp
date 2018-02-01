#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
int n,m;
bool found;
string kata[100];
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
/*bool flood(int a, int b){
	int x,y,i;
	kata[a][b]='*';
	if(i=0;i<4;i++){
		x = a+dr[i]; y = b+dc[i];
		if(x>=0 && x<n && y>=0 && y<m){
			if(kata[x][y]=='.'){flood(x,y);}
		}else{found=false;}
	}
}*/

int main(){
	int i,j,k,tc,a,b,test=1;
	queue <ii> q;
	bool curfound;
	scanf("%d",&tc);
	while(tc--){
		curfound=false;
		printf("Case #%d: ",test++);
		scanf("%d %d",&n,&m);
		//printf("n: %d m: %d\n",n,m);
		for(i=0;i<n;i++){cin>>kata[i];}
		//for(i=0;i<n;i++){cout<<kata[i]<<endl;}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(kata[i][j]=='.'){
					curfound=true;
					q.push(ii(i,j));
					while(!q.empty()){
						ii front = q.front(); q.pop();
						a = front.first; b = front.second;
						//printf("a: %d b:%d\n",a,b);
						kata[a][b]='*';
						for(k=0;k<4;k++){
							a = front.first+dr[k]; b=front.second+dc[k];
							
							if(a>=0 && a<n && b>=0 && b<m){
								if(kata[a][b]=='.'){q.push(ii(a,b));}
							}else{curfound=false;}
						}
					}
					/*printf("kata sekarang:\n");
					for(k=0;k<n;k++){cout<<kata[k]<<endl;}*/
				}
				if(curfound){break;}
			}
			if(curfound){break;}
		}
		if(curfound){printf("YA\n");}
		else{printf("TIDAK\n");}
	}
	return 0;
}