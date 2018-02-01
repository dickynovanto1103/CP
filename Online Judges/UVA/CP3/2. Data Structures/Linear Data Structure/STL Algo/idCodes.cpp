#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i;
	string kata;
	char listkar[55];
	while(cin>>kata && kata!="#"){
		for(i=0;i<kata.length();i++){
			listkar[i] = kata[i];
		}
		int cnt=0;
		string ans="";
		do{
			
			if(cnt==1){
				for(i=0;i<kata.length();i++){
					printf("%c",listkar[i]);
					ans+=listkar[i];
				}
				printf("\n");	
			}else if(cnt>1){break;}
			cnt++;
			
		}while(next_permutation(listkar,listkar+kata.length()));
		if(ans==""){printf("No Successor\n");}
	}

	return 0;
}