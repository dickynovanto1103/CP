#include <cstdio>
#include <iostream>

using namespace std;

bool isAllHappy(string kata){
	int i;
	bool found = true;
	for(i=0;i<kata.length();i++){
		if(kata[i]=='-'){found = false; break;}
	}
	return found;
}

int main(){
	int tc,n,k,i,j,test=1, cnt;
	string kata;
	scanf("%d",&tc);
	while(tc--){
		printf("Case #%d: ",test++);
		cin>>kata>>k;
		n = kata.length();
		cnt=0;
		for(i=0;i<n-k+1;i++){
			//printf("i= %d kata[i] = %c\n",i,kata[i]);
			if(kata[i]=='-'){
				for(j=i;j<i+k;j++){
					if(kata[j]=='+'){kata[j]='-';}
					else{kata[j]='+';}
				}
				cnt++;
				//cout<<"kata sekarang: "<<kata<<endl;
			}
		}
		if(isAllHappy(kata)){printf("%d\n",cnt);}
		else{printf("IMPOSSIBLE\n");}
	}
	return 0;
}