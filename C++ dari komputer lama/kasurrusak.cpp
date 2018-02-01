#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

bool palindrome(string kata, int awal, int akhir){
	if(awal>=akhir){
		return(true);
	}
	else if(kata[awal]==kata[akhir]){
		//printf("ya\n");
		return(palindrome(kata,awal+1,akhir-1));
	}else{
		//printf("nooo\n");
		return(false);
	}
}

int main(){
	string kata;
	
	cin>>kata;
	//cout<<kata.length()<<endl;
	if(palindrome(kata,0,kata.length()-1)){
		printf("YA\n");
	}else{
		printf("BUKAN\n");
	}
	return 0;
}