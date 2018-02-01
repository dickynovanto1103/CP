#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int r,c,i,j;
	string kata[1001];
	//printf("test:\n");
	scanf("%d %d",&r,&c);
	//printf("r: %d c: %d\n",r,c);
	for(i=0;i<r;i++){cin>>kata[i];}
	int dx[] = {0,1,1,1,0,-1,-1,-1};
	int dy[] = {-1,-1,0,1,1,1,0,-1};
	bool found=true;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			char kar = kata[i][j];
			//printf("kar: %c\n",kar);
			int bil = kar-48;
			//printf("bil: %d\n",bil);
			if(bil>=0 && bil<=9){
				//cek sekitar
				int cntBom = 0, cntTanya = 0;
				//printf("i: %d j: %d\n",i,j);
				for(int k=0;k<8;k++){
					int x = i+dx[k], y = j+dy[k];
					//printf("x: %d y: %d\n",x,y);
					if(x>=0 && x<r && y>=0 && y<c){
						//printf("masuk sini\n");
						if(kata[x][y]=='*'){cntBom++;}
						else if(kata[x][y]=='?'){cntTanya++;}
					}
				}
				if(cntBom>bil){found = false; break;}
				else{
					if(cntBom+cntTanya==bil){//assign dengan bom aja
						for(int k=0;k<8;k++){
							int x = i+dx[k], y = j+dy[k];
							if(x>=0 && x<r && y>=0 && y<c){
								if(kata[x][y]=='?'){kata[x][y]='*';}
							}
						}
					}
				}
			}
		}
		if(!found){break;}
	}
	//assign tanda tanya dengan angka atau bom
	if(found){
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				char kar = kata[i][j];
				bool isPlacedBomb = false;
				if(kar=='?'){
					//printf("cek koordinat %d %d\n",i,j);
					int cntBom = 0;
					/*for(int k=0;k<8;k++){
						int x = i+dx[k], y = j+dy[k];
						if(x>=0 && x<r && y>=0 && y<c){
							if(kata[x][y]=='*'){cntBom++;}
						}
					}
					if(cntBom)
					cntBom=0;*/
					for(int k=0;k<8;k++){
						int x = i+dx[k], y = j+dy[k];
						if(x>=0 && x<r && y>=0 && y<c){
							kar = kata[x][y];
							int bilLain = kar-48;
							if(kata[x][y]=='*'){cntBom++;}
							else if(bilLain>=0 && bilLain<=9){
								//cek disekitar bilangan itu..hitung bomnya
								int counterBom = 0;
								for(int l=0;l<8;l++){
									int xbaru = x+dx[l],ybaru = y+dy[l];
									if(xbaru>=0 && xbaru<r && ybaru>=0 && ybaru<c){
										if(kata[xbaru][ybaru]=='*'){counterBom++;}	
									}
									
								}
								if(counterBom==bilLain){continue;}
								if(counterBom>bilLain){found = false; break;}
								else{
									kata[i][j]='*'; isPlacedBomb = true;
									//printf("koordinat %d %d taruh bomb\n",i,j);
									/*for(int l=0;l<r;l++){
										for(int m=0;m<c;m++){
											printf("%c",kata[l][m]);
										}
										printf("\n");
									}*/
									break;
								}
							}
						}
					}
					if(!found){break;}
					if(!isPlacedBomb){kata[i][j] = cntBom+48;}
				}
			}
		}
		//cek final
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				char kar = kata[i][j];
				int bil = kar-48;
				if(bil>=0 && bil<=9){
					//cek sekitar
					int cntBom = 0, cntTanya = 0;
					for(int k=0;k<8;k++){
						int x = i+dx[k], y = j+dy[k];
						if(x>=0 && x<r && y>=0 && y<c){
							kar = kata[x][y];
							
							if(kata[x][y]=='*'){cntBom++;}
							
						}
					}
					
					if(cntBom>bil){found = false; break;}
					else if(cntBom<bil){found = false; break;}
				}
			}
			if(!found){break;}
		}	
	}
	/*for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%c",kata[i][j]);
		}
		printf("\n");
	}*/
	if(found){printf("VALID\n");}
	else{printf("INVALID\n");}
	return 0;
}