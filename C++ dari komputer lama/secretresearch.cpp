#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int N,panjang;
	string kata;
	cin>>N;
	while(N--){
		cin>>kata;
		panjang=kata.length();
		if(kata=="1"||kata=="4"||kata=="78"){
			printf("+\n");
		}else if(kata[panjang-2]=='3' && kata[panjang-1]=='5'){
			printf("-\n");
		}else if(kata[0]=='9' && kata[panjang-1]=='4'){
			printf("*\n");
		}else{
			printf("?\n");
		}
	}
	return 0;
}