#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(){
	int n,i,ans,a[1010],bil,cnt;
	while(scanf("%d",&bil),bil){
		i=0;
		a[i++]=bil;
		while(scanf("%d",&bil),bil){a[i++]=bil;}

		cnt=i; sort(a,a+cnt); bil=a[0];
		for(i=0;i<cnt;i++){a[i]-=bil;}
		//for(i=0;i<cnt;i++){printf("ke %d adalah %d\n",i,a[i]);}
		ans=gcd(a[0],a[1]);
		for(i=2;i<cnt;i++){ans=gcd(ans,a[i]);}
		printf("%d\n",ans);
	}
	return 0;
}