#include <cstdio>
#include <iostream>
using namespace std;

bool isangka(char karakter){return(karakter-'0' >=0 && karakter-'0'<=9);}

int main(){
	int tc,i,j,bil,ans;
	string kata;
	scanf("%d",&tc);
	for(i=0;i<tc;i++){
		
		if(i==0){getline(cin>>ws,kata);}
		else{getline(cin,kata);}
		bil=0; ans=-1;
		for(j=0;j<kata.length();j++){
			if(isangka(kata[j])){bil=bil*10+(kata[j]-'0');}
			else if(kata[j]=' '){//printf("bil yang dibaca: %d\n",bil );
				ans=max(ans,bil); bil=0; continue;}
		}
		ans=max(ans,bil);//utk yg terakhir
		printf("Case %d: %d\n",i+1,ans);
	}
	return 0;
}