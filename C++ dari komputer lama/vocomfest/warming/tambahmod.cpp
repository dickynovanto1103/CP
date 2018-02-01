#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int a,b,c,tc;
	scanf("%d",&tc);
	for(int i=0;i<tc;i++){
		scanf("%d %d %d",&a,&b,&c);
		printf("Case #%d: ",i+1);
		cout<<(a+b)%c<<endl;
	}
	
	return 0;
}