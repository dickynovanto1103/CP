#include <bits/stdc++.h>

using namespace std;

int main(){
	string kata;
	int i;
	i=1;
	while(cin>>kata, kata!="#"){
		printf("Case %d: ",i++);
		if(kata=="HELLO"){printf("ENGLISH\n");}
		else if(kata=="HOLA"){printf("SPANISH\n");}
		else if(kata=="HALLO"){printf("GERMAN\n");}
		else if(kata=="BONJOUR"){printf("FRENCH\n");}
		else if(kata=="CIAO"){printf("ITALIAN\n");}
		else if(kata=="ZDRAVSTVUJTE"){printf("RUSSIAN\n");}
		else{printf("UNKNOWN\n");}
	}
	return 0;
}