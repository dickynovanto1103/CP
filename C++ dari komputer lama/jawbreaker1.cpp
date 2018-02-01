#include <bits/stdc++.h>

using namespace std;
int n,m;
int a[30][30];
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};
int floodfill(int r,int c,int int1, int int2){
	int i;
	if(r<0 || r>=n || c<0 || c>=m){return 0;}
	else if(a[r][c]!=int1){return 0;}
	else{
		int ans=1;
		a[r][c]=int2;//avoid cycle
		for(i=0;i<4;i++){
			ans+=floodfill(r+dr[i],c+dc[i],int1,int2);
		}
		return ans;
	}
}

int main(){
	int i,j,b,k;
	
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d %d",&b,&k);
	int ans;
	ans=floodfill(b,k,a[b][k],9);
	printf("%d\n",ans*(ans-1));
	return 0;
}