#include <bits/stdc++.h>

using namespace std;
int cnt;
string kata[35];

int dr[]={-1,-1,0,1,1,1,0,-1};
int dc[]={0,1,1,1,0,-1,-1,-1};

void flood(int x,int y){
	int x_new,y_new,i,j;
	kata[x][y] = '#';
	for(i=0;i<8;i++){
		x_new = x+dr[i]; y_new = y+dc[i];
		if(x_new >=0 && x_new <cnt && y_new>=0 && y_new <kata[x_new].length()){
			if(kata[x_new][y_new]==' '){flood(x_new,y_new);}	
		}
	}
}

int main(){
	int tc,i,j,k,x,y;
	bool found;
	scanf("%d",&tc);
	for(i=0;i<tc;i++){
		//printf("kasus: %d\n",i);
		cnt=0;
		getline(cin>>ws,kata[cnt]);
		while(kata[cnt][0]!='_'){
			cnt++;
			getline(cin,kata[cnt]);
		}
		//mencari bintang
		found=false;
		for(j=0;j<cnt;j++){
			for(k=0;k<kata[j].length();k++){
				if(kata[j][k]=='*'){found=true; break;}
			}
			if(found){break;}
		}
		x = j; y = k;
		//printf("x = %d y = %d\n",x,y);
		flood(x,y);
		for(j=0;j<cnt;j++){cout<<kata[j]<<endl;}
		cout<<kata[cnt]<<endl;

		

	}
	return 0;
}