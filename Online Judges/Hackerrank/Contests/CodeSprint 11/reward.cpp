#include <cstdio>

using namespace std;

int main(){
	int a,b,c;
	int total = 0;
	scanf("%d %d %d",&a,&b,&c);
	a*=10; b*=10; c*=10;
	if(a>100){a=100;}
	if(b>100){b=100;}
	if(c>100){c=100;}
	total = a+b+c;
	printf("%d\n",total);
	return 0;
}