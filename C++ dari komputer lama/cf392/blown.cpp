#include <bits/stdc++.h>

using namespace std;

int i,red,blue,yellow,green;

int main(){
	char kata[110];
	
	map <char,int> mapper;
	map <int,char> mapper2;
	map <char,int>::iterator it;
	scanf("%s",kata);
	for(i=0;i<strlen(kata);i++){
		if(kata[i]!='!'){
			it=mapper.find(kata[i]);
			if(it==mapper.end()){
				mapper[kata[i]]=i%4;
				mapper2[i%4]=kata[i];
			}
			
		}
	}
	/*for(it=mapper.begin();it!=mapper.end();++it){
		printf("karakter: %c mapped to %d\n",it->first,it->second);
	}*/
	//iterasi
	for(i=0;i<strlen(kata);i++){
		if(kata[i]=='!'){
			if(mapper2[i%4]=='R'){red++;}
			else if(mapper2[i%4]=='G'){green++;}
			else if(mapper2[i%4]=='B'){blue++;}
			else if(mapper2[i%4]=='Y'){yellow++;}
		}
	}
	printf("%d %d %d %d\n",red,blue,yellow,green);
	return 0;
}
