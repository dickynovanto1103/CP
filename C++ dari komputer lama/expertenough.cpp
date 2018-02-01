#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int i,TC,N,j,count,c;
	string kata[10010],temp;
	int minim[10010],maks[10010];
	bool found;
	scanf("%d",&TC);
	for(i=1;i<=TC;i++){
		if(i>1){
			printf("\n");
		}
		scanf("%d",&N);
		for(j=1;j<=N;j++){
			cin>>kata[j]>>minim[j]>>maks[j];
		}
		int Q,harga;
		scanf("%d",&Q);
		
		while(Q--){
			
			found=true;
			count=0;
			scanf("%d",&harga);
			//searching
			for(j=1;j<=N;j++){
				if(harga>=minim[j] && harga<= maks[j]){
					count++;
					temp=kata[j];
				}
				if(count>1){
					found=false;
					break;
				}
			}
			if(!found){
				printf("UNDETERMINED\n");
			}else{
				if(j>N && count==0){
					printf("UNDETERMINED\n");
				}else{
					cout<<temp<<endl;
				}
				
			}
			c++;
		}
	}
	return 0;
}