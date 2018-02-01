#include <bits/stdc++.h>

using namespace std;

int main(){
	int sum,tc,i,n,a,b,c;
	scanf("%d",&tc);
	while(tc--){
		sum=0;
		scanf("%d",&n);
		while(n--){
			scanf("%d %d %d",&a,&b,&c);
			sum+=(a*c);
		}
		printf("%d\n",sum);
	}
	return 0;
}