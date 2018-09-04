#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc;
	int tt;
	int i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		int n,a,b,k;	
		scanf("%d %d %d %d",&n,&a,&b,&k);
		for(i=0;i<k;i++){
			n-=a;
			n+=b;
		}
		printf("Kasus #%d: %d\n",tt,n);
	}
	

	return 0;
};