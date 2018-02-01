#include <bits/stdc++.h>

using namespace std;

int main(){
	string kata,one="one";
	int n,cnt;
	scanf("%d",&n);
	while(n--){
		cnt=0;
		cin>>kata;
		if(kata.length()==3){
			for(int i=0;i<3;i++){
				if(kata[i]!=one[i]) cnt++;
			}
			if(cnt<=1){printf("1\n");}
			else{printf("2\n");}
		}else{
			printf("3\n");
		}
	}
	return 0;
}