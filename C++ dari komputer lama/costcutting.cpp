#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int tc,i,j;
	int a[5];
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		for(j=0;j<3;j++) scanf("%d",&a[j]);
		sort(a,a+3);
		printf("Case %d: %d\n",i,a[1]);
	}
	return 0;
}