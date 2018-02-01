#include <cstdio>

using namespace std;

int main(){
	int tc,n,cnt;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		n*=567;//printf("n sekarang: %d\n",n);
		n/=9;//printf("n sekarang: %d\n",n);
		n+=7492;//printf("n sekarang: %d\n",n);
		n*=235;//printf("n sekarang: %d\n",n);
		n/=47;//printf("n sekarang: %d\n",n);
		n-=498;//printf("n sekarang: %d\n",n);
		//proses mendapatkan digit puluhan
		n/=10; n%=10;
		if(n>=0){printf("%d\n",n);}
		else{printf("%d\n",n*-1);}
		
	}

	return 0;
}