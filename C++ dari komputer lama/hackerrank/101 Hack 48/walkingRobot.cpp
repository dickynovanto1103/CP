#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int n,i,j,l,r,q;
	string kata;
	scanf("%d",&q);
	while(q--){
		cin>>kata;
		//proses
		l=0; r=kata.length()-1;
		while(kata[l++]=='l');
		while(kata[r--]=='r');
		int ans = 0;
		for(i=l-1; i<=r+1;i++){
			if(kata[i]!='d'){ans++;}
		}
		printf("%d\n",ans);
	}
	return 0;
}