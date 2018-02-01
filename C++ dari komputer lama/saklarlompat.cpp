#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc,i,a,b;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&a,&b);
		for(i=1;i<=a+b;i++){
			int slot = 3*i+1;
			int temp = b;
			int g = min(b,2*i);
			slot -= g;
			b-=g;
			slot -= 2*b+a;
			if(slot >=0){
				printf("%d\n",i);
				break;
			}
			b=temp;
		}
	}
	return 0;
}