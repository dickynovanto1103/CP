#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc,a,b;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&a,&b);
		if(a>b){
			printf("%d %d\n",a,a+b);
		}else{printf("%d %d\n",b,a+b);}
	}
	return 0;
}