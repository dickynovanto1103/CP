#include <bits/stdc++.h>

using namespace std;
#define restricted -1
#define inf 1000000000
typedef pair <int,int> ii;
typedef pair <ii,int> iii;
typedef pair <iii,int> iiii;
int da[]={-1,1,0,0,0,0,0,0};
int db[]={0,0,-1,1,0,0,0,0};
int dc[]={0,0,0,0,-1,1,0,0};
int dd[]={0,0,0,0,0,0,-1,1};

int main(){
	int tc, i,j,k,l,n, a[10][10][10][10], dist[10][10][10][10],b,c,d,e,f,counter,g,h,y,res1,res2,res3,res4;
	queue <iiii> q;
	iiii x;
	bool found;
	scanf("%d",&tc);
	while(tc--){
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				for(k=0;k<10;k++){
					for(l=0;l<10;l++){
						a[i][j][k][l]=0; dist[i][j][k][l]=inf;//inisialisasi
					}
				}
			}
		}
		scanf("%d %d %d %d",&b,&c,&d,&e);//awal
		scanf("%d %d %d %d",&f,&g,&h,&y);//dest
		scanf("%d",&n);//banyak restriction
		for(i=0;i<n;i++){scanf("%d %d %d %d",&res1,&res2,&res3,&res4); a[res1][res2][res3][res4]=restricted;}
		//bfs
		counter=1;
		x = make_pair(make_pair(ii(b,c),d),e);
		found=false;
		q.push(x); dist[b][c][d][e]=0;
		while(!q.empty()){
			//printf("counter: %d\n",counter++);
			iiii front = q.front(); q.pop(); 
			int node1 = front.first.first.first, node2=front.first.first.second, node3=front.first.second, node4=front.second;
			//printf("node1 : %d node2 : %d node3 : %d node4 : %d\n",node1,node2,node3,node4);
			for(i=0;i<8;i++){
				b=node1 + da[i]; c=node2+db[i]; d=node3+dc[i]; e=node4+dd[i];
				//printf("b: %d c: %d d: %d e: %d\n",b,c,d,e);
				if(b==10){b=0;} if(c==10){c=0;}
				if(b==-1){b=9;} if(c==-1){c=9;}

				if(d==10){d=0;} if(e==10){e=0;}
				if(d==-1){d=9;} if(e==-1){e=9;}
				if(a[b][c][d][e]!=restricted && dist[b][c][d][e]==inf){
					iiii temp = make_pair(make_pair(ii(b,c),d),e);
					dist[b][c][d][e] = dist[node1][node2][node3][node4]+1; 
					q.push(temp);}
				if(b==f && c==g && d==h && e==y){found=true;break;}
			}
			if(found){//pengisian q
				while(!q.empty()){q.pop();}
			}
		}
		if(dist[f][g][h][y]==inf){printf("-1\n");}
		else{printf("%d\n",dist[f][g][h][y]);}
	}
	return 0;
}