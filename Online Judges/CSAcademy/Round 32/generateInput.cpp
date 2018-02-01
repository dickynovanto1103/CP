#include <cstdio>

using namespace std;

int main(){
	int i,j,a[100010];
	printf("100000\n");
	for(i=1;i<=100000;i++){
		j = 100000-i+1;
		a[i] = i; a[j] = i;
	}
	for (i = 1; i <= 100000; ++i)
	{
		if(i>1){printf(" ");}
		printf("%d",a[i]);
	}
	return 0;
}