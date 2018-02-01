#include <cstdio>

using namespace std;

int main(){
	int n,i,k,f,tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		int total = 0;
		while(k--){
			scanf("%d",&f);
			int bil;
			int temp = 1;
			while(f--){scanf("%d",&bil); temp*=bil; temp%=n;}
			total+=temp; total%=n;
		}
		printf("%d\n",total);
	}
	return 0;
}