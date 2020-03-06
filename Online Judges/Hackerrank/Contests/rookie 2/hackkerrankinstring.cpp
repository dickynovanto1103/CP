#include <bits/stdc++.h>

using namespace std;

int main(){
	string kata, kata2 = "hackerrank";
	int n,i,j,cnt;
	bool found;
	scanf("%d",&n);
	while(n--){
		found=true; cnt=0;
		cin>>kata;
		for(i=0;i<kata.length();i++){
			//cari h;
			if(cnt==0){
				if(kata[i]=='h'){cnt++;continue;}
			}else if(cnt==1){
				if(kata[i]=='a'){cnt++;continue;}
			}else if(cnt==2){
				if(kata[i]=='c'){cnt++;continue;}	
			}else if(cnt==3){
				if(kata[i]=='k'){cnt++;continue;}	
			}
			else if(cnt==4){
				if(kata[i]=='e'){cnt++;continue;}	
			}
			else if(cnt==5){
				if(kata[i]=='r'){cnt++;continue;}	
			}
			else if(cnt==6){
				if(kata[i]=='r'){cnt++;continue;}	
			}
			else if(cnt==7){
				if(kata[i]=='a'){cnt++;continue;}	
			}
			else if(cnt==8){
				if(kata[i]=='n'){cnt++;continue;}	
			}
			else if(cnt==9){
				if(kata[i]=='k'){cnt++;continue;}	
			}else{break;}

		}
		if(cnt==10){printf("YES\n");}
		else{printf("NO\n");}
	}
	return 0;
}