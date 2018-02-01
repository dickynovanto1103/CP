#include <cstdio>

using namespace std;

int main(){
	int n,i,q,p,k,a[100010];
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%d",&a[i]);}
	scanf("%d",&q);
	
	while(q--){
		int cnt = 0;
		scanf("%d %d",&p,&k);
		while(p<=n){
			p = p+a[p]+k;
			cnt++;	
		}
		
		printf("%d\n",cnt);
		
	}

	return 0;
}