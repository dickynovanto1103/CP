#include <bits/stdc++.h>

using namespace std;

int main(){
	char karakter;
	string kata;
	bool isword;
	int bil,ans,i;
	while(getline(cin,kata)){
		ans=0;
		isword=false;
		for(i=0;i<kata.length();i++){
			bil=kata[i];
			if((bil>=65 && bil <= 90) || (bil >= 97 && bil <= 122)){
				if(!isword){
					ans++;
					isword=true;
				}
			}else{isword=false;}
		}
		printf("%d\n",ans);

	}
	return 0;
}