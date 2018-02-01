#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int r,c;
ll a[1000][1000], path[1000][1000];
/*ll solve(int i, int j){
	if(i<r && j < c){
		if(a[i][j]==1000){return path[i][j] = 0;}
		if(i==r-1 && j==c-1){return path[i][j] = 1;}
		if(path[i][j]==0){
			path[i][j] = solve(i+1,j) + solve(i,j+1);
		}
		return path[i][j];
	}else{return 0;}
	
}*/
int main(){
	int tc,i,j,test=0;

	scanf("%d",&tc);

	while(tc--){
		if(test>0){printf("\n");}
		scanf("%d %d",&r,&c);
		
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				a[i][j] = path[i][j] = 0;
			}
		}
		string kata;
		for(i=0;i<r;i++){
			if(!i){getline(cin>>ws,kata);}
			else{getline(cin,kata);}
			//parse kata
			//cout<<"kata: "<<kata<<endl;
			int bil = 0, cnt = 0;
			int acuan;
			for(j=0;j<kata.length();j++){
				
				if(kata[j]==' '){
					//printf("bil: %d\n",bil);
					if(!cnt){acuan = bil; acuan--; bil = 0; cnt++;}
					else{
						bil--;
						a[acuan][bil] = 1000;
						//printf("penghalang: %d %d\n",acuan,bil);
					 	bil = 0;

					}//penghalang
				}else{
					bil*=10; bil = bil + (kata[j]-'0');
					//printf("bil menjadi: %d\n",bil);
				}
			}
			//printf("bil: %d\n",bil);
			if(cnt!=0){
				bil--;
				//printf("bil: %d\n",bil);
				//printf("masuk sini\n");
				//printf("penghalang: %d %d\n",acuan,bil);
				a[acuan][bil] = 1000;
			}
		}
		//dp bottom up
		path[r-1][c-1]=1;
		for(i=r-1;i>=0;i--){
			for(j=c-1;j>=0;j--){
				if(a[i][j]!=1000){
					if(i+1<r && j+1 < c){
						path[i][j] = path[i+1][j] + path[i][j+1];
					}else if(i+1 < r && j+1==c){
						path[i][j]+=path[i+1][j];
					}else if(i+1==r && j+1<c){
						path[i][j]+=path[i][j+1];
					}
				}				
			}
		}


		printf("%lld\n",path[0][0]);
		/*for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(j>0){printf(" ");}
				printf("%lld",path[i][j]);
			}
			printf("\n");
		}*/
		test=1;
	}
	return 0;
}