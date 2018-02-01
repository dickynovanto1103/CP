#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int a,b,c,i,ans;
	scanf("%d %d %d",&a,&b,&c);
	if(b!=a && b!=c){ans = abs(b-a) + abs(c-b) + 1;}
	else if(b==a && b!=c){ans = abs(b-c)+1;}
	else if(b!=a && b==c) {ans = abs(b-a)+1;}
	else{ans = 1;}
	printf("%d\n",ans);
	return 0;
}