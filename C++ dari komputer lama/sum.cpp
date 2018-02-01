#include <cstdio>

using namespace std;

int main(){
	int n,i,ans=0,j;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&i);ans+=i;
	}
	printf("%d",ans);
	return 0;
}