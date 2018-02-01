#include <bits/stdc++.h>

using namespace std;

int main(){
	int r,c,temp,i,j,k,cnt,bil,row,column,pjg,pos;
	char karakter;
	bool found;
	string ins, arena[110];
	//printf("%d\n",-1%4);
	/*cin>>karakter;
	bil = karakter;
	printf("%d\n",bil);*/
	while(scanf("%d %d %d",&r,&c,&temp), (r||c||temp)){
		for(i=0;i<r;i++){cin>>arena[i];}
		/*printf("arena awal:\n");
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				printf("%c",arena[i][j]);
			}
			printf("\n");
		}*/
		cin>>ins;
		found=false;
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(arena[i][j]=='N' || arena[i][j]=='S' ||arena[i][j]=='L' ||arena[i][j]=='O'){row=i; column=j; found=true; break;}
			}
			if(found) break;
		}
		//printf("row = %d column: %d\n",row,column);
		karakter = arena[row][column];
		if(karakter == 'N'){pos=0;}
		else if(karakter == 'L'){pos=1;}
		else if(karakter == 'S'){pos=2;}
		else if(karakter == 'O'){pos=3;}
		cnt=0;
		for(i=0;i<temp;i++){
			if(ins[i]=='D'){pos=(pos+1)%4;}
			else if(ins[i]=='E'){
				pos--;
				if(pos<0){pos=3;}
			}
			else{//F
				arena[row][column]='p';
				if(pos==0){
					row--;
					if(row<0 || arena[row][column]=='#'){row++;}
					else{
						if(arena[row][column]=='*'){cnt++; arena[row][column]='p';}
					}
				}else if(pos==1){
					column++;
					if(column==c || arena[row][column]=='#'){column--;}//perhatikan di sini...siapa tau RTE disini
					else{
						if(arena[row][column]=='*'){cnt++; arena[row][column]='p';}
					}
				}else if(pos==2){
					row++;
					if(row==r || arena[row][column]=='#'){row--;}//perhatikan di sini...siapa tau RTE disini
					else{
						if(arena[row][column]=='*'){cnt++; arena[row][column]='p';}
					}
				}else if(pos==3){
					column--;
					if(column<0 || arena[row][column]=='#'){column++;}//perhatikan di sini...siapa tau RTE disini
					else{
						if(arena[row][column]=='*'){cnt++; arena[row][column]='p';}
					}
					
				}
				/*printf("selama proses:\n");
					for(j=0;j<r;j++){
						for(k=0;k<c;k++){
							printf("%c",arena[j][k]);
						}
						printf("\n");
					}*/
				
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}