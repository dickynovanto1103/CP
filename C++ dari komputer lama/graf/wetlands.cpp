#include <bits/stdc++.h>

using namespace std;

char line[110],grid[110][110];
int R,C;
int dr[]={-1,-1,0,1,1,1,0,-1};
int dc[]={0,1,1,1,0,-1,-1,-1};
int floodfill(int r, int c, char c1, char c2){
	int ans,i;
	if(r<0 || r>=R || c<0 || c>=C){return 0;}
	else{
		if(grid[r][c]!=c1){return 0;}
		else{
			grid[r][c]=c2;//to avoid cycling
			ans=1;
			for(i=0;i<8;i++){
				ans+=floodfill(r+dr[i],c+dc[i],c1,c2);
			}
			return ans;
		}
	}
}

int main(){
	int tc,i,j,row,column;
	scanf("%d",&tc);
	gets(line);
	gets(line);
	while(tc--){
		R=0;
		while(1){
			//getline(cin,grid[R]);//ini ga bs
			gets(grid[R]);
			//scanf("%s",&grid[R]);//nanti efeknya nilai row sama columnya kacau
			if(grid[R][0]!='L' && grid[R][0]!='W'){break;}
			R++;
		}

		C=(int)strlen(grid[0]);
		/*printf("jumlah row: %d, jumlah column: %d\n",R,C);
		for(i=0;i<R;i++){
			for(j=0;j<C;j++){
				printf("%c",grid[i][j]);
			}
			printf("\n");
		}*/
		strcpy(line,grid[R]);
		while(1){
			sscanf(line,"%d %d",&row,&column); row--;column--;
			printf("%d\n",floodfill(row,column,'W','.'));
			floodfill(row,column,'.','W');//restoring for another testcase
			//printf("%d %d\n",row,column );
			//cout<<row<<" "<<column<<endl;

			gets(line);
			if(strcmp(line,"")==0 || feof(stdin)){break;}
		}
		if(tc){printf("\n");}
	}
	return 0;
}