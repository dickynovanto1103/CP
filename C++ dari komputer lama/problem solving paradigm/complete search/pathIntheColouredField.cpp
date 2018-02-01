#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

vector <string> kata;
int main(){
	int n,i,j,k,l;
	int ansdalam,ansluar;
	string temp;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){cin>>temp; kata.push_back(temp);}
		//ansdalam=1000000000; ansluar = -1;

			ansluar=-1;
		for(i=0;i<n;i++){
			//cout<<kata[i]<<endl;
			
			for(j=0;j<n;j++){
				
				if(kata[i][j]=='1'){
					ansdalam = 1000000000;
					for(k=0;k<n;k++){
						for(l=0;l<n;l++){
							if(kata[k][l]=='3'){ansdalam=min(ansdalam,abs(i-k)+abs(j-l));}
						}
					}
					ansluar = max(ansluar,ansdalam);
				}
			}
		}
		printf("%d\n",ansluar);
		kata.clear();
	}
	return 0;
}