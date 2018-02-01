#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc,a,b,c,ans;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&a,&b,&c);
		ans=(a+(a-b))*c/(a+b);
		if(ans<0){ans=0;}
		printf("%d\n",ans);
	}
	return 0;
}