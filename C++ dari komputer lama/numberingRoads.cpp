#include <bits/stdc++.h>

using namespace std;

int main(){
	int r,n,ans,i;
	float a,b;
	i=1;
	while(scanf("%d %d",&r,&n),(r||n)){
		a=(float)(r-n);
		b=(float)n;
		ans=ceil(a/b);
		printf("Case %d: ",i);
		if(ans>26){
			printf("impossible\n");
		}else{
			printf("%d\n",ans);
		}
		i++;
	}
	return 0;
}