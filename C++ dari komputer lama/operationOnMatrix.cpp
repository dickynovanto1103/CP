#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	string q,sq;
	int r,c,s,r1,r2,c1,c2,idxBrs,idxKol,maxBrs,maxKol;
	int TC,N,M,Q,i,j,k;
	int temporary;
	int A[23][23],temp[23][23],temp1[23][23];
	scanf("%d",&TC);
	for(i=1;i<=TC;i++){
		scanf("%d %d %d",&N,&M,&Q);
		for(j=1;j<=N;j++){
			for(k=1;k<=M;k++){
				cin>>A[j][k];
			}
		}
		while(Q--){
			cin>>q;
			if(q=="rotate"){
				cin>>sq;
				scanf("%d %d %d",&r,&c,&s);
				maxBrs=s+1;maxKol=s+1;
				if(sq=="cw"){//dimasukkan ke matrix temp dulu...dirotasi ke temp1,lalu kembalikan ke matriks A
					idxBrs=1;idxKol=1;
					for(j=r;j<=r+s;j++){
						for(k=c;k<=c+s;k++){
							temp[idxBrs][idxKol]=A[j][k];
							idxKol++;
						}
						idxKol=1;idxBrs++;
					}
					/*printf("matriks temp:\n");
					for(j=1;j<=maxBrs;j++){
						for(k=1;k<=maxKol;k++){
							cout<<temp[j][k];
							if(k<maxKol){printf(" ");}
						}
						printf("\n");
					}*/
					//rotasi matriks ke temp1
					for(j=1;j<=maxBrs;j++){
						for(k=1;k<=maxKol;k++){
							temp1[j][k]=temp[1+maxBrs-k][j];
						}
					}
					/*printf("matriks temp1:\n");
					for(j=1;j<=maxBrs;j++){
						for(k=1;k<=maxKol;k++){
							cout<<temp1[j][k];
							if(k<maxKol){printf(" ");}
						}
						printf("\n");
					}*/
					//mengembalikan ke A
					idxBrs=1;idxKol=1;
					for(j=r;j<=r+s;j++){
						for(k=c;k<=c+s;k++){
							A[j][k]=temp1[idxBrs][idxKol];
							idxKol++;
						}
						idxKol=1;idxBrs++;
					}
				}else{//ccw
					idxBrs=1;idxKol=1;
					for(j=r;j<=r+s;j++){
						for(k=c;k<=c+s;k++){
							temp[idxBrs][idxKol]=A[j][k];
							idxKol++;
						}
						idxKol=1;idxBrs++;
					}
					//rotasi matriks ke temp1
					for(j=1;j<=maxBrs;j++){
						for(k=1;k<=maxKol;k++){
							temp1[j][k]=temp[k][maxBrs+1-j];
						}
					}
					/*printf("matriks temp1:\n");
					for(j=1;j<=maxBrs;j++){
						for(k=1;k<=maxKol;k++){
							cout<<temp1[j][k];
							if(k<maxKol){printf(" ");}
						}
						printf("\n");
					}*/
					//mengembalikan ke A
					idxBrs=1;idxKol=1;
					for(j=r;j<=r+s;j++){
						for(k=c;k<=c+s;k++){
							A[j][k]=temp1[idxBrs][idxKol];
							idxKol++;
						}
						idxKol=1;idxBrs++;
					}
				}
			}else{//reflect
				
				cin>>sq;
				scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
				maxBrs=r2-r1+1;maxKol=c2-c1+1;
				if(sq=="x"){
					idxBrs=1;idxKol=1;
					for(j=r1;j<=r2;j++){
						for(k=c1;k<=c2;k++){
							temp[idxBrs][idxKol]=A[j][k];
							idxKol++;
						}
						idxBrs++;idxKol=1;
					}
					/*printf("matriks temp:\n");
					for(j=1;j<=maxBrs;j++){
						for(k=1;k<=maxKol;k++){
							cout<<temp[j][k];
							if(k<maxKol){printf(" ");}
						}
						printf("\n");
					}*/
					for(j=1;j<=maxBrs/2;j++){
						for(k=1;k<=maxKol;k++){
							temporary=temp[j][k];
							temp[j][k]=temp[maxBrs-j+1][k];
							temp[maxBrs-j+1][k]=temporary;
						}
					}
					/*printf("matriks temp1:\n");
					for(j=1;j<=maxBrs;j++){
						for(k=1;k<=maxKol;k++){
							cout<<temp[j][k];
							if(k<maxKol){printf(" ");}
						}
						printf("\n");
					}*/
					idxBrs=1;idxKol=1;
					for(j=r1;j<=r2;j++){
						for(k=c1;k<=c2;k++){
							A[j][k]=temp[idxBrs][idxKol];
							idxKol++;
						}
						idxBrs++;idxKol=1;
					}
				}else{//reflect y
					idxBrs=1;idxKol=1;
					for(j=r1;j<=r2;j++){
						for(k=c1;k<=c2;k++){
							temp[idxBrs][idxKol]=A[j][k];
							idxKol++;
						}
						idxBrs++;idxKol=1;
					}
					/*printf("matriks temp:\n");
					for(j=1;j<=maxBrs;j++){
						for(k=1;k<=maxKol;k++){
							cout<<temp[j][k];
							if(k<maxKol){printf(" ");}
						}
						printf("\n");
					}*/
					for(j=1;j<=maxBrs;j++){
						for(k=1;k<=maxKol/2;k++){
							temporary=temp[j][k];
							temp[j][k]=temp[j][maxKol-k+1];
							temp[j][maxKol-k+1]=temporary;
						}
					}
					/*printf("matriks temp1:\n");
					for(j=1;j<=maxBrs;j++){
						for(k=1;k<=maxKol;k++){
							cout<<temp[j][k];
							if(k<maxKol){printf(" ");}
						}
						printf("\n");
					}*/
					idxBrs=1;idxKol=1;
					for(j=r1;j<=r2;j++){
						for(k=c1;k<=c2;k++){
							A[j][k]=temp[idxBrs][idxKol];
							idxKol++;
						}
						idxBrs++;idxKol=1;
					}
				}
			}
		}
		printf("Case #%d:\n",i);
		for(j=1;j<=N;j++){
			for(k=1;k<=M;k++){
				cout<<A[j][k];
				if(k<M){printf(" ");}
			}
			printf("\n");
		}
	}
	return 0;
}