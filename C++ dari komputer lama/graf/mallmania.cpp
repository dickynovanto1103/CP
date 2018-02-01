#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef pair <int,int> ii;

int dist[2004][2004],rowmax,columnmax;
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
void inisialisasi(){
	int i,j;
	for(i=0;i<=rowmax;i++){
		for(j=0;j<=columnmax;j++){
			dist[i][j]=inf;
		}
	}
}
queue <ii> q;

int main(){
	vector <int> x1,y1,x2,y2;	
	int a,b,i,j,k,x_new,y_new,ans,d,e,max2,min2,min3,max3,min1,min4,max1,max4;
	bool found;
	while(scanf("%d",&a),a){
		rowmax=columnmax=-1;
		ans=inf; max1=max4=-1; min1=min4=inf;
		for(i=0;i<a;i++){scanf("%d %d",&d,&e);
			rowmax=max(rowmax,d); columnmax=max(columnmax,e); 
			max1=max(max1,d); max4 = max(max4,e); min1 = min(min1,d); min4 = min(min4,e);
			x1.push_back(d); y1.push_back(e);
		}
		scanf("%d",&b); max2=max3=-1; min2=min3=inf;
		for(i=0;i<b;i++){scanf("%d %d",&d,&e);rowmax=max(rowmax,d); columnmax=max(columnmax,e); 
			max2=max(max2,d); max3 = max(max3,e); min2 = min(min2,d); min3 = min(min3,e);
			x2.push_back(d); y2.push_back(e);
		}
		for(i=0;i<a;i++){
			inisialisasi();
			d = x1[i]; e = y1[i];
			q.push(ii(d,e)); dist[d][e]=0;
			found=false;
			while(!q.empty()){
				ii front = q.front(); q.pop();
				int x = front.first, y= front.second;
				for(j=0;j<=3;j++){
					x_new=x+dr[j]; y_new=y+dc[j];
					if(x_new>=min1 && x_new<=max1 && y_new>=min4 && y_new<=max4){dist[x_new][y_new]=0;}
					if(x_new>=0 && x_new<=rowmax && y_new>=0 && y_new <=columnmax){
						if(dist[x_new][y_new]==inf){
							dist[x_new][y_new]=dist[x][y]+1;
							if(x_new>=min2 && x_new<=max2 && y_new>=min3 && y_new<=max3){found=true; ans=min(ans,dist[x_new][y_new]);break;}
							q.push(ii(x_new,y_new));
						}
					}
				}
				if(found){break;}
			}
			while(!q.empty()){q.pop();}
			//for(j=0;j<b;j++){ans=min(ans,dist[x2[j]][y2[j]]);}
			
		}
		printf("%d\n",ans);
		x1.clear(); x2.clear(); y1.clear(); y2.clear();
	}
	return 0;
}