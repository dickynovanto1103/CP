#include <cstdio>
#include <iostream>
using namespace std;

void konversi(int N,string * kata){
	if(N==0){
		*kata='0'+*kata;
	}else if(N==1){
		*kata='1'+*kata;
	}
	else if(N%2==0){
		*kata='0'+*kata;
		konversi(N/2,kata);
	}else{
		*kata='1'+*kata;
		konversi(N/2,kata);
	}
}

int main(){
	int N;
	string kata,kata1;
	scanf("%d",&N);
	konversi(N,&kata);
	cout<<kata<<endl;
	return 0;
}