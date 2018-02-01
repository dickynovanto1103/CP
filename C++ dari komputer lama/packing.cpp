#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc,a,b,c,i;
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		printf("Case %d: ",i);
		scanf("%d %d %d",&a,&b,&c);
		if(a<=20 && b<=20 && c<=20){printf("good\n");}
		else{printf("bad\n");}
	}
	return 0;
}