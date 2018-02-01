#include <bits/stdc++.h>

using namespace std;

int coin[]={50,25,10,5,1};
int memo[7][7500];
int result(int type,int n){
	if(n==0){return 1;}
	else if(n < 0 || type==5){return 0;}
	else if(memo[type][n]!=-1){return memo[type][n];}
	else{return memo[type][n]=result(type+1,n)+result(type,n-coin[type]);}

}

int main(){
	int n;
	memset(memo,-1,sizeof memo);
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",result(0,n));
	}
	return 0;
}