#include <bits/stdc++.h>

using namespace std;
int c,r,cnt;
string kata[55];
int 
vector <int> ans;

int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};

void setangka(int x,int y,int cnt){
	int x_new,y_new,i,j;

}

int main(){
	int i,j;
	while(scanf("%d %d",&c,&r),(c||r)){
		cnt=0;
		for(i=0;i<r;i++){cin>>kata[i];}
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(kata[i][j]=='X' || kata[i][j]=='*'){setangka(i,j,cnt);}
			}
		}
	}

	return 0;
}